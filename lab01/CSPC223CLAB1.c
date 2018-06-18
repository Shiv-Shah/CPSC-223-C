#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/// USE GBD 
// lab1.cpp - convert this code to C11

/*
 *  This code should compile cleanly with the following options:
 *

	C:   -std=c11   -g -Og -Wall -Wextra -Wpedantic
	C++: -std=c++11 -g -Og -Wall -Wextra -Wpedantic
 */

unsigned int counter_for_length_of_array = 0;

void bumpint(int* i, int* amount)
{
	//  printf("Before NULL");
	if (amount == NULL)
	{
		*i += 1;

	}
	else
	{
		*i += *amount;
	}
}

void bumpchardeafault(char s[])
{
	if (counter_for_length_of_array == strlen(s))
	{
		char * revisedstr = malloc((strlen(s) * 2));
		for (unsigned int i = 0; i < strlen(s); i++)
		{
			revisedstr[i] = s[i];
		}
		revisedstr[strlen(s)] = 'o';
		counter_for_length_of_array++;
		for (unsigned int i = 0; i < strlen(s)+1; i++)
		{
			s[i] = revisedstr[i];
		}
	}
	else
	{
		s[counter_for_length_of_array] = 'o';
		counter_for_length_of_array++;
	}

}


void bumpchar(char s[], char amount)
{

	if (counter_for_length_of_array == strlen(s))
	{
		int inclength = strlen(s) ;
		char *newstr = malloc(inclength* 2);
		for (unsigned int i = 0; i < strlen(s); i++)
		{
			newstr[i] = s[i];
		}
		for (unsigned int i = 0; i < strlen(newstr); i++)
		{
			s[i] = newstr[i];
		}
		s[strlen(s)] = amount;
		counter_for_length_of_array++;
	}
	else
	{
		s[strlen(s)] = amount;
		counter_for_length_of_array++;
	}




}



int main()
{
	// int size_of_string = 0;

	char str[] = "Hello World";


	int i;
	int amount = 2;
	i = 1;

	counter_for_length_of_array = strlen(str);

	printf("%d%s i = ", i, "\n");
	//  printf("The Call to Null");
	bumpint(&i, NULL);
	printf("%d%s i = ", i, "\n");
	bumpint(&i, &amount);
	printf("%d%s i = ", i, "\n");






	//printf("%s i = ",i,"\n");
	for (unsigned int c = 0; c < strlen(str); c++)
	{
		printf("%c", str[c]);
	}
	printf("\n");
	bumpchardeafault(str);
	for (unsigned int c = 0; c < strlen(str); c++)
	{
		printf("%c", str[c]);
	}
	printf("\n");
	bumpchar(str, 'x');
	for (unsigned int c = 0; c < strlen(str); c++)
	{
		printf("%c", str[c]);
	}
	printf("\n");

	return 0;
}

