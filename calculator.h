#ifndef CALCULATOR_H
#define CALCULATOR_H
struct complex_number
{
	float real_number;
	float imaginary_number;
};

void complex_add(struct complex_number *com_num1, struct complex_number *com_num2, struct complex_number *result);
void complex_sub(struct complex_number *com_num1, struct complex_number *com_num2, struct complex_number *result);
void complex_div(struct complex_number *com_num1, struct complex_number *com_num2, struct complex_number *result);
void complex_mul(struct complex_number *com_num1, struct complex_number *com_num2, struct complex_number *result);
#endif
