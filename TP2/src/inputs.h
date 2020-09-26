/*
 * inputs.h
 *
 *  Created on: 18 sep. 2020
 *      Author: micavazzana
 */

#ifndef INPUTS_H_
#define INPUTS_H_

/**
 * \brief Solicita que ingrese un numero al usuario (dato entero)
 * \param int *pNumber, puntero al espacio donde se dejara el valor obtenido
 * \param char *message, Es el mensaje a ser mostrado al usuario
 * \param char *errorMessage, Es el mesaje de error a ser mostrado al usuario
 * \param int min, valor minimo admitido
 * \param int max, valor maximo admitido
 * \param int retries, cantidad de oportunidades para ingresar el dato
 * \return (-1) ERROR (0) EXITO
 */
int utn_getNumber(int* pNumber, char* message, char* errorMessage, int min, int max,int retries);

/**
 * \brief Solicita que ingrese un numero al usuario (dato con decimales)
 * \param float *pNumber, puntero al espacio donde se dejara el valor obtenido
 * \param char *message, Es el mensaje a ser mostrado al usuario
 * \param char *errorMessage, Es el mesaje de error a ser mostrado al usuario
 * \param float min, valor minimo admitido
 * \param float max, valor maximo admitido
 * \param int retries, cantidad de oportunidades para ingresar el dato
 * \return (-1) ERROR (0) EXITO
 */
int utn_getFloatNumber(float *pNumber, char *message, char *errorMessage, float min, float max, int retries);

/**
 *
 */
int utn_getName(char* name, int len, char* message, char* errorMessage, int retries);

/**
 *
 */
int utn_getAlphanumeric(char* name, int len, char* message, char* errorMessage, int retries);

#endif /* INPUTS_H_ */
