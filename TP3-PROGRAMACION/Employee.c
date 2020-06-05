#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "menu.h"
#include "getBibliotecas.h"

Employee* employee_new()
{
    Employee* emplempleadoNuevo = (Employee*)malloc(sizeof(Employee));
    if(emplempleadoNuevo!=NULL)
    {
        emplempleadoNuevo->id=0;
        strcpy(emplempleadoNuevo->nombre," ");
        emplempleadoNuevo->horasTrabajadas=0;
        emplempleadoNuevo->sueldo=0;
    }
     return emplempleadoNuevo;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* punteroEmpleado = employee_new();
    if(punteroEmpleado!=NULL)
    {
        if(employee_setId(punteroEmpleado,atoi(idStr)),
           employee_setNombre(punteroEmpleado,nombreStr),
           employee_setHorasTrabajadas(punteroEmpleado,atoi(horasTrabajadasStr)),
           employee_setSueldo(punteroEmpleado,atoi(sueldoStr)))
        {

        }
    }
    else
    {
        punteroEmpleado=NULL;
    }
    return punteroEmpleado;
}

int employee_delete(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno=0;
    if(this!=NULL)
    {
        if(id>0)
        {
            this->id=id;
            retorno=1;
        }
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)<128)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=1;
    }
    return retorno;
}

int empleado_listarUNEmpleado(Employee* this)
{
    int retorno=0;
     if(this!=NULL)
    {
        printf("ID: %d ||| Nombre: %s ||| Horas Trabajadas: %d ||| Suelo: %d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
        retorno=1;
    }
    return retorno;
}
int empleado_listarTODOS(Employee* this, int size)
{
    int retorno=0;
    if(this!=NULL && size>0)
    {
        for(int i=0;i<size;i++)
        {
            empleado_listarUNEmpleado(this+i);
        }
        retorno=1;
    }
    return retorno;
}

int empleado_alta(Employee* this, int indice)
{
    int retorno=0;
    char auxNombre[128];
    int auxHoras;
    int sueldo;

    if(this!=NULL)
    {
    	if((utn_getNombre(auxNombre,128,"\nIngrese el nombre del empleado: ","\nERROR - CARGA INCORRECTO\n", 3)==0) &&
    	   (utn_getNumero(&auxHoras,"\nIngrese las horas trabajadas del empleado: ","\nERROR - CARGA INCORRECTO\n",1,9999,3)==0) &&
		   (utn_getNumero(&sueldo,"\nIngrese el sueldo del empleado: ","\nERROR - CARGA INCORRECTO\n",1,99999,3)==0))
		{
    		if(!employee_setNombre(this,auxNombre))
			{
				return 0;
			}
			if(!employee_setId(this,indice))
			{
				return 0;
			}
			if(!employee_setHorasTrabajadas(this,auxHoras))
			{
				return 0;
			}
			if(!employee_setSueldo(this,sueldo))
			{
				return 0;
			}
		}
        printf("\n\nAlta dada con exito.\n\n");
        retorno=1;
    }
    return retorno;
}

int empleado_modificar(Employee* this,int index)
{
    int opcion=0;
    int retorno=0;
    int auxHoras;
    int sueldo;
    char auxNombre[128];

    do
    {
    	if(utn_getNumero(&opcion,"\n1.Nombre\n"
    						     "2.Horas trabajadas\n"
    						     "3.Sueldo\n"
    						     "4.Volver - Terminar\n"
    						     "Elija:","\nERROR - CARGA INCORRECTO\n",1,4,3)==0)
		{
    		 switch (opcion)
    		 {
    		 case 1:
    			 if(utn_getNombre(auxNombre,128,"\nIngrese el nombre: ","\nERROR - CARGA INCORRECTO\n", 3)==0)
    			 {
    				 employee_setNombre(this,auxNombre);
    				 retorno=1;
    			 }
    			 break;
    		 case 2:
				if(utn_getNumero(&auxHoras,"\nIngrese las horas trabajadas: ","\nERROR - CARGA INCORRECTO\n",1,9999,3)==0)
				{
					employee_setHorasTrabajadas(this,auxHoras);
					retorno=1;
				}
				break;
    		 case 3:
    			 if(utn_getNumero(&sueldo,"\nIngrese el sueldo: ","\nERROR - CARGA INCORRECTO\n",1,99999,3)==0)
    			 {
    				 employee_setSueldo(this,sueldo);
    				 retorno=1;
    			 }
    			 break;
    		 case 4:
    			 break;
			}
		}
    } while(opcion!=4);

    return retorno;
}
int empleado_CompararNOMBRES(void* empleado_1,void* empleado_2)
{
    Employee* empleado1=empleado_1;
    Employee* empleado2=empleado_2;
    return strcmp(empleado1->nombre,empleado2->nombre);
}
