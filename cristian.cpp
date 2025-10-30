#include <iostream>
#include <iomanip>

using namespace std;

class Clock {
public:
    int time; // tiempo en segundos (simulado)
    Clock(int t) { time = t; }

    int getTime() const { return time; }
    void adjust(int offset) { time += offset; }
};

int main() {
    cout << "=== SINCRONIZACIÓN DE RELOJES CON EL MÉTODO DE CRISTIAN ===\n" << endl;

    // Simulación: el servidor y el cliente tienen relojes distintos
    Clock server(100);   // tiempo real del servidor
    Clock client(90);    // reloj del cliente desfasado

    cout << "Tiempo inicial del cliente: " << client.getTime() << " s\n";
    cout << "Tiempo real del servidor:  " << server.getTime() << " s\n\n";

    // Paso 1: el cliente registra el tiempo antes de enviar la solicitud
    int t0 = client.getTime();
    cout << "Cliente envía solicitud en t0 = " << t0 << " s\n";

    // Simulamos retardo de red (ida y vuelta)
    int networkDelay = 4; // segundos totales (ida+vuelta)

    // Paso 2: el servidor recibe la solicitud, responde con su hora actual
    int ts = server.getTime(); // tiempo en el servidor al enviar la respuesta
    cout << "Servidor responde con ts = " << ts << " s\n";

    // Paso 3: el cliente recibe la respuesta después del retardo
    int t1 = t0 + networkDelay;
    cout << "Cliente recibe respuesta en t1 = " << t1 << " s\n";

    // Paso 4: el cliente calcula la hora actual estimada del servidor
    // fórmula: T = ts + (t1 - t0)/2
    int estimatedServerTime = ts + (t1 - t0) / 2;

    cout << "\nHora estimada actual del servidor: " << estimatedServerTime << " s" << endl;

    // Paso 5: el cliente ajusta su reloj
    int offset = estimatedServerTime - t1;
    client.adjust(offset);

    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Desfase aplicado: " << offset << " s" << endl;
    cout << "Nuevo tiempo del cliente: " << client.getTime() << " s" << endl;
    cout << "Tiempo del servidor:       " << server.getTime() << " s" << endl;

    cout << "\nSincronización completada correctamente." << endl;
    return 0;
}
