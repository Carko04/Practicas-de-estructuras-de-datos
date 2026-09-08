#include <iostream>
#include <string>

using namespace std;

int main() {
    // NIVEL 1 - Estructura basica y declaracion de variables

    string nombre;
    int edad;
    float calificacion1, calificacion2, calificacion3;
    float promedio;

    cout << "Nombre del estudiante: ";
    cin >> nombre;

    cout << "Edad: ";
    cin >> edad;

    cout << "Calificacion 1: ";
    cin >> calificacion1;

    cout << "Calificacion 2: ";
    cin >> calificacion2;

    cout << "Calificacion 3: ";
    cin >> calificacion3;

    // Calculo del promedio
    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

    cout << "\n--- RESUMEN ---" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Calificacion 1: " << calificacion1 << endl;
    cout << "Calificacion 2: " << calificacion2 << endl;
    cout << "Calificacion 3: " << calificacion3 << endl;
    cout << "Promedio: " << promedio << endl;
    return 0;
}