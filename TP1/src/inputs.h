/*
 * inputs.h
 *
 *  Created on: 8 sep. 2020
 *      Author: micavazzana
 */

#ifndef INPUTS_H_
#define INPUTS_H_

int getString(char* string, int len);

int getInt(int* entero);

int validationInt(char *num);

int getFloat(float *flotante);

int validationFloat(char *num);

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos);

int utn_getNumeroFloat(float *pResultado, char *mensaje, char *mensajeError, float min, float max, int reintentos);

int getOptionMenu(int *pOpcion, float operandoUno, float operandoDos, int min, int max, int reintentos);

#endif /* INPUTS_H_ */

