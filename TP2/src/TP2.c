/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ArrayEmployees.h"
#include "inputs.h"
#define QTY_EMPLOYEE 15//cambiar por 1000 cuando termine el testeo

int main(void) {

	int option;
	Employee listEmployees[QTY_EMPLOYEE];
	int id = 1;
	int bufferId;

	if(initEmployees(listEmployees,QTY_EMPLOYEE)==SUCCESS)
	{
		hardCodeData(listEmployees,&id);
		do
		{
			if(utn_getNumber(&option,"\n\nIngrese una opcion: "
					"\n1.Alta "
					"\n2.Modificacion "
					"\n3.Baja "
					"\n4.Informar"
					"\n5.SALIR\n",
					"Error, elija una opcion valida\n", 1, 5, 3)==SUCCESS)
			{
				switch(option)
				{
				case 1:
					if(loadUpEmployee(listEmployees, QTY_EMPLOYEE,&id) == SUCCESS)
					{
						printf("\nCarga realizada con exito\n");
					} else {
						printf("\nYa no hay lugar!\n");
					}
					break;
				case 2:
					if(isAnyData(listEmployees,QTY_EMPLOYEE)==TRUE)//checks that there is data loaded
					{
						printEmployees(listEmployees, QTY_EMPLOYEE);
						if(utn_getNumber(&bufferId,"\n\nIngrese el id del empleado que quiere modificar: ","\nError",0,INT_MAX,3)==SUCCESS &&
								modifyEmployee(listEmployees, QTY_EMPLOYEE,bufferId) == SUCCESS)
						{
							printf("\nModificacion realizada con exito\n");
						} else {
							printf("\nNo se puedo realizar la modificacion. No existen cargas con ese id\n");
						}
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 3:
					if(isAnyData(listEmployees,QTY_EMPLOYEE)==TRUE)//checks that there is data loaded
					{
						printEmployees(listEmployees, QTY_EMPLOYEE);
						if(utn_getNumber(&bufferId,"\n\nIngrese el id del empleado que quiere eliminar: ","\nError",0,INT_MAX,3)==SUCCESS &&
								removeEmployee(listEmployees, QTY_EMPLOYEE,bufferId) == SUCCESS)
						{
							printf("\nBaja realizada con exito\n");
						} else {
							printf("\nNo se puedo realizar la baja. No existen cargas con ese id\n");
						}
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 4:
					if(isAnyData(listEmployees,QTY_EMPLOYEE)==TRUE)//checks that there is data loaded
					{
						inform(listEmployees,QTY_EMPLOYEE);
					} else {
						printf("\nDebe cargar datos primero");
					}
					break;
				case 5:
					printf("\nHasta luego!\n");
					break;
				}
			}
		}while(option!=5);
	} else {
		printf("\nERROR!! No se pudo iniciar el programa\n");//ERROR, could not initialize the array
	}
	return EXIT_SUCCESS;
}
