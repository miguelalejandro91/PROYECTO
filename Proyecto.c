/*crea una aplicacion que permita el manejo de datos de una cuenta bancaria. realizar depositos, retiros y consulta
de saldos, con estos argumentos. construye un programa en donde los estudiantes deben crear un proyecto de programacion utilizando lenguaje C. 
Una caracteristica importante de la aplicacion es que siempre debe encontrarse en ejecucion, debe permitir el
ingreso de datos por parte del usuario, de acuerdo con el tema asignado y realizar operaciones de lectura, 
actualizacion, borrado, busqueda de datos. ademas la aplicacion debe guardar cada uno de los datos en un archivo 
plano de tipo .CSV (valores separados por comas). cada registro guardado en el archivo plano debe incluir tambien 
los datos de fecha y hora de creacion del registro*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXimo 100

// Estructura para almacenar los datos de una cuenta bancaria
typedef struct {
    int numeroCuenta;
    float saldo;
} CuentaBancaria;

// Función para guardar los registros en un archivo CSV
void guardarRegistro(CuentaBancaria cuenta) {
    FILE* archivo;
    archivo = fopen("registros.csv", "a"); // Abrir archivo en modo "append"

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    // Obtener la fecha y hora actual
    time_t tiempo;
    struct tm* fecha;
    char fechaHora[MAXimo];

    tiempo = time(NULL);
    fecha = localtime(&tiempo);
    strftime(fechaHora, MAXimo, "%Y-%m-%d %H:%M:%S", fecha);

    // Guardar los datos en el archivo CSV
    fprintf(archivo, "%d,%.2f,%s\n", cuenta.numeroCuenta, cuenta.saldo, fechaHora);

    fclose(archivo);
}

// Función para realizar un depósito en una cuenta
void realizarDeposito(CuentaBancaria* cuenta, float monto) {
    cuenta->saldo += monto;
    guardarRegistro(*cuenta);
    printf("Depósito realizado con éxito.\n");
}

// Función para realizar un retiro de una cuenta
void realizarRetiro(CuentaBancaria* cuenta, float monto) {
    if (monto > cuenta->saldo) {
        printf("Saldo insuficiente.\n");
        return;
    }

    cuenta->saldo -= monto;
    guardarRegistro(*cuenta);
    printf("Retiro realizado con éxito.\n");
}

// Función para consultar el saldo de una cuenta
void consultarSaldo(CuentaBancaria cuenta) {
    printf("Saldo actual: %.2f\n", cuenta.saldo);
}

int main() {
    CuentaBancaria cuenta;
    cuenta.numeroCuenta = 12345;
    cuenta.saldo = 1000.0;

    int opcion;
    float monto;

    while (1) {
        printf("\n");
        printf("1. Realizar deposito\n");
        printf("2. Realizar retiro\n");
        printf("3. Consultar saldo\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el monto a depositar: ");
                scanf("%f", &monto);
                realizarDeposito(&cuenta, monto);
                break;
            case 2:
                printf("Ingrese el monto a retirar: ");
                scanf("%f", &monto);
                realizarRetiro(&cuenta, monto);
                break;
            case 3:
                consultarSaldo(cuenta);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                exit(0);
            default:
                printf("Opción invalida.\n");
                break;
        }
    }

    return 0;
}


