#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "faculty.h"
#include <errno.h>
#include "commands.h"

// struct professor new_arr [NUM_FACULTY]= {};


 struct professor new_arr [NUM_FACULTY];

int main_cmp(const void *a, const void *b)
{
	return strcmp(((const struct command *)a)->name, ((const struct command *)b)->name);	
}


int main(int argc, char * argv[])
{

	if(argc ==3)
	{
		int ope = open(argv[1], O_RDONLY);
		if(ope == -1)
		{
			printf("Error %s\n",strerror(errno));
			exit( EXIT_FAILURE);	
		}
		
		int r = read(ope,new_arr,sizeof(faculty));
		
			if(r  == -1)
			{
					printf("Error %s\n",strerror(errno));
					exit( EXIT_FAILURE);	
					
			}
		
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
				printf("%s\n,%s\n,%s\n,%s\n",new_arr[index].name,new_arr[index].office,new_arr[index].phone,new_arr[index].email);
			}
			else
			{
				printf("no match\n");	
			}
				
		}
		
		
		return EXIT_SUCCESS;
	}

}
