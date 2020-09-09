/*
 * inputs.c
 *
 *  Created on: 8 sep. 2020
 *      Author: micavazzana
 */
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 0
#define ERROR -1

int utn_getNumero(int *pOutcome, char *message, char *messageError, int min, int max, int retries)
{
    int Return = ERROR;
    int bufferInt;

    if(pOutcome != NULL && retries>0 && min < max && max > min)
    {
        while(retries > 0)
        {
            printf("%s",message);
            scanf("%d",&bufferInt);

            if(bufferInt < min || bufferInt > max)//falta contemplar que no ingrese algo distinto a numeros
            {
                printf("%s",messageError);
                retries--;
            }
            else
            {
                *pOutcome = bufferInt;
                Return = SUCCESS;
                break;
            }
        }
    }

    return Return;
}



int utn_getNumeroFloat(float *pOutcome, char *message, char *messageError, int min, int max, int retries)
{
	int Return = ERROR;
	float bufferFloat;

	if(pOutcome != NULL && retries > 0 && min < max && max > min)
	{
		while (retries > 0)
		{
			printf("%s", message);
			scanf("%f", &bufferFloat);

			if(bufferFloat < min || bufferFloat > max) //falta contemplar que no ingrese algo distinto a numeros
			{
				printf("%s", messageError);
				retries--;

			}
			else
			{
				*pOutcome = bufferFloat;
				Return = SUCCESS;
				break;
			}
		}
	}

	return Return;
}

int utn_getChar(char *pOutcome, char *message, char *messageError, int retries)
{
    int Return = ERROR;
    char auxChar;

        while(retries > 0)
        {

            printf("%s",message);
            fpurge(stdin);
            scanf("%c",&auxChar);

            if((auxChar < 'a' || auxChar > 'z') && (auxChar < 'A' || auxChar > 'Z'))
            {
                printf("%s",messageError);
                retries--;
            }
            else
            {
                *pOutcome = auxChar;
                Return = SUCCESS;
                break;
            }
        }

    return Return;
}


int utn_getOptionMenu(int *pOption, float operandoUno, float operandoDos, int min, int max, int retries) {

	int Return = ERROR;
	int bufferInt;
	int resultadoScan;

	if (pOption != NULL && retries > 0 && min < max && max > min) {
		while (retries > 0) {

			printf("\nMenu\n"
					"\n1. Ingresar primer operando:  %.2f"
					"\n2. Ingresar segundo operando: %.2f"
					"\n3. Calcular todas las operaciones"
					"\n4. Informar resultados"
					"\n5. Salir"
					"\n\nElija una opcion: ", operandoUno, operandoDos);
			scanf("%d", &bufferInt);

			if (bufferInt < min || bufferInt > max) //revisar que no ingrese algo distinto a numeros
					{
				printf("Error! Elija una opcion valida");
				retries--;
			} else {
				*pOption = bufferInt;
				Return = SUCCESS;
				break;
			}

		}
	}

	return Return;
}
