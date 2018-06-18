#include "car.h"


typedef struct {
    Car parent;

    int top_speed;
} SCar;


extern struct vtbl SCar_vtable;
