#pragma once

typedef struct event_context {
	unsigned int data[2];
} event_context;

typedef unsigned char (*event_callback)(int code, void* sender, void* listener, event_context context);

unsigned char initialize_events(); 
void shutdown_events(); 

unsigned char register_event  (int code, void* listener, event_callback callback);
unsigned char unregister_event(int code, void* listener, event_callback callback);
unsigned char fire_event(int code, void* sender, event_context context);

typedef enum event_code {
	KEY_PRESS,
	KEY_RELEASE,
	MOUSE_CLICK,
	MOUSE_RELEASE
} event_code;
