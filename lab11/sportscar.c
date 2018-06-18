#include <stdio.h>

#include "car.h"
#include "sportscar.h"
#include "automobile.h"


void SCar_describe_impl(Automobile *obj)
{
	SCar *this = (SCar *) obj;
	printf("%d %s with %d doors and %d miles. The top speed is %d. \n",
		   this->parent.parent.model, // we use the arrow to point to a car and then use the . to get its parent and use the . to get one of the values of the parent. I think 
		   this->parent.parent.make,
		   this->parent.doors,
		   this->parent.parent.mileage,
		   this-> top_speed
		   );
		   
	Automobile_describe_impl(&this->parent.parent);
	test_drive(&this->parent.parent);
	
		printf("%d %s with %d doors and %d miles. The top speed is %d. \n",
		   this->parent.parent.model,
		   this->parent.parent.make,
		   this->parent.doors,
		   this->parent.parent.mileage,
		   this-> top_speed
		   );
	Automobile_describe_impl(&this->parent.parent);
}

void SCar_what_impl(Automobile *obj, char *fmt)
{
    SCar *this = (SCar *) obj;

    printf(fmt, "SCar", this->parent.parent.make);
}

struct vtbl SCar_vtable = {
    SCar_describe_impl,
    test_drive,
};
