#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int cantidarScan;
    char id[128];
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];
    Employee* auxEmplempleado=NULL;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen("data.csv","r");
        if(pFile==NULL)
        {
            retorno=0;
        }
        else
        {
        	do
            {
                cantidarScan=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n",id,nombre,horasTrabajadas,sueldo);
                if(cantidarScan==4)
                {
                    auxEmplempleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
                    ll_add(pArrayListEmployee,auxEmplempleado);
                }
                else
                {
                    break;
                }
            }while(!feof(pFile));
            retorno=1;
        }
    }
    else
    {
        printf("Error al parsear empleado en modo texto.\n");
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int cantidarScan;
    char id[128];
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];
    Employee* auxEmplempleado=NULL;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen("data.csv","rb");
        if(pFile==NULL)
        {
            retorno=0;
        }
        else
        {
            do
            {
                cantidarScan=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n",id,nombre,horasTrabajadas,sueldo);
                if(cantidarScan==4)
                {
                    auxEmplempleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
                    ll_add(pArrayListEmployee,auxEmplempleado);
                }
                else
                {
                    break;
                }
            }while(!feof(pFile));
            retorno=1;
        }
    }
    else
    {
        printf("Error al parsear empleado en modo binario.\n");
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}
