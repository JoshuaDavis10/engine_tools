#pragma once

enum {
	DARRAY_CAPACITY,
	DARRAY_LENGTH,
	DARRAY_STRIDE,
	DARRAY_FIELD_LENGTH
};

void* _darray_create(unsigned long long capacity, unsigned long long stride);
void  _darray_destroy(void* darray);

unsigned long long _darray_get_field(void* darray, unsigned long long field);
void _darray_set_field(void* darray, unsigned long long field, unsigned long long set_value);

void* _darray_resize(void* darray);

void* _darray_push(void* darray, const void* value_ptr);
//pop does not need to return a pointer to the darray b/c pop will pop off the end putting a TODO here cuz im not
//sure if that's exactly why...
void  _darray_pop(void* darray, void* dest);

//pop_at DOES need to return a pointer to the darray b/c we could pop off the start and then we'd have to return 
//the new start location? or smn...idk just implement the darn functions and then look back at this comment TODO
void* _darray_pop_at(void* darray, unsigned long long index, void* dest);
void* _darray_insert_at(void* darray, unsigned long long index, void* value_ptr);

#define DARRAY_DEFAULT_CAPACITY 1
#define DARRAY_RESIZE_FACTOR 2 

#define darray_create(type) \
	_darray_create(DARRAY_DEFAULT_CAPACITY, sizeof(type))

#define darray_reserve(type, capacity) \
	_darray_create(capacity, sizeof(type))

#define darray_destroy(array) _darray_destroy(array);

#define darray_push(array, value)  \
	{							   \
		__auto_type temp = value;\
		_darray_push(array, &temp);\
	}							   
		
#define darray_pop(array, value_ptr) \
	_darray_pop(array, value_ptr)

#define darray_insert_at(array, index, value)  \
	{										   \
		__auto_type temp = value;			   \
		_darray_insert_at(array, index, &temp);\
	}

#define darray_pop_at(array, index, value_ptr)\
	_darray_pop_at(array, index, value_ptr)

//clear (set length to 0)
#define darray_clear(array)\
	_darray_set_field(array, DARRAY_LENGTH, 0)

//getters for: capacity, length, stride
#define darray_capacity(array)\
	_darray_get_field(array, DARRAY_CAPACITY)

#define darray_length(array)\
	_darray_get_field(array, DARRAY_LENGTH)

#define darray_stride(array)\
	_darray_get_field(array, DARRAY_STRIDE)

//set length
#define darray_set_length(array, value) \
	_darray_set_field(array, DARRAY_LEGTH, value)
