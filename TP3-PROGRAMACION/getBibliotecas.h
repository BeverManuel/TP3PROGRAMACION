/*
 * biblioteca.h
 *
 *  Created on: 7 abr. 2020
 *      Author: Manuel Ignacio Bever
 */

#ifndef GETBIBLIOTECAS_H_
#define GETBIBLIOTECAS_H_

int myGets(char* cadena, int longitud);

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int isValidChar(char charRecibido);

void ClearScreen();

int validarNumeroFloat(char* stringRecibido);

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int utn_getEmail(char* mensaje, char* mensajeError, int longitud, int reintentos, char* pResultado);

int isValidEmail(char* stringRecibido);

int utn_getCUIT(char* pResultado, char* mensaje, char* mensajeError, int reintentos);

int isValidCUIT(char* stringRecibido);

#endif /* GETBIBLIOTECAS_H_ */
