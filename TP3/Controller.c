#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "inputs.h"
#include "Controller.h"
#define ERROR -1
#define SUCCESS 0

static int findMaxId(LinkedList* pArrayListEmployee);
static int generateNewId(LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL)
		{
			result = parser_EmployeeFromText(pFile, pArrayListEmployee); //parser_Employee returns 0 if Ok
			fclose(pFile);
		} else {
			result = -2; //couldn't open the file
		}
	}
	return result;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "rb");
		if (pFile != NULL)
		{
			result = parser_EmployeeFromBinary(pFile, pArrayListEmployee);//parser_Employee returns 0 if Ok
			fclose(pFile);
		} else {
			result = -2; //couldn't open the file
		}
	}
	return result;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	Employee* pEmployee;
	Employee buffer;

	if (pArrayListEmployee != NULL)
	{
		pEmployee = employee_new();
		if(pEmployee != NULL
			&& utn_getName(buffer.nombre,sizeof(buffer.nombre),"Ingrese nombre: ","Error", 3) == SUCCESS
			&& utn_getNumber(&buffer.horasTrabajadas,"Ingrese horas trabajadas: ","Error", 0, 5000, 3) == SUCCESS
			&& utn_getFloatNumber(&buffer.sueldo,"Ingrese sueldo: ","Error", 0, 100000, 3) == SUCCESS)
		{
			buffer.id = generateNewId(pArrayListEmployee);
			if (employee_setNombre(pEmployee, buffer.nombre) == SUCCESS
					&& employee_setHorasTrabajadas(pEmployee, buffer.horasTrabajadas) == SUCCESS
					&& employee_setSueldo(pEmployee, buffer.sueldo) == SUCCESS
					&& employee_setId(pEmployee,buffer.id) == SUCCESS)
			{
				result = ll_add(pArrayListEmployee, pEmployee);
			}
		}
	}
	return result;
}

/** \brief Buscar empleado por id
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int id buscado
 * \return int indice encontrado o (-1) si el puntero a LikedList es NULL, id invalido o empleado no encontrado
 *
 */
int controller_findById(LinkedList* pArrayListEmployee, int id)
{
	int result = ERROR;
	int i;
	int bufferId;
	int len;
	Employee* pEmployee;

	if (pArrayListEmployee != NULL && id > 0)
	{
		len = ll_len(pArrayListEmployee);
		for (i = 0; i < len; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			if (pEmployee != NULL
					&& employee_getId(pEmployee, &bufferId) == SUCCESS
					&& bufferId == id)
			{
				result = i;
				break;
			}
		}
	}
	return result;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	Employee* pEmployee;
	Employee buffer;
	int index;
	int option;

	if (pArrayListEmployee != NULL)
	{
		if (controller_ListEmployee(pArrayListEmployee) == SUCCESS
				&& utn_getNumber(&buffer.id, "\nIngrese el id del empleado que quiere modificar: ", "\nError!", 0, INT_MAX, 5) == SUCCESS)
		{
			index = controller_findById(pArrayListEmployee, buffer.id); //que hace exactamente el ll_indexOf??
			if (index != ERROR)
			{
				pEmployee = (Employee*) ll_get(pArrayListEmployee, index);
				if (pEmployee != NULL)
				{
					do {
						if (utn_getNumber(&option, "\n\nIngrese una opcion: "
								"\n1.Modificar Nombre "
								"\n2.Modificar Horas trabajadas "
								"\n3.Modificar Sueldo "
								"\n4.Volver al menu principal\n",
								"Error, elija una opcion valida\n", 1, 4, 3) == SUCCESS)
						{
							switch (option)
							{
							case 1:
								if (utn_getName(buffer.nombre, NAME_LEN, "\nIngrese nuevo nombre: ", "\nError!", 3) == SUCCESS)
								{
									employee_setNombre(pEmployee, buffer.nombre);
									result = SUCCESS;
								} else {
									result = -2;
								}
								break;
							case 2:
								if (utn_getNumber(&buffer.horasTrabajadas, "\nIngrese nueva cantidad de horas trabajadas: ", "\nError!", 0, 5000, 3) == SUCCESS)
								{
									employee_setHorasTrabajadas(pEmployee, buffer.horasTrabajadas);
									result = SUCCESS;
								} else {
									result = -3;
								}
								break;
							case 3:
								if (utn_getFloatNumber(&buffer.sueldo, "\nIngrese nuevo sueldo: ", "\nError!", 0, 100000, 3) == SUCCESS)
								{
									employee_setSueldo(pEmployee, buffer.sueldo);
									result = SUCCESS;
								} else {
									result = -4;
								}
								break;
							} //fin switch
						} else {
							printf("Se acabaron sus reintentos, vuelva a ingresar");
						}
						if (result < 0) {
							break;
						}
					} while (option != 4);
				}
			}
		}
	}
	return result;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	int index;
	int bufferId;
	Employee* pEmployee;
	char bufferAnswer[10];

	if (pArrayListEmployee != NULL)
	{
		if (controller_ListEmployee(pArrayListEmployee) == SUCCESS
			&& utn_getNumber(&bufferId , "\nIngrese el id del empleado que quiere eliminar: ", "\nError!", 0, INT_MAX, 5) == SUCCESS)
		{
			index = controller_findById(pArrayListEmployee, bufferId);
			if(index != ERROR)
			{
				pEmployee = (Employee*)ll_get(pArrayListEmployee, index);
				if (pEmployee != NULL
						&& utn_getName(bufferAnswer, 10, "\n\nDesea borrar? Debe ingresar 'Si' para proceder con la baja: ",
								"\nError,ingrese una respuesta valida.", 3) == SUCCESS
						&& strncasecmp(bufferAnswer, "si", 10) == 0)
				{
					employee_delete(pEmployee);
					result = ll_remove(pArrayListEmployee,index);
				}
			}
		}
	}
	return result;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int result = ERROR;
    int len;
    int i;

    if(pArrayListEmployee != NULL)
    {
    	len = ll_len(pArrayListEmployee);
    	printf("\n%10s %15s %15s %15s\n","ID","NOMBRE","HORAS TRABAJADAS","SUELDO\n");
    	for(i=0;i<len;i++)
    	{
    		result = controller_printOneEmployee(pArrayListEmployee,i);
    	}
    }
	return result;
}

int controller_printOneEmployee(LinkedList* pArrayListEmployee, int index)
{
	int result = ERROR;
	Employee buffer;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && index >= 0)
	{
		pEmployee = (Employee*)ll_get(pArrayListEmployee,index);
		if(	pEmployee != NULL
				&& employee_getId(pEmployee, &buffer.id) == SUCCESS
				&& employee_getNombre(pEmployee, buffer.nombre) == SUCCESS
				&& employee_getHorasTrabajadas(pEmployee, &buffer.horasTrabajadas) == SUCCESS
				&& employee_getSueldo(pEmployee, &buffer.sueldo) == SUCCESS)
		{
			printf("\n%10d %15s %15d %15.2f\n",
					buffer.id,
					buffer.nombre,
					buffer.horasTrabajadas,
					buffer.sueldo);
					result = SUCCESS;
		}
	}
	return result;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	int order;
	int option;

	if (pArrayListEmployee != NULL)
	{
		do {
			if (utn_getNumber(&option, "\n\nIngrese una opcion: "
					"\n1.Ordenar por Nombre "
					"\n2.Ordenar por Horas trabajadas "
					"\n3.Ordenar por Sueldo "
					"\n4.Ordenar por Id"
					"\n5.Volver al menu principal\n",
					"Error, elija una opcion valida\n", 1, 5, 3) == SUCCESS)
			{
				switch (option)
				{
				case 1:
					if(utn_getNumber(&order,"\nIngrese el criterio con el que desea ordenar [1-ASCENDENTE/0-DESCEDENTE]: ","\nError, debe ingresar o 0 o 1",0,1,3)==SUCCESS)
					{
						result = ll_sort(pArrayListEmployee, employee_compareByName,order);
					}
					break;
				case 2:
					if(utn_getNumber(&order,"\nIngrese el criterio con el que desea ordenar [1-ASCENDENTE/0-DESCEDENTE]: ","\nError, debe ingresar o 0 o 1",0,1,3)==SUCCESS)
					{
						result = ll_sort(pArrayListEmployee, employee_compareByWorkedHours,order);
					}
					break;
				case 3:
					if(utn_getNumber(&order,"\nIngrese el criterio con el que desea ordenar [1-ASCENDENTE/0-DESCEDENTE]: ","\nError, debe ingresar o 0 o 1",0,1,3)==SUCCESS)
					{
						result = ll_sort(pArrayListEmployee, employee_compareBySalary,order);
					}
					break;
				case 4:
					if(utn_getNumber(&order,"\nIngrese el criterio con el que desea ordenar [1-ASCENDENTE/0-DESCEDENTE]: ","\nError, debe ingresar o 0 o 1",0,1,3)==SUCCESS)
					{
						result = ll_sort(pArrayListEmployee, employee_compareById,order);
					}
					break;
				} //fin switch
			} else {
				printf("Se acabaron sus reintentos, vuelva a ingresar");
			}
		} while (option != 5);
	}
	return result;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");
		if (pFile != NULL)
		{
			result = parser_EmployeeToText(pFile, pArrayListEmployee); //parser_Employee returns 0 if Ok
			fclose(pFile);
		} else {
			result = -2; //couldn't open the file
		}
	}
	return result;
}

/** \brief Guarda los datos de los empleados en el archivo que recibe como parametro (modo binario).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero al array
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int result = ERROR;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");
		if (pFile != NULL)
		{
			result = parser_EmployeeToBinary(pFile, pArrayListEmployee); //parser_Employee returns 0 if Ok
			fclose(pFile);
		} else {
			result = -2; //couldn't open the file
		}
	}
	return result;
}

/**
 * \brief
 * \param
 * \return int Return
 */
static int findMaxId(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int len;
	int i;
	int max;
	int id = ERROR;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		for(i=0;i<len;i++)
		{
			pEmployee = ll_get(pArrayListEmployee,i);
			employee_getId(pEmployee,&id);
			if (i == 0 || id > max)
			{
				max = id;
			}
		}
		id = max;
	}
	return id;
}

/**
 * \brief Generates a new id for a new client,
 * \param void
 * \return int Return value of the new id
 */
static int generateNewId(LinkedList* pArrayListEmployee)
{
    static int id = ERROR;
    static int flag = 1;

    if(pArrayListEmployee != NULL)
    {
		if(flag == 1)//only once, the first time after opening the file
		{
			id = findMaxId(pArrayListEmployee);
			flag++;
		}
		id++;
    }
    return id;
}
