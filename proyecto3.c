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
