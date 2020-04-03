#include <stdio.h>
#include "calculator.h"

void complex_add(struct complex_number *com_num1, struct complex_number *com_num2, struct complex_number *result)
{
	result->real_number = com_num1->real_number + com_num2->real_number;
	result->imaginary_number = com_num1->imaginary_number + com_num2->imaginary_number;
}

void complex_sub(struct complex_number *com_num1, struct complex_number *com_num2, struct complex_number *result)
{
	result->real_number = com_num1->real_number - com_num2->real_number;
	result->imaginary_number = com_num1->imaginary_number - com_num2->imaginary_number;
}

void complex_div(struct complex_number *com_num1, struct complex_number *com_num2, struct complex_number *result)
{
	result->real_number = (com_num1->real_number*com_num2->real_number + com_num1->imaginary_number*com_num2->imaginary_number)/(com_num2->real_number*com_num2->real_number + com_num2->imaginary_number*com_num2->imaginary_number);
	result->imaginary_number = (com_num2->real_number*com_num1->imaginary_number - com_num1->real_number*com_num2->imaginary_number)/(com_num2->real_number*com_num2->real_number + com_num2->imaginary_number*com_num2->imaginary_number);
}

void complex_mul(struct complex_number *com_num1, struct complex_number *com_num2, struct complex_number *result)
{
	result->real_number = com_num1->real_number*com_num2->real_number - com_num1->imaginary_number*com_num2->imaginary_number;
	result->imaginary_number = com_num1->real_number*com_num2->imaginary_number + com_num2->real_number*com_num1->imaginary_number;
}
