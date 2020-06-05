#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getBibliotecas.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int menu(void)
{
    int opcion=0;//Cero es error.

    if(utn_getNumero(&opcion,"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    						 "2. Cargar los datos de los empleados desde el archivo (modo binario).\n"
    						 "3. Alta de empleado\n"
    						 "4. Modificar datos de empleado\n"
    						 "5. Baja de empleado\n"
    						 "6. Listar empleados\n"
    						 "7. Ordenar empleados\n"
    						 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    						 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    						 "10. Salir\n"
    						 "Elija una opcion:"
    						,"\n--- ERROR ---\n",1,10,3) == 0)
    {
    	return opcion;
    }

    return opcion;
}
