#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAX_RATE 0.0775
#define CATALOG_SIZE ((int) (sizeof(catalog) / sizeof(struct item))) // prints the total number of skus in catalog


struct item {
    char *sku;
    char *desc;
    double price;
    bool taxable;
};

struct item catalog[] = {
    { .sku = "87465896", .desc = "milk",         .price = 3.59, .taxable = false },
    { .sku = "37485942", .desc = "eggs",         .price = 2.98, .taxable = false },
    { .sku = "37618947", .desc = "bread",        .price = 3.18, .taxable = false },
    { .sku = "09484232", .desc = "ziploc bags",  .price = 1.19, .taxable = true },
    { .sku = "83648591", .desc = "paper towels", .price = 2.76, .taxable = true },
};

float total_cost = 0; // this gets the total cost
float taxable_val = 0; // this checks to see if tax is needed
int main(void)
{
	//printf("%d",CATALOG_SIZE); 
	char sku[9]; // gets the size of the sku
	unsigned int quant = 0; // gets the amount of items

    while(scanf("%s %u",sku,&quant) != EOF) // just checks the run
    {
    	for(int i = 0; i < CATALOG_SIZE; i++ ) // checks the struct to see if the values are the same
    	{
    		if(strcmp(sku,catalog[i].sku) == 0) // does comparison to see if the sku and the catalog.sku are the same
    		{
    			if(catalog[i].taxable == true) // checks to see if its taxable
    			{
    				float temp_cost = quant * catalog[i].price;
    				taxable_val = temp_cost*TAX_RATE;
    				total_cost = total_cost + taxable_val+temp_cost;
    				
    				
    			}
    			else
    			{
    				float temp_cost = quant * catalog[i].price;
    				total_cost = total_cost +temp_cost;
    				
    			}
    		}
    	}
    }
    
    printf("$%.2f\n",total_cost); // this will print the total cost 
}

