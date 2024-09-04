#include "../include/raylib.h"

#include "defines.h"
#include "logger.h"
#include "darray.h"

#include <stdio.h>

int main() {

	void* darray = darray_create(int);
	printf("created darray\n");

	darray_push(darray, 12);
	darray_push(darray, 14);

	int temp = 3;
	int* data = &temp;
	darray_pop(darray, data);
	printf("%d popped.\n", *(data));
	darray_pop(darray, data);
	printf("%d popped.\n", *(data));

	return 0;
}
