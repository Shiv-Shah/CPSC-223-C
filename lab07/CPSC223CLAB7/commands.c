#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "faculty.h"

struct command commands[NUM_COMMANDS] = {
    { "email",  find_by_email},
    { "name",   find_by_name },
    { "office", find_by_office },
    { "phone",  find_by_phone },
};

int cmp_name(const void * n1,const void * n2)
{
	return strcmp(((const struct professor *)n1)->name,((const struct professor *)n2)->name);
}


int find_by_name(char *name)
{
   struct professor foo;
   strcpy(foo.name,name);
	qsort(faculty,NUM_FACULTY,sizeof(struct professor),cmp_name);
	struct professor * find_name = bsearch(&foo,faculty,NUM_FACULTY,sizeof(struct professor),cmp_name);
	if(find_name != NULL)
	{
		return find_name - faculty;
	}
	else
	{
		return -1;	
	}
	
}

int cmp_office( const void * o1,const void * o2)
{
	return strcmp(((const struct professor *)o1)->office,((const struct professor *)o2)->office);
}

int find_by_office(char *office)
{
    // REMOVE THE FOLLOWING LINE BEFORE ADDING YOUR CODE
  //  (void) office;

    // INSERT CODE HERE
    struct professor foo;
    strcpy(foo.office,office);
    qsort(faculty,NUM_FACULTY,sizeof(struct professor),cmp_office);
    struct professor * find_office = bsearch(&foo,faculty,NUM_FACULTY,sizeof(struct professor),cmp_office);
    if(find_office != NULL)
	{
		return find_office - faculty;
	}
	else
	{
		return -1;	
	}
}


int cmp_phone(const void * p1,const void * p2)
{
	return strcmp(((const struct professor *)p1)->phone,((const struct professor *)p2)->phone);
}


int find_by_phone(char *phone)
{
   // (void) phone;

    // INSERT CODE HERE
    struct professor foo;
   	strcpy(foo.phone,phone);
	qsort(faculty,NUM_FACULTY,sizeof(struct professor),cmp_phone);
	struct professor * find_phone =bsearch(&foo,faculty,NUM_FACULTY,sizeof(struct professor),cmp_phone);

    if(find_phone != NULL)
	{
		return find_phone - faculty;
	}
	else
	{
		return -1;	
	}
}


int cmp_email(const void * e1,const void * e2)
{
	return strcmp(((const struct professor *)e1)->email,((const struct professor *)e2)->email);
}

int find_by_email(char *email)
{
    //(void) email;

    // INSERT CODE HERE
    struct professor foo;
    strcpy(foo.email,email);
    qsort(faculty,NUM_FACULTY,sizeof(struct professor),cmp_email);
	struct professor * find_email = bsearch(&foo,faculty,NUM_FACULTY,sizeof(struct professor),cmp_email);
	if(find_email != NULL)
	{
		return find_email - faculty;
	}
	else
	{
		return -1;	
	}
    
}


