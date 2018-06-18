#include <stdio.h>

#include "car.h"
#include "electriccar.h"
#include "automobile.h"


void ECar_describe_impl(Automobile *obj)
{
	ECar *this = (ECar *) obj;
	printf("%d %s with %d doors and %d miles. The max range is %d. \n",
		   this->parent.parent.model,
		   this->parent.parent.make,
		   this->parent.doors,
		   this->parent.parent.mileage,
		   this-> max_range
		   );
		   
	Automobile_describe_impl(&this->parent.parent);
	test_drive(&this->parent.parent);
	
	printf("%d %s with %d doors and %d miles. The max range is %d. \n",
		   this->parent.parent.model,
		   this->parent.parent.make,
		   this->parent.doors,
		   this->parent.parent.mileage,
		   this-> max_range
		   );
		   
	Automobile_describe_impl(&this->parent.parent);
}

void ECar_what_impl(Automobile *obj, char *fmt)
{
    ECar *this = (ECar *) obj;

    printf(fmt, "ECar", this->parent.parent.make);
}

struct vtbl ECar_vtable = {
    ECar_describe_impl,
    test_drive,
};
