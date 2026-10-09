#include <iostream>
#include <string>
#include <limits>

using namespace std;

    string nombre;
    int edad;
    float promedio;
    string opcionStr;
    string basural;
    int opcion;

    void mostrarMenu() {

        cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver informacion del programa" << endl;
        cout << "3. Salir" << endl;
    }
        
    int leerEntero(string mensaje, int min, int max) {

    int valor;

    while (true) {

        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error: Ingrese un numero entero." << endl;
        }
        else if (valor < min || valor > max) {

            cout << "Error: El valor debe estar entre "
                 << min << " y " << max << "." << endl;
        }
        else {

            return valor;
        }
    }
}
    float leerCalificacion(int numero) {
        float calificacion;
        string basural;
        while (true) {
            cout << "Calificacion " << numero << ": ";
            if (!(cin >> calificacion)) {
                cin.clear();
                cin >> basural;
                cout << "Error: Debe ingresar un numero valido." << endl;
            } else if (calificacion < 0.0f || calificacion > 10.0f) {
                cout << "Error: La calificacion debe estar entre 0 y 10. Reintente." << endl;
            } else {
                return calificacion;
            }
        }
    }

    float calcularPromedio(float suma, int total) {
        return suma / total;
    }

    string obtenerEstado(float promedio) {
        if (promedio >= 9) {
            return "EXCELENTE";
        } else if (promedio >= 7) {
            return "APROBADO";
        } else if (promedio >= 6) {
            return "REGULAR (aprobado con lo minimo)";
        } else {
            return "REPROBADO";
        }
    }

    void registrarEstudiante() {
        string nombre;
        int edad;
        float totalCalificaciones;

        float sumaCalificaciones = 0.0f;
        float calificacionMaxima = 0.0f;
        float calificacionMinima = 10.0f;
        float calificacionActual = 0.0f;
        int aprobadas = 0;
        int reprobadas = 0;

    cout << "\n--- REGISTRO DE ESTUDIANTE ---" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool nombreValido = false;
    while (!nombreValido) {
        cout << "Nombre del estudiante: ";
        getline(cin, nombre);

        if (nombre.empty()) continue;

        nombreValido = true;
        for (char c : nombre) {
            if (c >= '0' && c <= '9') {
                nombreValido = false;
                
                break;
            }
        }
    if (!nombreValido) {
        cout << "Error: El nombre no puede contener numeros. Reintente: ";
    }
    }

    edad = leerEntero("Edad del estudiante: ", 0, 120);
    totalCalificaciones = leerEntero("Cantidad de calificaciones: ", 1, 100);

for (int i = 1; i <= totalCalificaciones; i++) {
    calificacionActual = leerCalificacion(i);
    sumaCalificaciones += calificacionActual;

    if (calificacionActual > calificacionMaxima) {
    calificacionMaxima = calificacionActual;
}

if (calificacionActual < calificacionMinima) {
    calificacionMinima = calificacionActual;
}

    if (calificacionActual >=6) {
        aprobadas++;
    } else {
        reprobadas++;
    }
}

float promedio;
    promedio = calcularPromedio(sumaCalificaciones, totalCalificaciones);

    cout << "\n--- RESULTADOS DEL ESTUDIANTE ---" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Calificacion mas alta: "
    << calificacionMaxima << endl;
    cout << "Calificacion mas baja: "
    << calificacionMinima << endl;
    cout << "Cantidad de calificaciones aprobadas: "
    << aprobadas << endl;
    cout << "Cantidad de calificaciones reprobadas: "
    << reprobadas << endl;
    cout << "Estado del estudiante: "
    << obtenerEstado(promedio) << endl;
    }

    
int main() {

    int opcion;

    do {

        mostrarMenu();

        opcion = leerEntero("Opcion (1-3): ", 1, 3);

        switch (opcion) {

            case 1:
                registrarEstudiante();
                break;

            case 2:
                cout << "\n--- INFORMACION DEL PROGRAMA ---"
                     << endl;

                cout << "Sistema de calificaciones escolares."
                     << endl;

                cout << "Permite registrar estudiantes y sus "
                     << "calificaciones." << endl;

                cout << "Calcula el promedio de las "
                     << "calificaciones." << endl;

                break;

            case 3:
                cout << "\nSaliendo del programa..."
                     << endl;

                break;
        }

    } while (opcion != 3);

    return 0;
}