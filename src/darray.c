#include "darray.h"

#include <stdlib.h>

#define DEFAULT_CAPACITY 1

enum {
	DARRAY_CAPACITY,
	DARRAY_LENGTH,
	DARRAY_STRIDE,
	DARRAY_FIELD_LENGTH
};

void* _darray_create(unsigned int capacity, unsigned int stride) {
	unsigned int darray_info_size = sizeof(unsigned int) * DARRAY_FIELD_LENGTH;
	unsigned int data_size = stride * capacity; 
	unsigned int* darray = malloc(darray_info_size + data_size);

	memset(darray, 0, darray_info_size + data_size);

	darray[DARRAY_CAPACITY] = capacity;
	darray[DARRAY_LENGTH] = 0;
	darray[DARRAY_STRIDE] = stride;

	return (void*)(darray + DARRAY_FIELD_LENGTH);
}

void _darray_destroy(void* darray) {
	//TODO: code here
}
