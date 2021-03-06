#include <stdio.h>
#include "complex.h"
#include "div.h"
void complex_div(struct complex_number *com_num1, struct complex_number *com_num2, struct complex_number *result)
{
	result->real_number = (com_num1->real_number*com_num2->real_number + com_num1->imaginary_number*com_num2->imaginary_number)/(com_num2->real_number*com_num2->real_number + com_num2->imaginary_number*com_num2->imaginary_number);
	result->imaginary_number = (com_num2->real_number*com_num1->imaginary_number - com_num1->real_number*com_num2->imaginary_number)/(com_num2->real_number*com_num2->real_number + com_num2->imaginary_number*com_num2->imaginary_number);
}