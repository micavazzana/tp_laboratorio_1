#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
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
			result = -2; //couldn't open the file or the file doesn't exist
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
			result = -2; //couldn't open the file or the file doesn't exist
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
	//index?el add agrega en un nuevo nodo, no necesita buscar un index libre

	if (pArrayListEmployee != NULL)
	{
		pEmployee = employee_new();
		if(pEmployee != NULL
			&& utn_getName(buffer.nombre,sizeof(buffer.nombre),"ingrese nombre","error",3) == SUCCESS
			&& utn_getNumber(&buffer.horasTrabajadas,"ingrese horas trabajadas","error",0,5000,3) == SUCCESS
			&& utn_getNumberFloat(&buffer.sueldo,"ingrese sueldo","error",0,100000,3) == SUCCESS)
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
			employee_getId(pEmployee, &bufferId);
			if (pEmployee != NULL && bufferId == id)
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
		if (//imprimo listado: controller_ListEmployee(pArrayListEmployee) == SUCCESS
			&& utn_getNumber(&buffer.id, "\nIngrese el id del empleado que quiere modificar: ", "\nError!", 0, INT_MAX, 5) == SUCCESS
			&& (index = controller_findById(pArrayListEmployee, buffer.id) != ERROR))
		{
			pEmployee = ll_get(pArrayListEmployee, index);
			if (pEmployee != NULL)
			{
				do
				{
					if (utn_getNumber(&option,
									  "\n\nIngrese una opcion: "
									  "\n1.Modificar Nombre "
									  "\n2.Modificar Horas trabajadas "
									  "\n3.Modificar Sueldo "
									  "\n4.Volver al menu principal\n",
									  "Error, elija una opcion valida\n", 1, 4, 3) == SUCCESS)
					{
						switch (option)
						{
						case 1:
							if (utn_getName(buffer.nombre, sizeof(buffer.nombre), "\nIngrese nuevo nombre: ", "\nError!", 3) == SUCCESS)
							{
								employee_setNombre(pEmployee, buffer.nombre);
								result = SUCCESS;
							}
							else
							{
								result = -2;
							}
							break;
						case 2:
							if (utn_getNumber(buffer.horasTrabajadas, "\nIngrese nuevas horas trabajads: ", "\nError!",0,5000, 3) == SUCCESS)
							{
								employee_setHorasTrabajadas(pEmployee, buffer.horasTrabajadas);
								result = SUCCESS;
							}
							else
							{
								result = -3;
							}
							break;
						case 3:
							if (utn_getNumberFloat(buffer.sueldo, "\nIngrese nuevo sueldo: ", "\nError!",0,100000, 3) == SUCCESS)
							{
								employee_setSueldo(pEmployee, buffer.sueldo);
								result = SUCCESS;
							}
							else
							{
								result = -4;
							}
							break;
						} //fin switch
					}
					else
					{
						printf("Se acabaron sus reintentos, vuelva a ingresar");
					}
					if (result < 0)
					{
						break;
					}
				} while (option != 4);
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

	if (pArrayListEmployee != NULL)
	{
		if (//imprimo listado: controller_ListEmployee(pArrayListEmployee) == SUCCESS
			&& utn_getNumber(&bufferId, "\nIngrese el id del empleado que quiere eliminar: ", "\nError!", 0, INT_MAX, 5) == SUCCESS
			&& (index = controller_findById(pArrayListEmployee, bufferId) != ERROR))
		{
			pEmployee = ll_get(pArrayListEmployee, index);
			if (pEmployee != NULL)
			{
				//pregunto si quiere hacer la baja - si la confirma:
				result = ll_remove(pArrayListEmployee,index);//elimino del array, y me faltaria el espacio de memoria / pEmployee?
			}
		}

	}
	return result;
}

//DESARROLLAR controller_printOneEmployee(LinkedList* pArrayListEmployee)

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
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
    return 1;
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
			result = -2; //couldn't open the file or the file doesn't exist
		}
	}
	return result;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
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
			result = -2; //couldn't open the file or the file doesn't exist
		}
	}
	return result;
}

/**
 * \brief Generates a new id for a new client,
 * \param void
 * \return int Return value of the new id
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
			//obtener los id del listado //
			pEmployee = ll_get(pArrayListEmployee,i);
			//employee_getId //me lo guardo en id
			employee_getId(pEmployee,&id);
			//buscar el maximo
			if (i == 0 || id > max)
			{
				max = id;
			}
		}
		id = max + 1;
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
