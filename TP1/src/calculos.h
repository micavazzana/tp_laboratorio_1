/*
 * calculos.h
 *
 *  Created on: 8 sep. 2020
 *      Author: micavazzana
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
 * \brief Realiza la operacion matematica SUMA
 * \param float operandoUno, primer operando
 * \param float operandoDos, segundo operando
 * \param float *pResultado, puntero a donde de guardara el resultado de la operacion
 * \return (-1) ERROR (0) EXITO
 */
int sumar(float operandoUno, float operandoDos, float *pResultado);

/**
 * \brief Realiza la operacion matematica RESTA
 * \param float operandoUno, primer operando
 * \param float operandoDos, segundo operando
 * \param float *pResultado, puntero a donde de guardara el resultado de la operacion
 * \return (-1) ERROR (0) EXITO
 */
int restar(float operandoUno, float operandoDos, float *pResultado);

/**
 * \brief Realiza la operacion matematica DIVISION
 * \param float operandoUno, primer operando
 * \param float operandoDos, segundo operando
 * \param float *pResultado, puntero a donde de guardara el resultado de la operacion
 * \return (-1) ERROR (0) EXITO
 */
int dividir(float operandoUno, float operandoDos, float *pResultado);

/**
 * \brief Realiza la operacion matematica MULTIPLICACION
 * \param float operandoUno, primer operando
 * \param float operandoDos, segundo operando
 * \param float *pResultado, puntero a donde de guardara el resultado de la operacion
 * \return (-1) ERROR (0) EXITO
 */
int multiplicar(float operandoUno, float operandoDos, float *pResultado);

/**
 * \brief Calcula el FACTORIAL de un numero
 * \param float operando, operando ingresado
 * \param long int *pResultado, puntero a donde de guardara el resultado de la operacion
 * \return (-1) ERROR (0) EXITO
 */
int calcularFactorial(float operando, long int *pResultado);

#endif /* CALCULOS_H_ */
