/*
 * ArrayEmployees.h
 *
 *  Created on: 25 sep. 2020
 *      Author: micavazzana
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define NAME_LEN 51
#define SUCCESS 0
#define ERROR -1
#define TRUE 1
#define FALSE 0

struct
{
	int id;
	char name[NAME_LEN];
	char lastName[NAME_LEN];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;

/**
 * \brief To indicate that all position in the array are empty,
 * 		  this function put the flag (isEmpty) in TRUE in all position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list, int len);

/**
 * \brief Searches for an empty index in the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return value of the first empty index found -
 * 			   or (-1) if Error [Invalid length or NULL pointer] or if there isn't more avaible space.
 */
int findEmptyIndex(Employee* list, int len);

/**
 * \brief
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param
 * \return
 */
int loadUpEmployee(Employee* list, int len,int* id);

/**
 * \brief add in a existing list of employees the values received as parameters * in the first empty position
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * \brief find an Employee by Id en returns the index position in array.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len,int id);

/**
 * \brief
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \param
 * \return
 */
int modifyEmployee(Employee* list, int len, int id);

/**
 * \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list, int len, int id);

/**
 * \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list, int len, int order);

/**
 * \brief Forces data into the array of employees
 * \param list Employee* Pointer to array of employees
 * \param id int*
 * \param
 * \return
 */
int printOneEmployee(Employee list);

/**
 * \brief Print the content of employees array
 * \param list Employee* Pointer to array of employees
 * \param length int  Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printEmployees(Employee* list, int len);

/**
 * \brief
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param
 * \return
 */
int inform(Employee* list, int len);

/**
 * \brief
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param
 * \return int Returns TRUE(1) if there is data, if not, returns FALSE(0)
 */
int isAnyData(Employee* list, int len);

/**
 * \brief Forces data into the array of employees
 * \param list Employee* Pointer to array of employees
 * \param id int*
 * \param
 * \return
 */
int hardCodeData(Employee* list,int* id);

/**
 * \brief Forces data into the array of employees
 * \param list Employee* Pointer to array of employees
 * \param id int*
 * \param
 * \return
 */
int totalSalary(Employee* list, int len,float* totalSalary);

/**
 * \brief Forces data into the array of employees
 * \param list Employee* Pointer to array of employees
 * \param id int*
 * \param
 * \return
 */
int averageSalary(Employee* list, int len, float* averageSalary);

/**
 * \brief Forces data into the array of employees
 * \param list Employee* Pointer to array of employees
 * \param id int*
 * \param
 * \return
 */
int printEmployeesAboveAverageSalary(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
