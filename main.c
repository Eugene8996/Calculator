#include <stdio.h>
#include <dlfcn.h>
#include "plugins/complex.h"

#define LIB_PATH_ADD "plugins/libadd.so"
#define LIB_PATH_SUB "plugins/libsub.so"
#define LIB_PATH_DIV "plugins/libdiv.so"
#define LIB_PATH_MUL "plugins/libmul.so"

#define LIB_COUNT 4

typedef	void (*lib_func)(struct complex_number *com_num1, struct complex_number *com_num2, struct complex_number *result);
typedef struct 
{
	void *handler;
	lib_func function;
	char *name;
}lib_t;


int main(void)
{
	struct complex_number com_num1, com_num2, result;
	char buffer [256];
	int operation = 0;
	int i=0;
	
	lib_t lib_handler[LIB_COUNT];
	int lib_total = 0;

	lib_handler[lib_total].handler = dlopen(LIB_PATH_ADD, RTLD_LAZY);
	if(!lib_handler[lib_total].handler)
		printf("The library "LIB_PATH_ADD" is missing\n");
	else
	{
		lib_handler[lib_total].function = dlsym(lib_handler[lib_total].handler, "complex_add");
		lib_handler[lib_total].name = "Add";
		lib_total++;
	}

	lib_handler[lib_total].handler = dlopen(LIB_PATH_SUB, RTLD_LAZY);
	if(!lib_handler[lib_total].handler)
		printf("The library "LIB_PATH_SUB" is missing\n");
	else
	{
		lib_handler[lib_total].function = dlsym(lib_handler[lib_total].handler, "complex_sub");
		lib_handler[lib_total].name = "Sub";
		lib_total++;
	}

	lib_handler[lib_total].handler = dlopen(LIB_PATH_DIV, RTLD_LAZY);
	if(!lib_handler[lib_total].handler)
		printf("The library "LIB_PATH_DIV" is missing\n");
	else
	{
		lib_handler[lib_total].function = dlsym(lib_handler[lib_total].handler, "complex_div");
		lib_handler[lib_total].name = "Div";
		lib_total++;
	}

	lib_handler[lib_total].handler = dlopen(LIB_PATH_MUL, RTLD_LAZY);
	if(!lib_handler[lib_total].handler)
		printf("The library "LIB_PATH_MUL" is missing\n");
	else		
	{
		lib_handler[lib_total].function = dlsym(lib_handler[lib_total].handler, "complex_mul");
		lib_handler[lib_total].name = "Mul";
		lib_total++;
	}

	while(1)
	{
		for (i = 0; i < lib_total; i++)
		{
			printf("%d) %s\n", i + 1, lib_handler[i].name);
		}
		printf("%d) Quit\n>", lib_total + 1);
		
		scanf("%s", buffer);
		if (sscanf(buffer, "%d", &operation) != 1)
		{
			printf("Error!\n");
			continue;
		}
		if (operation == lib_total + 1)
			return 0;
		scanf("%f%f%f%f", &com_num1.real_number, &com_num1.imaginary_number, &com_num2.real_number, &com_num2.imaginary_number);
		lib_handler[operation-1].function(&com_num1, &com_num2, &result);
		printf("result = %.2f %.2f\n", result.real_number, result.imaginary_number);
	}
	for (i = 0; i <= lib_total; i++)
		{
			dlclose(lib_handler[i].handler);
		}
	return 0;
}




