/*
 * biblioteca.c
 *
 *  Created on: 7 abr. 2020
 *      Author: Manuel Ignacio Bever
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "getBibliotecas.h"

static int esNumerica(char* cadena, int limite);

static int getInt(int* pResultado);

static int esNombre(char* cadena,int longitud);

static int getNombre(char* pResultado,int longitud);

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		setbuf(stdout, NULL);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/*
 *
 *
 *
 *
 *
 *
 *
 *
 */

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 si se obtiene un numero entero y -1 si no
 */

static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[4096];
    if(	pResultado != NULL &&
    	myGets(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */

static int esNumerica(char* cadena, int limite)
{
	int retorno = 1; // VERDADERO
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;		}
		//CONTINUE
	}
	//BREAK
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

/*
 *
 *
 *
 *
 *
 *
 *
 *
 */

/**
 * \brief Hace unos saltos los cuales "limpian" la pantalla
 */
void ClearScreen()
  {
	for(int x=0; x<5; x++){
		printf("\n");
	}
  }

/*
 *
 *
 *
 *
 *
 *
 *
 *
 */

/**
 * \brief Verifica si la cadena ingresada es un numero flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	int retorno=-1;
    char bufferStr[40];

    if(mensaje!=NULL && mensajeError!=NULL && minimo<maximo && reintentos>=0 && pResultado!=NULL)
    {
        do
        {
        	printf("%s",mensaje);
        	setbuf(stdout, NULL);
        	fgets(bufferStr,sizeof(bufferStr),stdin);
        	if(bufferStr[strlen(bufferStr)-1] == '\n')
        		{
        			bufferStr[strlen(bufferStr)-1] = '\0';
        		}

        	if(validarNumeroFloat(bufferStr)==1)
                {
        		*pResultado=atof(bufferStr); // atof array to float
                 if(*pResultado>=minimo && *pResultado<=maximo)
                 {
                	 retorno=0;
                	 break;
                 }
                 else
                 {
                	 printf("%s",mensajeError);
                	 reintentos--;
                 }
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }

        }
        while(reintentos>=0);
    }
    return retorno;
}

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int validarNumeroFloat(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int contadorPuntos=0;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9') // pregunto si es un numero o no
        {
        	if(stringRecibido[i]!='.') // pregunto si tiene un .
        	{
        		contadorPuntos++;
        		if(contadorPuntos>1) // pregunto si hay otro punto, si hay es invalido
        		{
        			retorno=0;
        			break;
        		}
        	}
        	else
        	{
        		if(i==0) // pregunto en el primer casillero sea positivo o negativo, si no lo es salgo
        		{
        			if(stringRecibido[i]!= '+' && stringRecibido[i]!='-')
        			{
        				retorno=0;
        				break;
        			}
        		}
        	}
        }
    }
    return retorno;
}

/*
 *
 *
 *
 *
 *
 *
 *
 *
 */

/**
 * \brief Solicita una letra al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el caracter maximo a ser aceptado
 * \param maximo Es el caracter minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el char y -1 si no
 */
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char bufferChar[256];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			if(myGets(bufferChar,sizeof(bufferChar))==0) //==0
			{
				if(isValidChar(bufferChar[0])==1)
				{
					*pResultado=bufferChar[0];
					retorno=0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			}

		}while(reintentos>=0);

	}
	return retorno;
}

/**validar que sea caracterer .
* char* stringrecibido.
* revisa la cadena cumpla con las condiciones
*\return status -1 si hay error, 0 si  esta todo bien
*
*/
int isValidChar(char charRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    if(charRecibido<'A' || (charRecibido>'Z' && charRecibido<'a') || charRecibido>'z')
        retorno=0;
    return retorno;
}

/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	myGets(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i]<' ' || cadena[i]>'z')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero char y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/** utn_getEmail le solicita un mail al cliente
 * char* mensaje - solicita un mensaje que figura en la consultsa
 * char* mensajeError - en caso de ser negada la pregunta sale el mensaje de error
 * int longitud - tama�o del vector
 * int reintentos - intentos para realizar el programa al quedar sin intentos sale
 * char* pResultado - puntero de la variable donde se guaradara lo cargado
*/
int utn_getEmail(char* mensaje, char* mensajeError, int longitud, int reintentos, char* pResultado)
{
    int retorno=-1;
    char bufferString[longitud];

    if(mensaje!=NULL && mensajeError!=NULL && reintentos>=0 && pResultado!=NULL)
    {
        do
        {
        	printf("%s",mensaje);
        	if(myGets(bufferString,sizeof(bufferString)) == 0) //==0 sin errores !0
            {
                if(isValidEmail(bufferString)==1)
                {
                    strncpy(pResultado,bufferString,longitud);
                    retorno=0;
                    break;
                }
                else
                {
                	printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


/** validar que sea un email .
*
*char* stringrecibido.
*revisa la cadena cumpla con las condiciones
*retorno  -1 si hay error, 0 si  esta todo bien
*
*/
int isValidEmail(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}


/*
 *
 *
 *
 *
 *
 *
 *
 *
 */


/* pide cuit valido
*
* char* mensaje indica el mensaje de lo que se pide
* char* mensajeError indica el mensaje de ERROR en la consola en caso de que se falle
* int tamanoMinimo el minimo que tiene que ser la cadena
* int tamanoMaximo el maximo que tiene que ser la cadena
* int reintentos si hay error
* pResultado* puntero donde se guardara lo cargado en caso de estar correcto!
* return retorno -1 si hay error, 0 si  esta todo bien
*
*/
int utn_getCUIT(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    int tamanoMaximo=14; //con guiones 13 elementos
    int tamanoMinimo=11;  // sin puntos
    int retorno=-1;
    char bufferString[tamanoMaximo];

    if(mensaje!=NULL && mensajeError!=NULL && tamanoMinimo<tamanoMaximo && reintentos>=0 && pResultado!=NULL)
    {
        do
        {
        	printf("%s",mensaje);
            if(myGets(bufferString,sizeof(bufferString)) == 0) //==0 sin errores !0
            {
                if(isValidCUIT(bufferString)== 1)
                {
                    strncpy(pResultado,bufferString,tamanoMaximo);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
/* validar que sea un cuit .
*
* char* stringrecibido.
* revisa la cadena cumpla con las condiciones
*\return retorno -1 si hay error, 0 si  esta todo bien
*
*/
int isValidCUIT(char* stringRecibido)
{
    int retorno = 1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    char bufferString[14];
    strncpy(bufferString,stringRecibido,14);

    for(i=0;bufferString[i]!='\0';i++) // RESALIZO UN FORMO HASTA QUE ENCUENTRO EL PUNTO FINAL DEL VECTOR
    {
        if((bufferString[i]<'0' || bufferString[i]>'9') && (bufferString[i]!='-')) // chequeo que solo sean numeros o gion
        {
            retorno=0;
            break;
        }
    }

    return retorno;
}
