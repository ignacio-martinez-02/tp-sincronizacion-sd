#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

class Computer {
public:
    int id;
    int clock; // reloj en segundos (simulado)

    Computer(int pid, int initTime) {
        id = pid;
        clock = initTime;
    }

    int getTime() const {
        return clock;
    }

    void adjustClock(int adjustment) {
        clock += adjustment;
    }

    void showTime() const {
        cout << "Computadora " << id << " -> reloj: " << clock << " s" << endl;
    }
};

int main() {
    cout << "=== SINCRONIZACIÓN DE RELOJES CON EL ALGORITMO DE BERKELEY ===\n" << endl;

    // Creamos las computadoras con sus relojes iniciales
    Computer master(1, 100);  // El maestro tiene reloj en 100s
    Computer c2(2, 110);
    Computer c3(3, 95);
    Computer c4(4, 102);

    vector<Computer> slaves = {c2, c3, c4};

    cout << "Tiempos iniciales:\n";
    master.showTime();
    for (auto& c : slaves) c.showTime();
    cout << endl;

    // Paso 1: el maestro solicita los tiempos de los esclavos
    vector<int> differences;
    cout << "Paso 1: El maestro solicita los tiempos actuales de cada computadora.\n";
    for (auto& c : slaves) {
        int diff = c.getTime() - master.getTime();
        differences.push_back(diff);
        cout << "Diferencia con C" << c.id << ": " << diff << " s" << endl;
    }

    // Paso 2: el maestro calcula el ajuste promedio
    int sum = accumulate(differences.begin(), differences.end(), 0);
    int avg = sum / (differences.size() + 1); // +1 porque el maestro también se ajusta

    cout << "\nAjuste promedio calculado: " << avg << " segundos.\n";

    // Paso 3: el maestro y los esclavos ajustan sus relojes
    master.adjustClock(avg);
    for (auto& c : slaves) {
        int diff = c.getTime() - master.getTime();
        c.adjustClock(-diff); // sincroniza con el nuevo tiempo del maestro
    }

    cout << "\nTiempos finales sincronizados:\n";
    master.showTime();
    for (auto& c : slaves) c.showTime();

    cout << "\nSincronización completada correctamente." << endl;
    return 0;
}
