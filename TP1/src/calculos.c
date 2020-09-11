#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int sumar(float operandoUno, float operandoDos, float *pResultado)
{
    int retorno = -1;

    if (pResultado != NULL)
    {
        *pResultado = operandoUno + operandoDos;
        retorno = 0;
    }

    return retorno;
}

int restar(float operandoUno, float operandoDos, float *pResultado)
{
    int retorno = -1;

    if (pResultado != NULL)
    {
        *pResultado = operandoUno - operandoDos;
        retorno = 0;
    }

    return retorno;
}

int dividir(float operandoUno, float operandoDos, float *pResultado)
{
    int retorno = -1;

    if (pResultado != NULL && operandoDos != 0)
    {
        *pResultado = operandoUno / operandoDos;
        retorno = 0;
    }

    return retorno;
}

int multiplicar(float operandoUno, float operandoDos, float *pResultado)
{
    int retorno = -1;

    if (pResultado != NULL)
    {
        *pResultado = operandoUno * operandoDos;
        retorno = 0;
    }

    return retorno;
}

int calcularFactorial(int operando, long int*pResultado)
{
    int retorno = -1;
    long int auxFactorial=1;
    int i;

    if (pResultado != NULL && operando >= 0)
    {
        for (i = operando; i > 0; i--)
        {
            auxFactorial = auxFactorial * i;
        }
        *pResultado = auxFactorial;
        retorno = 0;
    }

    return retorno;
}
