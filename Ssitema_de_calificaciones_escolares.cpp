#include <iostream>
#include <string>

using namespace std;

int main() {
    // NIVEL 1 - Estructura basica y declaracion de variables

    string nombre;
    int edad;
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

            case 1: {

                cout << "\n--- REGISTRAR ESTUDIANTE ---" << endl;

    cout << "Nombre del estudiante: ";
    cin >> nombre;

    cout << "Edad: ";
    while (!(cin >> edad) || edad < 0 || edad > 120) {
                    cout << "Error: Edad invalida. Ingrese un entero entre 0 y 120: ";
                    cin.clear();
                }

    int totalCalificaciones;
                float calificacionActual;
                float sumaCalificaciones = 0.0f;
                float calificacionMaxima = -1.0f;
                float calificacionMinima = 11.0f;
                int aprobadas = 0;
                int reprobadas = 0;

    cout << "¿Cuantas calificaciones deseas registrar?: ";
    while (!(cin >> totalCalificaciones) || totalCalificaciones <= 0) {
                    cout << "Error: Debe ingresar un numero entero positivo: ";
                    cin.clear();
                }

    for (int i = 1; i <= totalCalificaciones; i++) {
                    cout << "Calificacion " << i << ": ";
                    while (!(cin >> calificacionActual) || calificacionActual < 0 || calificacionActual > 10) {
                        cout << "Error: La calificacion debe ser un numero entre 0 y 10. Reintente Calificacion " << i << ": ";
                        cin.clear();
                    }

                    sumaCalificaciones += calificacionActual;

                    if (calificacionActual >= 6) {
                        aprobadas++;
                    } else {
                        reprobadas++;
                    }

                    if (calificacionActual > calificacionMaxima) {
                        calificacionMaxima = calificacionActual;
                    }
                    if (calificacionActual < calificacionMinima) {
                        calificacionMinima = calificacionActual;
                    }
                }

                promedio = sumaCalificaciones / totalCalificaciones;

                cout << "\n--- RESUMEN ---" << endl;
                cout << "Nombre: " << nombre << endl;
                cout << "Edad: " << edad << endl;
                cout << "Promedio: " << promedio << endl;
                cout << "Calificacion mas alta: " << calificacionMaxima << endl;
                cout << "Calificacion mas baja: " << calificacionMinima << endl;
                cout << "Calificaciones aprobadas: " << aprobadas << endl;
                cout << "Calificaciones reprobadas: " << reprobadas << endl;


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
}

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