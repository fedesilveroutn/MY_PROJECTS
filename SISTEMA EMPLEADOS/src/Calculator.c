#include "Calculator.h"

/**
 * @fn float calculator_add(float, float)
 * @brief
 *
 * @param num1
 * @param num2
 * @return
 */
float calculator_add(float num1, float num2)
{
	float result;
	result = num1 + num2;
	return result;
}
/**
 * @fn float calculator_rest(float, float)
 * @brief
 *
 * @param num1
 * @param num2
 * @return
 */
float calculator_rest(float num1, float num2)
{
	float result;
	result = num1 - num2;
	return result;
}
/**
 * @fn float calculator_divide(float, float)
 * @brief
 *
 * @param num1
 * @param num2
 * @return
 */
float calculator_divide(float num1, float num2)
{
	float result = 0;
	if(num2 != 0)
	{
		result = num1 / num2;
	}
	else
	{
		printf("\nERROR. NO SE PUEDE DIVIDIR POR 0");
	}

	return result;
}
/**
 * @fn float calculator_multiply(float, float)
 * @brief
 *
 * @param num1
 * @param num2
 * @return
 */
float calculator_multiply(float num1, float num2)
{
	float result;
	result = num1 * num2;
	return result;
}
/**
 * @fn int calculator_operations()
 * @brief
 *
 * @return
 */
int calculator_operations()
{
	int ret = -1;
	int option;
	float num1;
	float num2;
	float result;

	getInt(&option, "\n------------------------------------------------------------------"
					"\n1. SUMAR"
					"\n2. RESTAR"
					"\n3. DIVIDIR"
					"\n4. MULTIPLICAR"
					"\n------------------------------------------------------------------"
					"\nINGRESE UNA OPCION (1-4): ", "\nERROR. REINGRESE UNA OPCION VALIDA (1-4): ", 1, 4 );

	switch(option)
	{

	case 1:
			getFloat(&num1, "\nINGRESE EL PRIMER OPERANDO: ", "\nERROR. REINGRESE UN NUMERO VALIDO: ", -99999999, 99999999);
			getFloat(&num2, "\nINGRESE EL SEGUNDO OPERANDO: ", "\nERROR. REINGRESE UN NUMERO VALIDO: ", -99999999, 99999999);
			result = calculator_add(num1, num2);
			break;

	case 2:
			getFloat(&num1, "\nINGRESE EL MINUENDO: ", "\nERROR. REINGRESE UN NUMERO VALIDO: ", -99999999, 99999999);
			getFloat(&num2, "\nINGRESE EL SUSTRAENDO: ", "\nERROR. REINGRESE UN NUMERO VALIDO: ", -99999999, 99999999);
			result = calculator_rest(num1, num2);
			break;

	case 3:
			getFloat(&num1, "\nINGRESE EL DIVIDENDO: ", "\nERROR. REINGRESE UN NUMERO VALIDO: ", -99999999, 99999999);
			getFloat(&num2, "\nINGRESE EL DIVISOR: ", "\nERROR. REINGRESE UN NUMERO VALIDO: ", -99999999, 99999999);
			result = calculator_divide(num1, num2);
			break;

	case 4:
			getFloat(&num1, "\nINGRESE EL PRIMER FACTOR: ", "\nERROR. REINGRESE UN NUMERO VALIDO: ", -99999999, 99999999);
			getFloat(&num2, "\nINGRESE EL SEGUNDO FACTOR: ", "\nERROR. REINGRESE UN NUMERO VALIDO: ", -99999999, 99999999);
			result = calculator_multiply(num1, num2);
			break;

	}

	printf("EL RESULTADO ES: %.2f", result);
	ret = 0;
	return ret;
}
/**
 * @fn float calculator_averageSalary(float, int)
 * @brief
 *
 * @param num
 * @param count
 * @return
 */
float calculator_averageSalary(float num, int count)
{
	float result;
	result = num / count;
	return result;
}










