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
 * \brief Searches for an empty index in the array,
 * 		  this function checks if the flag(isEmpty) is TRUE and saves the first index found.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return value of the first empty index found -
 * 			   or (-1) if Error [Invalid length, NULL pointer or if there isn't more avaible space]
 */
int findEmptyIndex(Employee* list, int len);

/**
 * \brief Requests to the user to complete the data asked and adds that data to the array.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int*, Pointer to the value of the id to be asigned
 * \return Return (-1) if Error [Invalid length or NULL pointer or no avaible space] - (0) if OK
 */
int loadUpEmployee(Employee* list, int len,int* id);

/**
 * \brief add in a existing list of employees the values received as parameters * in the first empty position
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \param id int value of the id asigned
 * \param name[] char value of the name entered
 * \param lastName[] char value of the lastName entered
 * \param salary float value of the salary entered
 * \param sector int value of the sector entered
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * \brief Searches an Employee by Id
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int, id searched
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len,int id);

/**
 * \brief Lets the user to decide what field to change of an existing employee
 * 			(also choosed by the user, searched by id)
 * \param list employee* Pointer to array of employees
 * \param len int Array length
 * \param int id, id searched
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 */
int modifyEmployee(Employee* list, int len, int id);

/**
 * \brief Remove a Employee searched by Id (put isEmpty Flag in 1)
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int, id searched
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
 * \brief Prints the data of only one employee
 * \param list Employee* Pointer to array of employees
 * \return Return (-1) if Error [flag isEmpty is TRUE] - (0) if Ok
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
 * \brief Lets the user to decide what to see - Ordered list of employees or data about salary
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int inform(Employee* list, int len);

/**
 * \brief Checks if there is any data in the array
 * 			this function checks the flag (isEmpty). If it is false, there is data.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Returns TRUE(1) if there is data, if not, returns FALSE(0)
 */
int isAnyData(Employee* list, int len);

/**
 * \brief Forces data into the array of employees
 * \param list Employee* Pointer to array of employees
 * \param id int* Pointer to the id to be asigned
 * \return Return (-1) if Error [NULL pointer] - (0) if Ok
 */
int hardCodeData(Employee* list,int* id);

/**
 * \brief Calculates the total salary of all employees
 * \param list Employee* Pointer to array of employees
 * \param int len Array length
 * \param float* totalSalary pointer to the space where the value calculated will be saved
 * \return
 */
int totalSalary(Employee* list, int len,float* totalSalary);

/**
 * \brief Calculates the average salary
 * \param list Employee* Pointer to array of employees
 * \param int len Array length
 * \param float* averageSalary  pointer to the space where the value calculated will be saved
 * \return
 */
int averageSalary(Employee* list, int len, float* averageSalary);

/**
 * \brief Prints and counts the quantity employees above average salary
 * \param list Employee* Pointer to array of employees
 * \param int len Array length
 * \param int* qtyEmployeesAboveAverageSalary pointer to the space where the quantity of employees will be saved
 * \return
 */
int printEmployeesAboveAverageSalary(Employee* list, int len,int* qtyEmployeesAboveAverageSalary);

#endif /* ARRAYEMPLOYEES_H_ */
