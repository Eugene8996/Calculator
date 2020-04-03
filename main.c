#include <stdio.h>
#include "calculator.h"

int main(void)
{
	struct complex_number com_num1, com_num2, result;
	int operation;
	
	while(1)
	{
		printf("1)Add\n2)Sub\n3)Div\n4)Mul\n5)Quit\nEnter the operation and numbers\n>");
		scanf("%d", &operation);
		if (operation == 5)
			break;
		scanf("%f%f%f%f", &com_num1.real_number, &com_num1.imaginary_number, &com_num2.real_number, &com_num2.imaginary_number);
		switch (operation)
		{
			case 1:
			{
				complex_add(&com_num1, &com_num2, &result);
				break;
			}
			case 2:
			{
				complex_sub(&com_num1, &com_num2, &result);
				break;
			}
			case 3:
			{
				complex_div(&com_num1, &com_num2, &result);
				break;
			}
			case 4:
			{
				complex_mul(&com_num1, &com_num2, &result);
				break;
			}
		}
		printf("result = %.2f %.2f\n", result.real_number, result.imaginary_number);
	}
	return 0;
}




