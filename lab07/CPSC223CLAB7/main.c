#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "faculty.h"

int main_cmp(const void *a, const void *b)
{
	return strcmp(((const struct command *)a)->name, ((const struct command *)b)->name);	
}


int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("\nphonebook <command> <string>");
	}
	else
	{
		struct command * find_thing = bsearch(argv[1],commands,NUM_COMMANDS,sizeof(struct command),main_cmp);
		if(find_thing == NULL)
		{
			printf("invalid response\n");
			return EXIT_FAILURE;
		
		}
		else
		{
			int index =find_thing->function(argv[2]);
			if(index != -1)
			{
				printf("%s\n,%s\n,%s\n,%s\n",faculty[index].name,faculty[index].office,faculty[index].phone,faculty[index].email);
			}
			else
			{
				printf("no match\n");	
			}
				
		}
	}
	
}
