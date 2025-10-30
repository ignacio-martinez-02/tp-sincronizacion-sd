#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Message {
    int sender;
    int timestamp;
    string content;
};

class Process {
public:
    int id;
    int clock;

    Process(int pid) {
        id = pid;
        clock = 0;
    }

    void localEvent(const string& desc) {
        clock++;
        cout << "Evento local en P" << id << " (" << desc 
             << ") -> Reloj = " << clock << endl;
    }

    Message sendMessage(const string& msg) {
        clock++;
        cout << "P" << id << " envia mensaje: '" << msg 
             << "' -> Reloj = " << clock << endl;
        return {id, clock, msg};
    }

    void receiveMessage(const Message& m) {
        clock = max(clock, m.timestamp) + 1;
        cout << "P" << id << " recibe mensaje de P" << m.sender 
             << " ('" << m.content << "') -> Reloj = " << clock << endl;
    }
};

int main() {
    cout << "=== SINCRONIZACIÓN DE PROCESOS CON RELOJES LÓGICOS DE LAMPORT ===\n" << endl;

    Process P1(1), P2(2), P3(3), P4(4);

    // Secuencia: P1 -> P2 -> P3 -> P4
    P1.localEvent("inicio");
    Message m1 = P1.sendMessage("listo P2");
    P2.receiveMessage(m1);

    P2.localEvent("procesando");
    Message m2 = P2.sendMessage("listo P3");
    P3.receiveMessage(m2);

    P3.localEvent("tarea completada");
    Message m3 = P3.sendMessage("listo P4");
    P4.receiveMessage(m3);

    P4.localEvent("finaliza");

    cout << "\n=== ESTADO FINAL DE LOS RELOJES LÓGICOS ===\n" << endl;
    cout << left << setw(10) << "Proceso" << setw(10) << "Reloj final" << endl;
    cout << "---------------------" << endl;
    cout << "P1" << setw(8) << " " << P1.clock << endl;
    cout << "P2" << setw(8) << " " << P2.clock << endl;
    cout << "P3" << setw(8) << " " << P3.clock << endl;
    cout << "P4" << setw(8) << " " << P4.clock << endl;

    cout << "\nSimulación finalizada correctamente." << endl;

    return 0;
}
