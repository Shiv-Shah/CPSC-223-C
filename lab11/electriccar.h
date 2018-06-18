#include "car.h"


typedef struct {
    Car parent;

    int max_range;
} ECar;


extern struct vtbl ECar_vtable;
