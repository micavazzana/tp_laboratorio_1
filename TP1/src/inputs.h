/*
 * inputs.h
 *
 *  Created on: 8 sep. 2020
 *      Author: micavazzana
 */

#ifndef INPUTS_H_
#define INPUTS_H_

/**
 * \brief Solicita un entero al usuario
 * \param int *pOutcome, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char *message, Es el mensaje a ser mostrado al usuario
 * \param char *messageError, Es el mesaje de error a ser mostrado al usuario
 * \param int min, valor minimo admitido
 * \param int max, valor maximo admitido
 * \param int retries, cantidad de oportunidades para ingresar el dato
 * \return (-1) Error / (0) Exito
 */
int utn_getNumero(int *pOutcome, char *message, char *messageError, int min, int max, int retries);

/**
 * \brief Solicita un flotante al usuario
 * \param float *pOutcome, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char *message, Es el mensaje a ser mostrado al usuario
 * \param char *messageError, Es el mesaje de error a ser mostrado al usuario
 * \param float min, valor minimo admitido
 * \param float max, valor maximo admitido
 * \param int retries, cantidad de oportunidades para ingresar el dato
 * \return (-1) Error / (0) Exito
 */
int utn_getNumeroFloat(float *pOutcome, char *message, char *messageError, int min, int max, int retries);

/**
 * \brief
 * \param
 * \return
 */
int utn_getChar(char *pOutcome, char *message, char *messageError, int retries);

/**
 * \brief
 * \param
 * \return
 */
int utn_getOptionMenu(int *pOption, float operandoUno, float operandoDos, int min, int max, int retries);

#endif /* INPUTS_H_ */
