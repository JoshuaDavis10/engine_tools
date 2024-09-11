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

    register_event(KEY_PRESS, 0, cb);

    event_context c;
    memset(&c, 0, sizeof(event_context));
    fire_event(KEY_PRESS, 0, c);

	return 0;
}
