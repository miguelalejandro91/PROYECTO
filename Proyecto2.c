#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct cuenta {
    int numero_cuenta;
    char nombre[100];
    float saldo;
};

void agregar_datos(struct cuenta c) {
    FILE *archivo;
    archivo = fopen("datos.csv", "a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(archivo, "%d,%s,%.2f,%02d/%02d/%d %02d:%02d:%02d\n",
            c.numero_cuenta, c.nombre, c.saldo,
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(archivo);
}

int main() {
    struct cuenta c;
    printf("Ingrese el número de cuenta: ");
    scanf("%d", &c.numero_cuenta);
    printf("Ingrese el nombre: ");
    scanf("%s", c.nombre);
    printf("Ingrese el saldo: ");
    scanf("%f", &c.saldo);
    agregar_datos(c);
    return 0;
}