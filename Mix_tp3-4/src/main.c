#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"
#define ERROR -1
#define SUCCESS 0
#define FALSE 0
#define TRUE 1

int main()
{
	int option = 0;
	LinkedList *listaEmpleados = ll_newLinkedList();
	int result;
	int isSaved = FALSE;
	char bufferAnswer[10];

	do
	{
		if(utn_getNumber(&option,
							"\n\nIngrese una opcion: \n"
							"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
							"\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
							"\n3. Alta de empleado"
							"\n4. Modificar datos de empleado"
							"\n5. Baja de empleado"
							"\n6. Listar empleados"
							"\n7. Ordenar empleados"
							"\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
							"\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
							"\n10. SALIR\n\n","\nError! elija una opcion valida",1,10,5)==SUCCESS)
		{
			switch (option)
			{
				case 1:
					result = controller_loadFromText("data.csv", listaEmpleados);
					if (result == SUCCESS) {
						printf("\nArchivo cargado con exito!\n");
					} else if(result == -2){
						printf("\nNo se pudo abrir el archivo.\n");
					} else {
						printf("\nNombre de archivo incorrecto o direccion de memoria invalida.\n");
					}
					break;
				case 2:
					result = controller_loadFromBinary("data.bin", listaEmpleados);
					if (result == SUCCESS) {
						printf("\nArchivo cargado con exito!\n");
					} else if(result == -2){
						printf("\nNo se pudo abrir el archivo.\n");
					} else {
						printf("\nNombre de archivo incorrecto o direccion de memoria invalida.\n");
					}
					break;
				case 3:
					if(ll_isEmpty(listaEmpleados)==0)
					{
						if(controller_addEmployee(listaEmpleados) == SUCCESS) {
							printf("\nAlta realizada con exito!\n");
						} else {
							printf("\nNo pudo realizarse el alta.\n");
						}
					} else {
						printf("\nDebe cargar el archivo primero.\n");
					}
					break;
				case 4:
					if(ll_isEmpty(listaEmpleados)==0)
					{
						switch (controller_editEmployee(listaEmpleados)) {
						case SUCCESS:
							printf("\nModificacion realizada con exito!\n");
							break;
						case ERROR:
							printf("\nNo existen empleados con ese ID, o no ha hecho modificaciones. Vuelva a intentarlo.\n");
							break;
						case -2:
							printf("\nNo pudo realizar el cambio de nombre. Vuelva a intentarlo.\n");
							break;
						case -3:
							printf("\nNo pudo realizar el cambio de horas trabajadas. Vuelva a intentarlo.\n");
							break;
						case -4:
							printf("\nNo pudo realizar el cambio de sueldo. Vuelva a intentarlo.\n");
							break;
						}
					} else {
						printf("\nDebe cargar el archivo primero.\n");
					}
					break;
				case 5:
					if(ll_isEmpty(listaEmpleados)==0)
					{
						if(controller_removeEmployee(listaEmpleados) == SUCCESS) {
							printf("\nBaja realizada con exito!\n");
						} else {
							printf("\nNo se pudo realizar la baja.\n");
						}
					} else {
						printf("\nDebe cargar el archivo primero.\n");
					}
					break;
				case 6:
					if(ll_isEmpty(listaEmpleados)==0)
					{
						controller_ListEmployee(listaEmpleados);
					} else {
						printf("\nDebe cargar el archivo primero.\n");
					}
					break;
				case 7:
					ll_filter(listaEmpleados,employee_IdParImpar);
					/*
					if(ll_isEmpty(listaEmpleados)==0)
					{
						if(controller_sortEmployee(listaEmpleados)==SUCCESS)
						{
							printf("\nOrdenado con exito!\n");
						} else {
							printf("\nNo se pudo realizar el ordenamiento.\n");
						}
					} else {
						printf("\nDebe cargar el archivo primero.\n");
					}*/
					break;
				case 8:
					if(ll_isEmpty(listaEmpleados)==0)
					{
						result = controller_saveAsText("dataTexto.csv", listaEmpleados);
						if (result == SUCCESS) {
							printf("\nArchivo guardado con exito!\n");
							isSaved = TRUE;
						} else if(result == -2){
							printf("\nNo se pudo guardar.\n");
						} else {
							printf("\nError. Direccion de memoria invalida.\n");
						}
					} else {
						printf("\nDebe cargar el archivo primero.\n");
					}
					break;
				case 9:
					if(ll_isEmpty(listaEmpleados)==0)
					{
						result = controller_saveAsBinary("dataBin.bin", listaEmpleados);
						if (result == SUCCESS) {
							printf("\nArchivo guardado con exito!\n");
							isSaved = TRUE;
						} else if(result == -2){
							printf("\nNo se pudo guardar.\n");
						} else {
							printf("\nError. Direccion de memoria invalida.\n");
						}
					} else {
						printf("\nDebe cargar el archivo primero.\n");
					}
					break;
				case 10:
					if(isSaved == TRUE)
					{
						ll_clear(listaEmpleados);
						ll_deleteLinkedList(listaEmpleados);
						printf("\nHasta luego!\n");
					} else if(ll_isEmpty(listaEmpleados)==1) {
						printf("\nNo ha realizado nada en el programa. Adios\n");
					} else if (isSaved == FALSE){
						printf("\nDebe guardar el archivo primero. Desea hacerlo?\n");
						if(utn_getName(bufferAnswer, 10, "\nDebe ingresar 'Si' para volver al menu y hacerlo: ", "\nError,ingrese una respuesta valida.", 3) == SUCCESS
												&& strncasecmp(bufferAnswer, "si", 10) == 0) {
							option = 0;
						} else {
							printf("\nHa decidido no guardar el archivo.\nHasta luego!\n");
							option = 10;
						}
					}
					break;
			}
		}
	} while (option != 10);
	return 0;
}
