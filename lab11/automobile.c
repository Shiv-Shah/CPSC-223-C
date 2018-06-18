#include <stdio.h>

#include "automobile.h"

void Automobile_describe_impl(Automobile *this)
{
    printf("Price: $%g\n", this->price);
}

void test_drive(Automobile *this )
{
	this->mileage +=5;
	
}

struct vtbl Automobile_vtable = {
    Automobile_describe_impl,
    test_drive
    
    
};

