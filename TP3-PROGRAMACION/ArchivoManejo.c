/*
 * archivo.c
 *
 *  Created on: 4 jun. 2020
 *      Author: Manuel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArchivoManejo.h"
#include "getBibliotecas.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"


void manejo(void)
{
    int opcionMenu  = 0;
    int bandera = 0;
    int confirmarSalida = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados!=NULL)
    {
        do
        {
            opcionMenu=menu();
            switch (opcionMenu)
            {
            case 1:
            	if(bandera == 0)
            	{
            		if(controller_loadFromText("data.csv",listaEmpleados)==1)
					 {
						 printf("Archivo en modo texto cargado correctamente.\n\n");
					 }
            		bandera = 1;
            	}
                break;

            case 2:
            	if(bandera == 0)
            	{
            		if(controller_loadFromBinary("data.csv",listaEmpleados)==1)
					{
						printf("Archivo en modo binario cargado correctamente.\n\n");
					}
            		bandera = 1;
            	}
                break;

            case 3:
            	if(bandera == 1)
            	{
            		controller_addEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\nEl archivo no se encuentra abierto!\n\n");
            	}
                break;

            case 4:
            	if(bandera == 1)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
				{
					printf("\nEl archivo no se encuentra abierto!\n\n");
				}
                break;

            case 5:
            	if(bandera == 1)
            	{
            		controller_removeEmployee(listaEmpleados);
            	}
            	else
				{
					printf("\nEl archivo no se encuentra abierto!\n\n");
				}
                break;

            case 6:
            	if(bandera == 1)
				{
            		controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("\nEl archivo no se encuentra abierto!\n\n");
				}
                break;

            case 7:
            	if(bandera == 1)
				{
            		controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("\nEl archivo no se encuentra abierto!\n\n");
				}
                break;

            case 8:
            	if(bandera == 1)
				{
            		if(controller_saveAsText("data.csv",listaEmpleados)==1)
					{
						printf("Archivo de texto guardado con exito.\n\n");
					}
            		confirmarSalida = 1;
				}
				else
				{
					printf("\nEl archivo no se encuentra abierto!\n\n");
				}
                break;

            case 9:
            	if(bandera == 1)
				{
            		if(controller_saveAsBinary("data.csv",listaEmpleados)==1)
					{
						printf("Archivo binario guardado con exito.\n\n");
					}
            		confirmarSalida = 1;
				}
				else
				{
					printf("\nEl archivo no se encuentra abierto!\n\n");
				}
                break;
            case 10:
            	if(confirmarSalida == 0)
            	{
            		int consulta;
            		if(utn_getNumero(&consulta,"Seguro que quiere salir sin guardar?\n"
													  "1.Si \n2.No\n"
													  "Elija:"
													 ,"\n--- ERROR ---\n",1,2,3) == 0)
					{
            			if(consulta == 1)
            			{
            				break;
            			}
            			if(consulta == 2)
						{
            				opcionMenu = -1;
            				break;
						}
					}
            	}
            	if(confirmarSalida == 1)
				{
            		printf("\nARCHIVO GUARDADO Y SALIENDO.\n\n");
            		break;
				}
            }
        }while(opcionMenu!=10);
    }
    else
    {
        printf("Hubo un problema al asignar memoria.\n\n");
    }

}

