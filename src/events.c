#include "events.h"

//TODO: registered event struct (has listener (void*) and callback function)

//TODO: event code entry struct (array of registered events for a particular code

//TODO: event system state struct (array of event code entries... has length of maximum message codes (just make it a big number... you'll really only have like 4 codes tbh... for now at least)

//TODO: static event system state global variable (also a boolean is_initialized that will be checked whenever the initialize event system func is called so that we don't initialize it more than once)

//TODO: at this point you need a darray implementation

//TODO: function implementatons
//	- initialize
//	- shutdown
//	- register
//	- unregister
//	- fire


