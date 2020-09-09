/*
 * inputs.c
 *
 *  Created on: 8 sep. 2020
 *      Author: micavazzana
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#define EXITO 0
#define ERROR -1

/**
 * \brief Obtiene una cadena de caracteres
 * \param char* string, puntero a la cadena donde deja lo obtenido
 * \param int len, tamaño de la cadena que se recibe
 * \return (-1) ERROR (0) EXITO
 */
int getString(char* string, int len)
{
    int retorno = ERROR;
    char aux[4096];

    if(string != NULL && len > 0)
    {
        fpurge(stdin);
        fgets(aux,sizeof(aux),stdin); //fgets (direccionDeLaVariable,cantidadCaracteresDeLaVariable,stdin)
        aux[strnlen(aux,sizeof(aux))-1]='\0';//pongo un \0 en vez del \n que me genera el fgets

        if(strnlen(aux,sizeof(aux)) <= len)//garantizo que lo ingresado sea menor a lo que recibo como tamaño por paramtero
        {
            strncpy(string,aux,len); //lo guardo en mi puntero string
            retorno = EXITO;
        }
    }

    return retorno;
}

/**
 * \brief Obtiene un entero y lo valida
 * \param int* entero, puntero al espacio donde dejo lo obtenido
 * \return (-1) ERROR (0) EXITO
 */
int getInt(int* entero)
{
    int retorno = ERROR;
    char aux[4096];

    if(entero != NULL)
    {
        if(getString(aux,sizeof(aux))== EXITO && validationInt(aux) == EXITO)//obtengo una cadena y la valido
        {
            *entero = atoi(aux);//la convierto en entero y la asigno al puntero a entero
            retorno = EXITO;
        }
    }
    return retorno;
}

/**
 * \brief Valida que lo ingresado sea un numero. Contempla tanto negativos como positivos
 * \param char *num, puntero a la cadena que se busca validar
 * \return (-1) ERROR (0) EXITO
 */
int validationInt(char *num)
{
    int retorno = EXITO;
    int i = 0;

    if(num != NULL)
    {
        if(num[0] == '-' || num[0] == '+')
        {
            i = 1;
        }

        for( ; num[i]!= '\0'; i++)
        {
            if(num[i] < '0' || num[i] > '9')
            {
                retorno = ERROR;
                break;
            }
        }
    }

    return retorno;
}

/**
 * \brief Obtiene un numero con decimales y lo valida
 * \param int* flotante, puntero al espacio donde dejo lo obtenido
 * \return (-1) ERROR (0) EXITO
 */
int getFloat(float *flotante)
{
    int retorno = ERROR;
    char aux[4096];

    if(flotante != NULL)
    {
        if(getString(aux,sizeof(aux))== EXITO && validationFloat(aux) == EXITO)
        {
            *flotante = atof(aux);
            retorno = EXITO;
        }
    }
    return retorno;
}

/**
 * \brief Valida que lo ingresado sea un numero. Contempla tanto negativos como positivos y decimales
 * \param char *num, puntero a la cadena que se busca validar
 * \return (-1) ERROR (0) EXITO
 */
int validationFloat(char *num)
{
    int retorno = EXITO;
    int i = 0;
    int contadorDePuntos = 0;

    if(num != NULL)
    {
        if(num[0] == '-' || num[0] == '+')
        {
            i = 1;
        }

        for( ; num[i]!= '\0'; i++)
        {
            if(num[i] < '0' || num[i] > '9')
            {
                if(num[i] == '.')
                {
                    contadorDePuntos++;
                    if(contadorDePuntos>1)
                    {
                        retorno = ERROR;
                        break;
                    }
                }
                else
                {
                    retorno = ERROR;
                    break;
                }
            }
        }
    }

    return retorno;
}

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
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos)
{
    int retorno = ERROR;
    int auxInt;

    if(pResultado != NULL && mensaje !=NULL && mensajeError != NULL && reintentos>0 && min < max && max > min)
    {
        while(reintentos > 0)
        {
            printf("%s",mensaje);
            if(getInt(&auxInt) == ERROR || (auxInt < min || auxInt > max))
            {
                printf("%s",mensajeError);
                reintentos--;
            }
            else
            {
                *pResultado = auxInt;
                retorno = EXITO;
                break;
            }
        }
    }

    return retorno;
}



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
int utn_getNumeroFloat(float *pResultado, char *mensaje, char *mensajeError, float min, float max, int reintentos)
{
    int retorno = ERROR;
    float auxFloat;

    if(pResultado != NULL && mensaje !=NULL && mensajeError != NULL && reintentos>0 && min < max && max > min)
    {
        while(reintentos > 0)
        {
            printf("%s",mensaje);
            if(getFloat(&auxFloat) == ERROR || (auxFloat < min || auxFloat > max))
            {
                printf("%s",mensajeError);
                reintentos--;
            }
            else
            {
                *pResultado = auxFloat;
                retorno = EXITO;
                break;
            }
        }
    }

    return retorno;
}

/** \brief Le pide al usuario que ingrese una opcion del menu que le ofrece y muestra los operandos ingresados
 * \param int *pOpcion, puntero al espacio donde se dejara la opcion del menu elegida
 * \param float operandoUno, operando ingresado en la primer opcion
 * \param float operandoDos, operando ingresado en la segunda opcion
 * \param int min, valor minimo admitido
 * \param int max, valor maximo admitido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \return (-1) ERROR (0) EXITO
 */
int getOptionMenu(int *pOpcion, float operandoUno, float operandoDos, int min, int max, int reintentos)
{
    int retorno = ERROR;
    int auxOpcion;

    if (pOpcion != NULL && reintentos > 0 && min < max && max > min)
    {
        while (reintentos > 0)
        {
            printf("\nMenu\n"
                   "\n1. Ingresar primer operando:  %.2f"
                   "\n2. Ingresar segundo operando: %.2f"
                   "\n3. Calcular todas las operaciones"
                   "\n4. Informar resultados"
                   "\n5. Salir"
                   "\n\nElija una opcion: ", operandoUno, operandoDos);
            if(getInt(&auxOpcion) == ERROR || (auxOpcion < min || auxOpcion > max))
            {
                printf("Error! Elija una opcion valida");
                reintentos--;
            }
            else
            {
                *pOpcion = auxOpcion;
                retorno = EXITO;
                break;
            }
        }
    }
    return retorno;
}
