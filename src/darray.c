#include "darray.h"
#include "logger.h"

#include <stdlib.h>
#include <string.h>

void* _darray_create(unsigned long long capacity, unsigned long long stride) {
	unsigned long long header_size = sizeof(unsigned long long) * DARRAY_FIELD_LENGTH;
	unsigned long long array_size  = capacity * stride;
	unsigned long long* new_array = malloc(header_size + array_size);
	memset(new_array, 0, header_size + array_size);
	new_array[DARRAY_LENGTH]   = 0;
	new_array[DARRAY_CAPACITY] = capacity;
	new_array[DARRAY_STRIDE]   = stride;
	return (void*)(new_array + DARRAY_FIELD_LENGTH);
}

void  _darray_destroy(void* darray) {
	unsigned long long* header = (unsigned long long*)darray - DARRAY_FIELD_LENGTH;
	free(header);
}

unsigned long long _darray_get_field(void* darray, unsigned long long field) {
	unsigned long long* header = (unsigned long long*)darray - DARRAY_FIELD_LENGTH;
	return header[field];
}

void _darray_set_field(void* darray, unsigned long long field, unsigned long long set_value) {
	unsigned long long* header = (unsigned long long*)darray - DARRAY_FIELD_LENGTH;
	header[field] = set_value;
}

void* _darray_resize(void* darray) {
	unsigned long long length = darray_length(darray);
	unsigned long long stride = darray_stride(darray);
	void* temp = _darray_create(DARRAY_RESIZE_FACTOR * darray_capacity(darray), stride);
	memcpy(temp, darray, length * stride);

	_darray_set_field(temp, DARRAY_LENGTH, length);
	_darray_destroy(darray);
	return temp;
}

void* _darray_push(void* darray, const void* value_ptr) {
	unsigned long long length = darray_length(darray);
	unsigned long long stride = darray_stride(darray);

	if(length >= darray_capacity(darray)) {
		darray = _darray_resize(darray);
		LOGINFO("Resized darray.");
	}

	unsigned long long addr = (unsigned long long)darray;
	addr += (length * stride);
	memcpy((void*)addr, value_ptr, stride);
	LOGINFO("Pushed data.");
	_darray_set_field(darray, DARRAY_LENGTH, length + 1);
	return darray;
}
//pop does not need to return a pointer to the darray b/c pop will pop off the end putting a TODO here cuz im not
//sure if that's exactly why...
void  _darray_pop(void* darray, void* dest) {
	unsigned long long length = darray_length(darray);
	unsigned long long stride = darray_stride(darray);

	unsigned long long addr = (unsigned long long)darray;
	addr += ((length - 1) * stride);
	memcpy(dest, (void*)addr, stride);
	_darray_set_field(darray, DARRAY_LENGTH, length - 1);

	LOGINFO("Popped data.");
}

//pop_at DOES need to return a pointer to the darray b/c we could pop off the start and then we'd have to return 
//the new start location? or smn...idk just implement the darn functions and then look back at this comment TODO
void* _darray_pop_at(void* darray, unsigned long long index, void* dest) {
	unsigned long long length = darray_length(darray);
	unsigned long long stride = darray_stride(darray);
	if(index >= length) {
		LOGERROR("Tried to pop from an index out of bounds of the array.");
		return darray;
	}

	unsigned long long addr = (unsigned long long)darray;
	addr += (index * stride);
	memcpy(dest, (void*)addr, stride);

	// If not last element, remove entry and copy everything past it inward:
	if(index != length - 1) {
		memcpy((void*)addr, (void*)(addr + stride), stride * (length - index));
	}

	_darray_set_field(darray, DARRAY_LENGTH, length - 1);
	return darray;
}

void* _darray_insert_at(void* darray, unsigned long long index, void* value_ptr) {
	unsigned long long length = darray_length(darray);
	unsigned long long stride = darray_stride(darray);
	if(index >= length) {
		LOGERROR("Tried to insert an element to an index out of bounds of the array.");
		return darray;
	}
	if(length >= darray_capacity(darray)) {
		darray = _darray_resize(darray);
	}

	unsigned long long addr = (unsigned long long)darray;
	addr += (index * stride);

	// If not the last element, copy everything past the index outward to make room for the new element:
	if(index != length - 1) {
		memcpy((void*)(addr + stride), (void*)addr, stride * (length - index));
	}

	// Set value at index
	memcpy((void*)addr, value_ptr, stride);
	_darray_set_field(darray, DARRAY_LENGTH, length + 1);
	return darray;
}
