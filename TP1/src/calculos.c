#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

/**
 * \brief Realiza la operacion matematica SUMA
 * \param float operandoUno, primer operando
 * \param float operandoDos, segundo operando
 * \param float *pResultado, puntero a donde de guardara el resultado de la operacion
 * \return (-1) ERROR (0) EXITO
 */
int sumar(float operandoUno, float operandoDos, float *pResultado) {

	int retorno = -1;

	if (pResultado != NULL) {
		*pResultado = operandoUno + operandoDos;
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Realiza la operacion matematica RESTA
 * \param float operandoUno, primer operando
 * \param float operandoDos, segundo operando
 * \param float *pResultado, puntero a donde de guardara el resultado de la operacion
 * \return (-1) ERROR (0) EXITO
 */
int restar(float operandoUno, float operandoDos, float *pResultado) {

	int retorno = -1;

	if (pResultado != NULL) {
		*pResultado = operandoUno - operandoDos;
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Realiza la operacion matematica DIVISION
 * \param float operandoUno, primer operando
 * \param float operandoDos, segundo operando
 * \param float *pResultado, puntero a donde de guardara el resultado de la operacion
 * \return (-1) ERROR (0) EXITO
 */
int dividir(float operandoUno, float operandoDos, float *pResultado) {
	int retorno = -1;

	if (pResultado != NULL && operandoDos != 0) {
		*pResultado = operandoUno / operandoDos;
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Realiza la operacion matematica MULTIPLICACION
 * \param float operandoUno, primer operando
 * \param float operandoDos, segundo operando
 * \param float *pResultado, puntero a donde de guardara el resultado de la operacion
 * \return (-1) ERROR (0) EXITO
 */
int multiplicar(float operandoUno, float operandoDos, float *pResultado) {
	int retorno = -1;

	if (pResultado != NULL) {
		*pResultado = operandoUno * operandoDos;
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Calcula el FACTORIAL de un numero
 * \param float operando, operando ingresado
 * \param long int *pResultado, puntero a donde de guardara el resultado de la operacion
 * \return (-1) ERROR (0) EXITO
 */
int calcularFactorial(float operando, long int*pResultado) {

	int retorno = -1;
	long long int auxFactorial=1;
	int i;

	if (pResultado != NULL && operando >= 0) {
		for (i = operando; i > 0; i--) {
			auxFactorial = auxFactorial * i;
		}
		*pResultado = auxFactorial;
		retorno = 0;
	}

	return retorno;
}
