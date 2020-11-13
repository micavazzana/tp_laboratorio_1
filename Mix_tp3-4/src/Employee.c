#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validations.h"
#define ERROR -1
#define SUCCESS 0

/*
 * \brief Pide memoria para un nuevo empleado
 * \param void
 * \return int Return puntero con espacio de memoria con tipo Employee*
 */
Employee* employee_new(void)
{
	return (Employee*) malloc(sizeof(Employee));
}

/*
 * \brief Pide memoria para un nuevo empleado y setea los campos en el espacio de memoria requerido
 * \param idStr char* id que va a setear
 * \param nameStr char* nombre que va a setear
 * \param workedHoursStr char* horas trabajadas que va a setear
 * \param salaryStr char* sueldo que va a setear
 * \return int Return puntero con espacio de memoria con tipo Employee* con los campos ya seteados
 */
Employee* employee_newParametros(char* idStr,char* nameStr,char* workedHoursStr, char* salaryStr)
{
	Employee* pEmployee = NULL;

	if (idStr != NULL && nameStr != NULL && workedHoursStr != NULL && salaryStr != NULL)
	{
		pEmployee = employee_new();
		if (pEmployee != NULL)
		{
			employee_setNombre(pEmployee,nameStr);
			employee_setHorasTrabajadasTxt(pEmployee,workedHoursStr);
			employee_setSueldoTxt(pEmployee,salaryStr);
			employee_setIdTxt(pEmployee,idStr);
		}
	}
	return pEmployee;
}

/*
 * \brief Libera espacio de memoria de un empleado
 * \param this Employee* puntero a empleado
 * \return -1 void
 */
void employee_delete(Employee* this)
{
	free(this);
}

/*
 * \brief Carga el id en el campo del empleado
 * \param this Employee* puntero a empleado
 * \param id int id a cargar
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si el id no es valido
 * 					  (0) EXITO
 */
int employee_setId(Employee* this, int id)
{
	int result = ERROR;
	if (this != NULL && id >= 0)
	{
		this->id = id;
		result = SUCCESS;
	}
	return result;
}

/*
 * \brief Obtiene el id del empleado
 * \param this Employee* puntero a empleado
 * \param id int* puntero al espacio donde va a guardar el id obtenido
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero al id es NULL
 * 					  (0) EXITO
 */
int employee_getId(Employee* this, int* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        result = SUCCESS;
    }
    return result;
}

/*
 * \brief Carga el id en el campo del empleado (tratado como texto) y valida que el dato sea correcto
 * \param this Employee* puntero a empleado
 * \param id char* puntero al id que va a cargar
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero al id es NULL
 * 					  (0) EXITO
 */
int employee_setIdTxt(Employee* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL && isValidNumber(id, sizeof(id)))
    {
        this->id = atoi(id);
        result = SUCCESS;
    }
    return result;
}

/*
 * \brief Obtiene el id del empleado (tratado como texto)
 * \param this Employee* puntero a empleado
 * \param id char* puntero al espacio donde va a guardar el id obtenido
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero al id es NULL
 * 					  (0) EXITO
 */
int employee_getIdTxt(Employee* this, char* id)
{
    int result = ERROR;
    if (this != NULL && id != NULL)
    {
        sprintf(id, "%d", this->id);
        result = SUCCESS;
    }
    return result;
}

/*
 * \brief Carga el nombre en el campo del empleado y valida que el dato sea correcto
 * \param this Employee* puntero a empleado
 * \param name char* puntero al nombre que va a cargar
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero al nombre es NULL
 * 					  (0) EXITO
 */
int employee_setNombre(Employee *this, char* name)
{
	int result = ERROR;
	if (this != NULL && name != NULL && isValidCompoundName(name, NAME_LEN))
	{
		strncpy(this->nombre, name, NAME_LEN);
		result = SUCCESS;
	}
	return result;
}

/*
 * \brief Obtiene el nombre del empleado
 * \param this Employee* puntero a empleado
 * \param name char* puntero al espacio donde va a guardar el nombre obtenido
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero al id es NULL
 * 					  (0) EXITO
 */
int employee_getNombre(Employee* this, char* name)
{
    int result = ERROR;
    if (this != NULL && name != NULL)
    {
        strncpy(name, this->nombre, NAME_LEN);
        result = SUCCESS;
    }
    return result;
}

/*
 * \brief Carga las horas trabajadas en el campo del empleado
 * \param this Employee* puntero a empleado
 * \param workedHours int horas trabajadas a cargar
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si el valor no es valido
 * 					  (0) EXITO
 */
int employee_setHorasTrabajadas(Employee* this, int workedHours)
{
	int result = ERROR;
	if(this != NULL && workedHours > 0)
	{
		this->horasTrabajadas = workedHours;
		result = SUCCESS;
	}
	return result;
}

/*
 * \brief Obtiene las horas trabajadas del empleado
 * \param this Employee* puntero a empleado
 * \param workedHours int* puntero al espacio donde va a guardar las horas trabajadas obtenidas
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero al entero es NULL
 * 					  (0) EXITO
 */
int employee_getHorasTrabajadas(Employee* this, int* workedHours)
{
    int result = ERROR;
    if (this != NULL && workedHours != NULL)
    {
        *workedHours = this->horasTrabajadas;
        result = SUCCESS;
    }
    return result;
}

/*
 * \brief Carga las horas trabajadas en el campo del empleado (tratado como texto) y valida que el dato sea correcto
 * \param this Employee* puntero a empleado
 * \param workedHours char* puntero a las horas trabajadas que va a guardar
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero al id es NULL
 * 					  (0) EXITO
 */
int employee_setHorasTrabajadasTxt(Employee* this, char* workedHours)
{
    int result = ERROR;
    if (this != NULL && workedHours != NULL && isValidNumber(workedHours, sizeof(workedHours)))
    {
        this->horasTrabajadas = atoi(workedHours);
        result = SUCCESS;
    }
    return result;
}

/*
 * \brief Obtiene las horas trabajadas del empleado (tratado como texto)
 * \param this Employee* puntero a empleado
 * \param workedHours char* puntero al espacio donde va a guardar las horas trabajadas obtenidas
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero a las horas trabajadas es NULL
 * 					  (0) EXITO
 */
int employee_getHorasTrabajadasTxt(Employee* this, char* workedHours)
{
    int result = ERROR;
    if (this != NULL && workedHours != NULL)
    {
        sprintf(workedHours, "%d", this->horasTrabajadas);
        result = SUCCESS;
    }
    return result;
}

/*
 * \brief Carga el sueldo en el campo del empleado
 * \param this Employee* puntero a empleado
 * \param salary float sueldo a cargar
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si el valor no es valido
 * 					  (0) EXITO
 */
int employee_setSueldo(Employee* this, float salary)
{
	int result = ERROR;
	if(this != NULL && salary > 0)
	{
		this->sueldo = salary;
		result = SUCCESS;
	}
	return result;
}

/*
 * \brief Obtiene el sueldo del empleado
 * \param this Employee* puntero a empleado
 * \param salary float* puntero al espacio donde va a guardar el sueldo obtenido
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero al flotante es NULL
 * 					  (0) EXITO
 */
int employee_getSueldo(Employee* this, float* salary)
{
    int result = ERROR;
    if (this != NULL && salary != NULL)
    {
        *salary = this->sueldo;
        result = SUCCESS;
    }
    return result;
}

/*
 * \brief Carga el sueldo en el campo del empleado (tratado como texto) y valida que el dato sea correcto
 * \param this Employee* puntero a empleado
 * \param salary char* puntero al sueldo que va a guardar
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero al sueldo es NULL
 * 					  (0) EXITO
 */
int employee_setSueldoTxt(Employee* this, char* salary)
{
    int result = ERROR;
    if (this != NULL && salary != NULL && isValidNumberFloat(salary, sizeof(salary)))
    {
        this->sueldo = atof(salary);
        result = SUCCESS;
    }
    return result;
}

/*
 * \brief Obtiene el sueldo del empleado (tratado como texto)
 * \param this Employee* puntero a empleado
 * \param salary char* puntero al espacio donde va a guardar el sueldo obtenido
 * \return int Return (-1) ERROR - Si el puntero a Employee* es NULL o si e puntero al sueldo es NULL
 * 					  (0) EXITO
 */
int employee_getSueldoTxt(Employee* this, char* salary)
{
    int result = ERROR;
    if (this != NULL && salary != NULL)
    {
        sprintf(salary, "%.2f", this->sueldo);
        result = SUCCESS;
    }
    return result;
}

/*
 * \brief Compara los nombres de dos empleados
 * \param void* puntero al primer empleado a comparar
 * \param void* puntero al segundo empleado a comparar
 * \return int Return (-2) Error
 * 					  (-1) Si el nombre del primer empleado es menor al segundo
 * 					   (1) Si el nombre del primer empleado es mayor al segundo
 * 					   (0) Si los nombres son iguales
 */
int employee_compareByName(void* firstEmployee, void* SecondEmployee)
{
	int result = -2;
	char bufferFirstEmployee[NAME_LEN];
	char bufferSecondEmployee[NAME_LEN];
	int strCompare;

	if(firstEmployee != NULL && SecondEmployee != NULL)
	{
		employee_getNombre((Employee*)firstEmployee,bufferFirstEmployee);
		employee_getNombre((Employee*)SecondEmployee,bufferSecondEmployee);
		strCompare = strncasecmp(bufferFirstEmployee, bufferSecondEmployee, NAME_LEN);
		if(strCompare > 0)
		{
			result = 1;
		} else if (strCompare < 0) {
			result = -1;
		} else {
			result = 0;
		}
	}
	return result;
}

/*
 * \brief Compara la cantidad de horas trabajadas de dos empleados
 * \param void* puntero al primer empleado a comparar
 * \param void* puntero al segundo empleado a comparar
 * \return int Return (-2) Error
 *					  (-1) Si la cantidad de horas trabajadas del primer empleado es menor al segundo
 * 					   (1) Si la cantidad de horas trabajadas del primer empleado es mayor al segundo
 * 					   (0) Si la cantidad de horas trabajadas son iguales
 */
int employee_compareByWorkedHours(void* firstEmployee, void* SecondEmployee)
{
	int result = -2;
	int bufferFirstEmployee;
	int bufferSecondEmployee;

	if(firstEmployee != NULL && SecondEmployee != NULL)
	{
		employee_getHorasTrabajadas((Employee*)firstEmployee,&bufferFirstEmployee);
		employee_getHorasTrabajadas((Employee*)SecondEmployee,&bufferSecondEmployee);
		if(bufferFirstEmployee > bufferSecondEmployee)
		{
			result = 1;
		} else if (bufferFirstEmployee < bufferSecondEmployee) {
			result = -1;
		} else {
			result = 0;
		}
	}
	return result;
}

/*
 * \brief Compara los sueldos de dos empleados
 * \param void* puntero al primer empleado a comparar
 * \param void* puntero al segundo empleado a comparar
 * \return int Return (-2) Error
 * 					  (-1) Si el sueldo del primer empleado es menor al segundo
 * 					   (1) Si el sueldo del primer empleado es mayor al segundo
 * 					   (0) Si los sueldos son iguales
 */
int employee_compareBySalary(void* firstEmployee, void* SecondEmployee)
{
	int result = -2;
	float bufferFirstEmployee;
	float bufferSecondEmployee;

	if(firstEmployee != NULL && SecondEmployee != NULL)
	{
		employee_getSueldo((Employee*)firstEmployee,&bufferFirstEmployee);
		employee_getSueldo((Employee*)SecondEmployee,&bufferSecondEmployee);
		if(bufferFirstEmployee > bufferSecondEmployee)
		{
			result = 1;
		} else if (bufferFirstEmployee < bufferSecondEmployee) {
			result = -1;
		} else {
			result = 0;
		}
	}
	return result;
}

/*
 * \brief Compara los id de dos empleados
 * \param void* puntero al primer empleado a comparar
 * \param void* puntero al segundo empleado a comparar
 * \return int Return (-2) Error
 * 					  (-1) Si el id del primer empleado es menor al segundo
 * 					   (1) Si el id del primer empleado es mayor al segundo
 * 					   (0) Si los id son iguales
 */
int employee_compareById(void* firstEmployee, void* SecondEmployee)
{
	int result = -2;
	int bufferFirstEmployee;
	int bufferSecondEmployee;

	if(firstEmployee != NULL && SecondEmployee != NULL)
	{
		employee_getId((Employee*)firstEmployee,&bufferFirstEmployee);
		employee_getId((Employee*)SecondEmployee,&bufferSecondEmployee);
		if(bufferFirstEmployee > bufferSecondEmployee)
		{
			result = 1;
		} else if (bufferFirstEmployee < bufferSecondEmployee) {
			result = -1;
		} else {
			result = 0;
		}
	}
	return result;
}

int employee_IdParImpar(void* pEmployee)
{
	int retorno=-1;
	int id;
	if(pEmployee!=NULL)
	{
		employee_getId((Employee*)pEmployee,&id);
		if(!(id % 2))
		{
			retorno=1;//true
		}
		else
		{
			retorno=0;//false
		}
	}
	return retorno;
}
