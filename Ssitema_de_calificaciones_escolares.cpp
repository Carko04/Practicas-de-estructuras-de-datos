#include <iostream>
#include <string>

using namespace std;

int main() {

    string nombre;
    int edad;
    float promedio;
    string opcionStr;
    string basural;
    int opcion;

    do {

        cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver informacion del programa" << endl;
        cout << "3. Salir" << endl;
        
    do {
            cout << "Opcion (1-3): ";
            cin >> opcionStr;

            if (opcionStr == "1") opcion = 1;
            else if (opcionStr == "2") opcion = 2;
            else if (opcionStr == "3") opcion = 3;
            else {
                cout << "Error: Opcion invalida. Intente de nuevo." << endl;
                opcion = 0;
            }
        } while (opcion == 0);

        switch (opcion) {

            case 1: {

                cout << "\n--- REGISTRAR ESTUDIANTE ---" << endl;

    bool nombreValido = false;
                cout << "Nombre del estudiante: ";
                while (!nombreValido) {
                    cin >> nombre;
                    nombreValido = true;

                    // Verifica que no tenga dígitos ('0' al '9')
                    for (char c : nombre) {
                        if (c >= '0' && c <= '9') {
                            nombreValido = false;
                            break;
                        }
                    }

                    if (!nombreValido) {
                        cout << "Error: El nombre no puede contener numeros. Reintente Nombre: ";
                    }
                }

    cout << "Edad: ";
                while (true) {
                    if (!(cin >> edad)) {
                        cin.clear();
                        cin >> basural; // Solo lee basural si se ingresaron letras
                        cout << "Error: Ingrese un numero valido. Reintente Edad: ";
                    } else if (edad < 0 || edad > 120) {
                        cout << "Error: La edad debe estar entre 0 y 120. Reintente Edad: ";
                    } else {
                        break; // Dato correcto
                    }
                }

    int totalCalificaciones;
                float calificacionActual;
                float sumaCalificaciones = 0.0f;
                float calificacionMaxima = 0.0f;
                float calificacionMinima = 10.0f;
                int aprobadas = 0;
                int reprobadas = 0;

    cout << "¿Cuantas calificaciones deseas registrar?: ";
                while (true) {
                    if (!(cin >> totalCalificaciones)) {
                        cin.clear();
                        cin >> basural; // Limpia letras o texto atascado
                        cout << "Error: Debe ingresar un numero entero. Reintente: ";
                    } else if (totalCalificaciones <= 0) {
                        // Para números negativos o cero, responde de inmediato sin pedir entrada extra
                        cout << "Error: La cantidad debe ser un numero mayor a 0. Reintente: ";
                    } else {
                        break; // Cantidad válida
                    }
                }

                for (int i = 1; i <= totalCalificaciones; i++) {
                    cout << "Calificacion " << i << ": ";

                    // 4. VALIDACIÓN DE CADA CALIFICACIÓN
                    while (true) {
                        if (!(cin >> calificacionActual)) {
                            cin.clear();
                            cin >> basural; // Limpia letras o texto atascado
                            cout << "Error: Ingrese un numero valido. Reintente Calificacion " << i << ": ";
                        } else if (calificacionActual < 0.0f || calificacionActual > 10.0f) {
                            cout << "Error: La calificacion debe estar entre 0 y 10. Reintente Calificacion " << i << ": ";
                        } else {
                            break; // Calificación válida
                        }
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