#include <stdio.h>
#include <stdlib.h>
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
					if (controller_loadFromText("data.csv", listaEmpleados) == SUCCESS) {
						printf("\nArchivo cargado con exito!\n");
					} else if(result == -2){
						printf("\nNo se pudo abrir el archivo.\n");
					} else {
						printf("\nNombre de archivo incorrecto o direccion de memoria invalida.\n");
					}
					break;
				case 2:
					if ((result = controller_loadFromBinary("data.csv", listaEmpleados) == SUCCESS)) {
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
					}
					break;
				case 8:
					if(ll_isEmpty(listaEmpleados)==0)
					{
						if (controller_saveAsText("dataComoTexto.csv", listaEmpleados) == SUCCESS) {
							printf("\nArchivo guardado con exito!\n");
							isSaved = TRUE;
						} else {
							printf("\nNo se pudo guardar.\n");
						}
					} else {
						printf("\nDebe cargar el archivo primero.\n");
					}
					break;
				case 9:
					if(ll_isEmpty(listaEmpleados)==0)
					{
						if (controller_saveAsBinary("dataComoBinario.csv", listaEmpleados) == SUCCESS) {
							printf("\nArchivo guardado con exito!\n");
							isSaved = TRUE;
						} else {
							printf("\nNo se pudo guardar.\n");
						}
					} else {
						printf("\nDebe cargar el archivo primero.\n");
					}
					break;
				case 10:
					if(isSaved == TRUE)
					{
						//ll_clear // libero la memoria con delete y con clear borro los punteros a la lista?
						ll_deleteLinkedList(listaEmpleados);
						printf("\nHasta luego!\n");
					} else if(ll_isEmpty(listaEmpleados)==1) {

					} else if (isSaved == FALSE){
						printf("\nDebe guardar el archivo primero.\n");
						option = 0;
					}
					break;
			}
		}
	} while (option != 10);
	return 0;
}
