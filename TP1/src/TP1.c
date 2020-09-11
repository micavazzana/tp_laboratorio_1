/*
 ============================================================================
 Name        : TP1.c
 Author      : micavazzana
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Proyecto hecho en macOS
*/
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "inputs.h"
#include "calculos.h"
#define EXITO 0

int main(void)
{
    int opcion;
    float operandoUno = 0;
    float operandoDos = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    long int resultadoFactorialUno;
    long int resultadoFactorialDos;
    int resultadoFuncionSumar;
    int resultadoFuncionRestar;
    int resultadoFuncionDividir;
    int resultadoFuncionMultiplicar;
    int resultadoFuncionFactorialUno;
    int resultadoFuncionFactorialDos;
    int obtuveOperandoUno;
    int obtuveOperandoDos;

    do
    {
        if (getOptionMenu(&opcion, operandoUno, operandoDos, 1, 5, 3)==EXITO)
        {
            switch (opcion)
            {
            case 1:
                obtuveOperandoUno = utn_getNumeroFloat(&operandoUno,"Ingrese primer operando: ","Error, debe ingresar un numero.\n",FLT_MIN, FLT_MAX,3);
                if (obtuveOperandoUno == EXITO) {
                    printf("\nIngresado con exito\n");
                } else {
                    printf("\nSe han acabado sus reintentos");
                }
                break;
            case 2:
                obtuveOperandoDos = utn_getNumeroFloat(&operandoDos,"Ingrese segundo operando: ","Error, debe ingresar un numero.\n", FLT_MIN, FLT_MAX,3);
                if (obtuveOperandoDos == EXITO) {
                    printf("\nIngresado con exito\n");
                } else {
                    printf("\nSe han acabado sus reintentos");
                }
                break;
            case 3:
                if (obtuveOperandoUno == EXITO && obtuveOperandoDos == EXITO)
                {
                    printf("Calculando...\n Prosiga.\n\n");
                    resultadoFuncionSumar = sumar(operandoUno, operandoDos, &resultadoSuma);
                    resultadoFuncionRestar = restar(operandoUno, operandoDos, &resultadoResta);
                    resultadoFuncionDividir = dividir(operandoUno, operandoDos, &resultadoDivision);
                    resultadoFuncionMultiplicar = multiplicar(operandoUno, operandoDos, &resultadoMultiplicacion);
                    resultadoFuncionFactorialUno = calcularFactorial(operandoUno, &resultadoFactorialUno);
                    resultadoFuncionFactorialDos = calcularFactorial(operandoDos, &resultadoFactorialDos);
                } else {
                    printf("\nDebe ingresar ambos operandos primero.\n");
                }
                break;
            case 4:
                if (obtuveOperandoUno == EXITO && obtuveOperandoDos == EXITO)
                {
                    //si obtuve operandos entonces pregunto si se pudo calcular en cada caso e imprimo resultado
                    printf("\nResultados:\n");
                    if (resultadoFuncionSumar == EXITO)
                    {
                        printf("\nLa suma de %.2f + %.2f es: %.2f", operandoUno, operandoDos, resultadoSuma);
                    } else {
                        printf("\nNo se pudo realizar la suma.");
                    }
                    if (resultadoFuncionRestar == EXITO)
                    {
                        printf("\nLa resta de %.2f - %.2f es: %.2f", operandoUno, operandoDos, resultadoResta);
                    } else {
                        printf("\nNo se pudo realizar la resta.");
                    }
                    if (resultadoFuncionDividir == EXITO)
                    {
                        printf("\nLa division de %.2f / %.2f es: %.2f",	operandoUno, operandoDos, resultadoDivision);
                    } else {
                        printf("\nNo se realizar la division. No se puede dividir por 0.");
                    }
                    if (resultadoFuncionMultiplicar == EXITO)
                    {
                        printf("\nLa multiplicacion de %.2f x %.2f es: %.2f", operandoUno, operandoDos, resultadoMultiplicacion);
                    } else {
                        printf("\nNo se pudo realizar la multiplicacion.");
                    }
                    if (resultadoFuncionFactorialUno == EXITO)
                    {
                        printf("\nEl factorial de: %d es %ld /",(int) operandoUno, resultadoFactorialUno);
                    } else {
                        printf("\nCon su primer operando: No se puede calcular el factorial de un numero negativo.\n");
                    }
                    if (resultadoFuncionFactorialDos == EXITO)
                    {
                        printf("El factorial de: %d es %ld\n", (int) operandoDos, resultadoFactorialDos);
                    } else {
                        printf("\nCon su segundo operando: No se puede calcular el factorial de un numero negativo.\n");
                    }

                } /**fin if obtuve operandos**/ else {
                    printf("\nDebe ingresar ambos operandos primero.\n");
                }
                break;
            case 5:
                printf("\nHasta luego!");
                break;
            }///fin switch
        } else {
            printf("\nSe han acabado sus reintentos.");
        }
    }
    while (opcion != 5);

    return 0;
}
