#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "faculty.h"
#include <errno.h>

int main(int argc, char * argv[])
{
struct professor new_arr [NUM_FACULTY];
	if(argc ==2)
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
		
		for(int i = 0; i < 16; i++)
		{
		
			//faculty[i] = r;
			printf("%s\n %s\n %s\n %s\n",new_arr[i].name,new_arr[i].office,new_arr[i].phone,new_arr[i].email );
		}
		return EXIT_SUCCESS;
	}

}
