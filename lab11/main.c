/*
 * Starter code for Lab 11
 *
 * cf. Gaddis, Starting out With C++, Eighth Edition, p. 912
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "automobile.h"
#include "car.h"
#include "truck.h"
#include "suv.h"
#include "electriccar.h"
#include "sportscar.h"

#define LEN(array) (sizeof(array) / sizeof(array[0]))

void list_inventory(Automobile *inventory[], int size)
{
    printf("We have the following automobiles in inventory:\n\n");

    for (int i = 0; i < size; i++) {
        inventory[i]->vptr->describe(inventory[i]);
        printf("\n");
    }
}

int main(void)
{
    Car c = {
        .parent.make     = "BMW",
        .parent.model    = 2017,
        .parent.mileage  = 50000,
        .parent.price    = 15000.0,
        .doors          = 4,
        .parent.vptr     = &Car_vtable,
    };

    Truck t = {
        .parent.make     = "Toyota",
        .parent.model    = 2006,
        .parent.mileage  = 40000,
        .parent.price    = 12000.0,
        .driveType      = "4WD",
        .parent.vptr     = &Truck_vtable,
    };

    SUV s = {
        .parent.make     = "Volvo",
        .parent.model    = 2005,
        .parent.mileage  = 30000,
        .parent.price    = 18000.0,
        .passengers     = 5,
        .parent.vptr     = &SUV_vtable,
    };
    
    SCar sc = {
    	.parent.parent.make       = "Porshe",
        .parent.parent.model      = 2015,
        .parent.parent.mileage    = 100000,
        .parent.parent.price      = 100000.0,
      //  .parent.passengers = 5,
      	.parent.doors             = 4,
        .top_speed                = 500,
        .parent.parent.vptr       = &SCar_vtable,
    };
   
    ECar ec = {
    	.parent.parent.make       = "Tesla",
        .parent.parent.model      = 2018,
        .parent.parent.mileage    = 100000,
        .parent.parent.price      = 35000.0,
        .parent.doors             = 4,
      //  .parent.passengers = 5,
        .max_range                = 400,
        .parent.parent.vptr       = &ECar_vtable,
    
    };
    

    Automobile *stock[] = {
        (Automobile *) &c,
        (Automobile *) &t,
        (Automobile *) &s,
        (Automobile *) &sc,
        (Automobile *) &ec
    };

    list_inventory(stock, LEN(stock));

    return EXIT_SUCCESS;
}
