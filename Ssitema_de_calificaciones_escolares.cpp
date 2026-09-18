#include <iostream>
#include <string>

using namespace std;

int main() {
    // NIVEL 1 - Estructura basica y declaracion de variables

    string nombre;
    int edad;
    float calificacion1, calificacion2, calificacion3;
    float promedio;
    int opcion;

    do {

        cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver informacion del programa" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:

                cout << "\n--- REGISTRAR ESTUDIANTE ---" << endl;

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
    
    // NIVEL 2 - Condicionales if-else y validacion

    if (edad < 0 || edad > 120) {
        cout << "Edad invalida" << endl;
        return 1;
    }

    if (calificacion1 < 0 || calificacion1 > 10 ||
        calificacion2 < 0 || calificacion2 > 10 ||
        calificacion3 < 0 || calificacion3 > 10) {
        cout << "Error: las calificaciones deben estar entre 0 y 10." << endl;
        return 1;
    }

    if (promedio >= 9) {
        cout << "Estado: EXCELENTE" << endl;
    } else if (promedio >= 7) {
        cout << "Estado: APROBADO" << endl;
    } else if (promedio >= 6) {
        cout << "Estado: REGULAR (aprobado con lo minimo)" << endl;
    } else {
        cout << "Estado: REPROBADO" << endl;
    }
    break;

            case 2:

                cout << "\n--- INFORMACION DEL PROGRAMA ---" << endl;
                cout << "Sistema de calificaciones escolares." << endl;
                cout << "Permite registrar estudiantes y sus calificaciones." << endl;
                cout << "Calcula el promedio de las calificaciones." << endl;

                break;

            case 3:

                cout << "\nSaliendo del programa..." << endl;

                break;

            default:

                cout << "\nOpcion no valida." << endl;

                break;
        }

    } while (opcion != 3);
    return 0;
}