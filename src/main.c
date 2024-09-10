#include "../include/raylib.h"

#include "defines.h"
#include "logger.h"
#include "darray.h"

#include <stdio.h>

int main() {

	void* darray = (void*)darray_create(int);
	printf("created darray\n");
	int temp = 3;

	darray_push(darray, 1);
	darray_push(darray, 2);
	darray_push(darray, 3);
	darray_push(darray, 4);
	darray_pop(darray, &temp);
	printf("%d popped.\n", temp);
	darray_pop(darray, &temp);
	printf("%d popped.\n", temp);
	darray_pop(darray, &temp);
	printf("%d popped.\n", temp);
	darray_pop(darray, &temp);
	printf("%d popped.\n", temp);


	return 0;
}
