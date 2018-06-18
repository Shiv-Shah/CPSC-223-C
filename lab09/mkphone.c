// Lab 9 

//Lab 9 int fd = open(filename,mode,permis)

//fopen          open
///"rb"           O_RDONLY
//"wb"           O_WRONLY | O_CREAT | O_TRUNC
// turn bit on : byte|flag
// turn bit off: byte&flag
// toggle bit on/off byte ^ flag
// check to see if the it is set (byte & flag) == flag
// check if a bit is not set (byte & flag) == 0

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "faculty.h"
#include "faculty.c"





int cmp_name(const void * n1,const void * n2)
{
	return strcmp(((const struct professor *)n1)->name,((const struct professor *)n2)->name);
}

int cmp_office( const void * o1,const void * o2)
{
	return strcmp(((const struct professor *)o1)->office,((const struct professor *)o2)->office);
}

int cmp_phone(const void * p1,const void * p2)
{
	return strcmp(((const struct professor *)p1)->phone,((const struct professor *)p2)->phone);
}

int cmp_email(const void * e1,const void * e2)
{
	return strcmp(((const struct professor *)e1)->email,((const struct professor *)e2)->email);
}

int main(void)
{
 	int ope = open("name.bin", O_WRONLY | O_CREAT | O_TRUNC,0444);
 	if(ope == -1 )
 	{
 		exit( EXIT_FAILURE);
 	}
 	else
 	{
 		qsort(faculty,NUM_FACULTY,sizeof(struct professor),cmp_name);
 		if(write(ope, faculty,sizeof(faculty)) == -1)
 		{
 			exit( EXIT_FAILURE);
 		}
 	}
 	close(ope);
	// create file 
	// quick sort
	// write to file 
	// do again
	ope = open("office.bin", O_WRONLY | O_CREAT | O_TRUNC,0444);
 	if(ope == -1 )
 	{
 		exit( EXIT_FAILURE);
 	}
 	else
 	{
 		qsort(faculty,NUM_FACULTY,sizeof(struct professor),cmp_office);
 		if(write(ope, faculty,sizeof(faculty))  == -1)
 		{
 			exit( EXIT_FAILURE);
 		}
 	}
 	close(ope);
	
	
	ope = open("phone.bin", O_WRONLY | O_CREAT | O_TRUNC,0444);
 	if(ope == -1 )
 	{
 		exit( EXIT_FAILURE);
 	}
 	else
 	{
 		qsort(faculty,NUM_FACULTY,sizeof(struct professor),cmp_phone);
 		if(write(ope, faculty,sizeof(faculty)) == -1)
 		{
 			exit( EXIT_FAILURE);
 		}
 	}
 	close(ope);
 	
 	
 	ope = open("email.bin", O_WRONLY | O_CREAT | O_TRUNC,0444);
 	if(ope == -1 )
 	{
 		 exit( EXIT_FAILURE);
 	}
 	else
 	{
 		qsort(faculty,NUM_FACULTY,sizeof(struct professor),cmp_email);
 		if(write(ope, faculty,sizeof(faculty)) == -1)
 		{
 			exit( EXIT_FAILURE);
 		}
 	}
 	close(ope);
	
	
}























