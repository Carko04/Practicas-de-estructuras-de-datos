#include <iostream>

using namespace std;


int PIN_CORRECTO = 1234;
int MAX_INTENTOS = 3;
double SALDO_INICIAL = 5000.00;
double MAX_DEPOSITO = 10000.00;
double COMISION_RETIRO_MENOR = 15.00; 
double LIMITE_COMISION = 1000.00;


bool autenticarUsuario();
void mostrarMenu();
void consultarSaldo(double saldo);
void depositar(double &saldo);
void retirar(double &saldo);
void menuRetirosRapidos(double &saldo);
void limpiarEntrada();

int main() {
    
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    if (!autenticarUsuario()) {
        return 0; 
    }

    double saldo = SALDO_INICIAL;
    int opcion;

    do {
        mostrarMenu();
        if (!(cin >> opcion)) {
            cout << "\n[Error] Debe ingresar un numero de opcion valido.\n";
            limpiarEntrada();
            opcion = 0; 
            continue;
        }

        switch (opcion) {
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                depositar(saldo);
                break;
            case 3:
                retirar(saldo);
                break;
            case 4:
                menuRetirosRapidos(saldo);
                break;
            case 5:
                cout << "\nGracias por utilizar el cajero automatico. ¡Hasta luego!\n";
                break;
            default:
                cout << "\n[Error] Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}

void limpiarEntrada() {
    cin.clear(); 
    cin.ignore(10000, '\n'); 
}


bool autenticarUsuario() {
    int pinIngresado;
    int intentos = 0;

    while (intentos < MAX_INTENTOS) {
        cout << "Ingrese su PIN: ";
        if (!(cin >> pinIngresado)) {
            cout << "[Error] Entrada invalida. Por favor, ingrese solo numeros.\n\n";
            limpiarEntrada();
            continue; 
        }

        if (pinIngresado == PIN_CORRECTO) {
            cout << "\n¡PIN correcto! Bienvenido al sistema.\n";
            return true;
        } else {
            intentos++;
            int restantes = MAX_INTENTOS - intentos;
            if (restantes > 0) {
                cout << "[Error] PIN incorrecto. Intentos restantes: " << restantes << "\n\n";
            } else {
                cout << "\n[Error] Ha superado el numero maximo de intentos. Su tarjeta ha sido bloqueada.\n";
            }
        }
    }
    return false;
}


void mostrarMenu() {
    cout << "\n====================================\n";
    cout << "          CAJERO AUTOMATICO         \n";
    cout << "====================================\n";
    cout << "1. Consultar saldo\n";
    cout << "2. Depositar\n";
    cout << "3. Retirar\n";
    cout << "4. Tabla de retiros rapidos\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
}


void consultarSaldo(double saldo) {
    cout << "\n------------------------------------\n";
    cout << "Su saldo actual es: $" << saldo << "\n";
    cout << "------------------------------------\n";
}


void depositar(double &saldo) {
    double monto;
    cout << "\nIngrese el monto a depositar: $";
    if (!(cin >> monto)) {
        cout << "[Error] Entrada invalida. Debe ingresar una cantidad numerica.\n";
        limpiarEntrada();
        return;
    }

    if (monto <= 0) {
        cout << "[Error] El monto a depositar debe ser mayor a $0.00.\n";
    } else if (monto > MAX_DEPOSITO) {
        cout << "[Error] El deposito no puede exceder los $" << MAX_DEPOSITO << ".\n";
    } else {
        saldo += monto;
        cout << "¡Deposito exitoso! Su nuevo saldo es: $" << saldo << "\n";
    }
}


void retirar(double &saldo) {
    int monto;
    cout << "\nIngrese el monto a retirar (multiplos de $100): $";
    if (!(cin >> monto)) {
        cout << "[Error] Entrada invalida. Debe ingresar un numero entero.\n";
        limpiarEntrada();
        return;
    }

    if (monto <= 0) {
        cout << "[Error] El monto debe ser mayor a $0.00.\n";
        return;
    }

    if (monto % 100 != 0) {
        cout << "[Error] El monto a retirar debe ser multiplo de $100.\n";
        return;
    }

    double comision = (monto < LIMITE_COMISION) ? COMISION_RETIRO_MENOR : 0.0;
    double totalAEnviar = monto + comision;

    if (totalAEnviar > saldo) {
        cout << "[Error] Saldo insuficiente. ";
        if (comision > 0) {
            cout << "Recuerde que para montos menores a $" << LIMITE_COMISION 
                 << " se aplica una comision de $" << comision << ".\n";
        } else {
            cout << "\n";
        }
    } else {
        saldo -= totalAEnviar;
        cout << "¡Retiro exitoso! Retiro: $" << (double)monto;
        if (comision > 0) {
            cout << " (Comision cobrada: $" << comision << ")";
        }
        cout << "\nSu nuevo saldo es: $" << saldo << "\n";
    }
}


void menuRetirosRapidos(double &saldo) {
    int opcionRapida;

    cout << "\n=======================================================\n";
    cout << "               TABLA DE RETIROS RAPIDOS                \n";
    cout << "=======================================================\n";
    cout << "Op.  Monto\tComision\tTotal\t\tEstado\n";
    cout << "-------------------------------------------------------\n";

    int index = 1;
    for (int monto = 500; monto <= 3000; monto += 500) {
        double comision = (monto < LIMITE_COMISION) ? COMISION_RETIRO_MENOR : 0.0;
        double totalRequerido = monto + comision;

        cout << " " << index << ")  $" << (double)monto << "\t$" << comision << "\t\t$" << totalRequerido << "\t";

        if (saldo >= totalRequerido) {
            cout << "Disponible\n";
        } else {
            cout << "No disponible\n";
        }
        index++;
    }
    cout << " 7)  Cancelar / Volver al menu principal\n";
    cout << "-------------------------------------------------------\n";
    cout << "Seleccione una opcion para retirar (1-6) o 7 para salir: ";

    if (!(cin >> opcionRapida)) {
        cout << "[Error] Entrada invalida. Debe ingresar un numero.\n";
        limpiarEntrada();
        return;
    }

    if (opcionRapida >= 1 && opcionRapida <= 6) {
        int montoSeleccionado = opcionRapida * 500;
        double comision = (montoSeleccionado < LIMITE_COMISION) ? COMISION_RETIRO_MENOR : 0.0;
        double totalRequerido = montoSeleccionado + comision;

        if (saldo >= totalRequerido) {
            saldo -= totalRequerido;
            cout << "\n¡Retiro rapido exitoso! Se retiraron $" << (double)montoSeleccionado;
            if (comision > 0) {
                cout << " (Comision cobrada: $" << comision << ")";
            }
            cout << "\nSu nuevo saldo es: $" << saldo << "\n";
        } else {
            cout << "\n[Error] Saldo insuficiente para realizar el retiro rapido de $" << (double)montoSeleccionado << ".\n";
        }
    } else if (opcionRapida == 7) {
        cout << "\nOperacion cancelada. Regresando al menu principal...\n";
    } else {
        cout << "\n[Error] Opcion invalida. Regresando al menu principal...\n";
    }
}