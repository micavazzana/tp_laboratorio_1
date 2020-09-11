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

int getString(char* string, int len)
{
    int retorno = ERROR;
    char aux[4096];

    if(string != NULL && len > 0)
    {
        fpurge(stdin);
        fgets(aux,sizeof(aux),stdin); //fgets (direccionDeLaVariable,cantidadCaracteresDeLaVariable,stdin)
        aux[strnlen(aux,sizeof(aux))-1]='\0';//pongo un \0 en vez del \n que me genera el fgets

        if(strnlen(aux,sizeof(aux)) <= len)//garantizo que lo ingresado sea menor a lo que recibo como tama�o por paramtero
        {
            strncpy(string,aux,len); //lo guardo en mi puntero string
            retorno = EXITO;
        }
    }

    return retorno;
}

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
