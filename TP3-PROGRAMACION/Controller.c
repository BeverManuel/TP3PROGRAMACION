#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "getBibliotecas.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int rta;
    FILE* archivo;
    if(path!=NULL && pArrayListEmployee!=NULL && archivo!=NULL)
    {
        rta=parser_EmployeeFromText(archivo,pArrayListEmployee);
        if(rta==1)
        {
             retorno=1;
        }
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* archivo;
    if(path!=NULL && archivo!=NULL && pArrayListEmployee!=NULL)
    {
        if(parser_EmployeeFromBinary(archivo,pArrayListEmployee)==1)
        {
            retorno=1;
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int indice;
    Employee* auxEmplempleado = employee_new();
    if(auxEmplempleado!=NULL)
    {
    	indice = controller_idmaximo(pArrayListEmployee);
    	printf("\n\nINDICE %d\n\n",indice);
        if(empleado_alta(auxEmplempleado,indice)==1)
        {
            ll_add(pArrayListEmployee,auxEmplempleado);
            printf("\nNuevo Empleado agregado a la lista.\n");

        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int indice_id;
    int indice_id2=0;
    int pregunta;
    Employee* empleadoModificar=NULL;
    empleadoModificar=employee_new();
    if(pArrayListEmployee!=NULL && empleadoModificar!=NULL)
    {
    	controller_ListEmployee(pArrayListEmployee);

    	utn_getNumero(&indice_id,"\nIngrese el id a modificar: ","\nERROR - CARGA INCORRECTO\n",0,100000,3);
        indice_id2 = indice_id-1;

        empleadoModificar=(Employee*)ll_get(pArrayListEmployee,indice_id2);

        if(empleadoModificar==NULL)
        {
            printf("\nEl empleado no existe.\n");
            return 0;
        }
        else
        {
        	printf("\n\nSelecionado:\n");
            empleado_listarUNEmpleado(empleadoModificar);
            if(utn_getNumero(&pregunta,"\nPara moficionar presione:\n"
            						   "1. SI\n"
            						   "2. NO - CANCELAR Y VOLVER\n"
            					   	   "ELIJA: ","\nERROR - CARGA INCORRECTO\n",1,2,3)==0)
            {
            	switch (pregunta)
            	{
            	case 1:
            		 if(empleado_modificar(empleadoModificar,indice_id2)==1)
					{
						ll_set(pArrayListEmployee,indice_id2,empleadoModificar);
						retorno=1;
					}
            		break;
            	case 2:
            		return 0;
            		break;
            	}
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int indice_id;
    int indice_id2=0;
    int pregunta;
    Employee* empleadoBorrar=NULL;
    empleadoBorrar=employee_new();
    if(pArrayListEmployee!=NULL && empleadoBorrar!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        utn_getNumero(&indice_id,"\nIngrese el id a modificar: ","\nERROR - CARGA INCORRECTO\n",0,100000,3);
        indice_id2 = indice_id - 1;

        empleadoBorrar=(Employee*)ll_get(pArrayListEmployee,indice_id2);
        if(empleadoBorrar==NULL)
        {
            printf("El empleado no existe.\n");
            return 0;
        }
        else
        {
        	printf("\n\nSelecionado:\n");
            empleado_listarUNEmpleado(empleadoBorrar);
            if(utn_getNumero(&pregunta,"\nPara moficionar presione:\n"
                        						   "1. SI\n"
                        						   "2. NO - CANCELAR Y VOLVER\n"
                        					   	   "ELIJA: ","\nERROR - CARGA INCORRECTO\n",1,2,3)==0)
            {
            	switch (pregunta)
            	{
            	case 1:
            		if(empleado_modificar(empleadoBorrar,indice_id2)==1)
					{
            			ll_remove(pArrayListEmployee,indice_id2);
            			retorno=1;
					}
            		break;
            	case 2:
            		return 0;
            		break;
            	}
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* auxEmplempleado=NULL;

    if(pArrayListEmployee!=NULL)
    {
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmplempleado=(Employee*)ll_get(pArrayListEmployee,i);
            empleado_listarUNEmpleado(auxEmplempleado);
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    printf("\nOrdenamiento de A a Z\n");
    if(ll_sort(pArrayListEmployee,empleado_CompararNOMBRES,1) == 0)
    {
    	retorno = 1;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int cantidad;
    int auxID;
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre[128];
    Employee* empleado=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* archivo;
        archivo=fopen(path,"r");
        if(archivo!=NULL)
        {
            archivo=fopen(path,"w");
            if(archivo!=NULL)
            {
                for(int i=0;i<ll_len(pArrayListEmployee);i++)
                {
                    empleado=employee_new();
                    if(empleado!=NULL)
                    {
                        empleado=(Employee*)ll_get(pArrayListEmployee,i);
                        employee_getId(empleado,&auxID);
                        employee_getNombre(empleado,auxNombre);
                        employee_getHorasTrabajadas(empleado,&auxHorasTrabajadas);
                        employee_getSueldo(empleado,&auxSueldo);
                        cantidad=fprintf(archivo,"%d,%s,%d,%d\n",auxID,auxNombre,auxHorasTrabajadas,auxSueldo);
                        if(cantidad<1)
                        {
                            return 0;
                        }
                        else
                        {
                            retorno=1;
                        }
                    }
                }
            }
            else
            {
                return 0;
            }
        }
        fclose(archivo);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int cantidad;
    Employee* empleado=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* archivo;
        archivo=fopen(path,"rb");
        if(archivo!=NULL)
        {
            archivo=fopen(path,"wb");
            if(archivo!=NULL)
            {
                for(int i=0;i<ll_len(pArrayListEmployee);i++)
                {
                    empleado=employee_new();
                    if(empleado!=NULL)
                    {
                        empleado=ll_get(pArrayListEmployee,i);
                        cantidad=fwrite(empleado,sizeof(Employee),1,archivo);
                        if(cantidad==1)
                        {
                            retorno=1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
             return 0;
        }
        fclose(archivo);
    }
    return retorno;
}
/*************************************************************************
 * ***********************************************************************
 */
int controller_idmaximo(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int i;
    Employee* auxEmplempleado=NULL;

    if(pArrayListEmployee!=NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmplempleado=(Employee*)ll_get(pArrayListEmployee,i);
            if(auxEmplempleado!=NULL)
			{
				if(auxEmplempleado->id > retorno)
				{
					retorno = auxEmplempleado->id;
				}
			}
        }
    }
   // printf("\n\n\nEL ID MAXIMO ES %d\n\n",retorno);
    retorno = retorno + 1;
    return retorno;
}
