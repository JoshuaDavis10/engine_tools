#include "../include/raylib.h"

#include "defines.h"
#include "logger.h"
#include "darray.h"
#include "events.h"

#include <stdio.h>
#include <string.h>


unsigned char cb(int code, void* sender, void* listener, event_context context) {
    printf("Callback function.\n");
    return 1;
}

int main() {
    
    initialize_events();

<<<<<<< HEAD
    register_event(KEY_PRESS, 0, cb);

    event_context c;
    memset(&c, 0, sizeof(event_context));
    fire_event(KEY_PRESS, 0, c);
=======
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

>>>>>>> fb6183e237363c866a64db43d5fab4c0f2f789dc

	return 0;
}
