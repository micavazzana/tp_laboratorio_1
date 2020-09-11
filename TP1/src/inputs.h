/*
 * inputs.h
 *
 *  Created on: 8 sep. 2020
 *      Author: micavazzana
 */

#ifndef INPUTS_H_
#define INPUTS_H_

/**
 * \brief Obtiene una cadena de caracteres
 * \param char* string, puntero a la cadena donde deja lo obtenido
 * \param int len, tama�o de la cadena que se recibe
 * \return (-1) ERROR (0) EXITO
 */
int getString(char* string, int len);

/**
 * \brief Obtiene un entero y lo valida
 * \param int* entero, puntero al espacio donde dejo lo obtenido
 * \return (-1) ERROR (0) EXITO
 */
int getInt(int* entero);

/**
 * \brief Valida que lo recibe sea un numero. Contempla tanto negativos como positivos
 * \param char *num, puntero a la cadena que se busca validar
 * \return (-1) ERROR (0) EXITO
 */
int validationInt(char *num);

/**
 * \brief Obtiene un numero con decimales y lo valida
 * \param int* flotante, puntero al espacio donde dejo lo obtenido
 * \return (-1) ERROR (0) EXITO
 */
int getFloat(float *flotante);

/**
 * \brief Valida que lo recibe sea un numero. Contempla tanto negativos como positivos y decimales
 * \param char *num, puntero a la cadena que se busca validar
 * \return (-1) ERROR (0) EXITO
 */
int validationFloat(char *num);

/**
 * \brief Solicita que ingrese un numero al usuario (dato entero)
 * \param int *pResultado, puntero al espacio donde se dejara el valor obtenido
 * \param char *mensaje, Es el mensaje a ser mostrado al usuario
 * \param char *mensajeError, Es el mesaje de error a ser mostrado al usuario
 * \param int min, valor minimo admitido
 * \param int max, valor maximo admitido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \return (-1) ERROR (0) EXITO
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos);

/**
 * \brief Solicita que ingrese un numero al usuario (dato con decimales)
 * \param int *pResultado, puntero al espacio donde se dejara el valor obtenido
 * \param char *mensaje, Es el mensaje a ser mostrado al usuario
 * \param char *mensajeError, Es el mesaje de error a ser mostrado al usuario
 * \param int min, valor minimo admitido
 * \param int max, valor maximo admitido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \return (-1) ERROR (0) EXITO
 */
int utn_getNumeroFloat(float *pResultado, char *mensaje, char *mensajeError, float min, float max, int reintentos);

/** \brief Le pide al usuario que ingrese una opcion del menu que le ofrece y muestra los operandos ingresados
 * \param int *pOpcion, puntero al espacio donde se dejara la opcion del menu elegida
 * \param float operandoUno, operando ingresado en la primer opcion
 * \param float operandoDos, operando ingresado en la segunda opcion
 * \param int min, valor minimo admitido
 * \param int max, valor maximo admitido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \return (-1) ERROR (0) EXITO
 */
int getOptionMenu(int *pOpcion, float operandoUno, float operandoDos, int min, int max, int reintentos);

#endif /* INPUTS_H_ */
