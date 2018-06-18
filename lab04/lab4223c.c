// lab4.c - starter code for Lab 4

/*
 * Convert your program from Lab 3 to use a linked list instead of an array.
 * Use this code as a starting point.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_SIZE 3
#define GDB_COMMAND_SIZE 10

struct node {
    int line;
    char command[MAX_COMMAND_SIZE + 1];
    unsigned int argument;

    struct node *next;
};

struct node *create_node(int line, char *command, unsigned int argument)
{
    assert(strlen(command) <= MAX_COMMAND_SIZE);

    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__); 
        exit(EXIT_FAILURE);
    }

    new->line = line;
    strcpy(new->command, command);
    new->argument = argument;

    new->next = NULL;

    return new;
}

struct node *append_node(struct node *start, struct node *new)
{
    assert(start != NULL);

    struct node *current = start;
    
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new;

    return new;
}

void print_node(struct node *n)
{
    printf("%2d %s %x\n", n->line, n->command, n->argument);
}

int getsize(struct node * head)
{
	int size = 0;
	for(head = head; head != NULL; head= head->next )
	{
		size++;
	}
	return size;
}


void print_list(struct node *start)
{
    struct node *current = start;

    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
}

struct node *create_list(void)
{
    struct node *head, *next;
    int line = 1;

    head = create_node(line++, "set", 0x1);
    next = append_node(head, create_node(line++, "shl", 0x1));
    next = append_node(next, create_node(line++, "shl", 0x1));
    next = append_node(next, create_node(line++, "or", 0x1));
    next = append_node(next, create_node(line++, "or", 0x2));
    next = append_node(next, create_node(line++, "shl", 0x2));
    next = append_node(next, create_node(line++, "xor", 0x10));
    next = append_node(next, create_node(line++, "xor", 0x10));
    next = append_node(next, create_node(line++, "and", 0x4));
    next = append_node(next, create_node(line++, "set", 0x1c));
    next = append_node(next, create_node(line++, "and", 0x3));
    next = append_node(next, create_node(line++, "set", 0x1c));
    next = append_node(next, create_node(line++, "shr", 0x1));

    return head;
}

void free_list(struct node *start)
{
    struct node *prev, *current;

    current = start;
    while (current != NULL) {
        prev = current;    
        current = current->next;
        free(prev);
    }
}

uint8_t bit_comp = 0;
int counter = 0;

void step(struct node *head)
{
	//struct *temp = head;
	assert(head != NULL);
	for(int i = 0;i < counter; i++)
	{
		if(head->next != NULL)
		{
			head = head->next;
		}
	}
	if(head->next != NULL)
	{
		if(strcmp(head->command,"set") == 0)
		{
			bit_comp = head->argument;
		//	head = head->next;
		}
		else if(strcmp(head->command,"shl") == 0)
		{
			bit_comp = bit_comp << head->argument;
		//	head = head->next;
		}
		else if(strcmp(head->command,"shr") == 0)
		{
			bit_comp = bit_comp >> head->argument;
		//	head = head->next;
		}
		else if(strcmp(head->command,"and") == 0)
		{
			bit_comp &= head->argument;
		//	head = head->next;
		}
		else if(strcmp(head->command,"or") == 0)
		{
			bit_comp |= head->argument;
		//	head = head->next;
		}
		else if(strcmp(head->command,"xor") == 0)
		{
			bit_comp ^= head->argument;
		//	head = head->next;
		}
		
		counter++;
	}
	else
	{
		if(strcmp(head->command,"set") == 0)
		{
			bit_comp = head->argument;
		//	head = head->next
		//	printf("Went wrong in set");
		}
		else if(strcmp(head->command,"shl") == 0)
		{
			bit_comp = bit_comp << head->argument;
		//		printf("Went wrong in shl");
		//	head = head->next;
		}
		else if(strcmp(head->command,"shr") == 0)
		{
			bit_comp = bit_comp >> head->argument;
		//		printf("Went wrong in shr");
		//	head = head->next;
		}
		else if(strcmp(head->command,"and") == 0)
		{
			bit_comp &= head->argument;
		//		printf("Went wrong in and");
		//	head = head->next;
		}
		else if(strcmp(head->command,"or") == 0)
		{
			bit_comp |= head->argument;
		//		printf("Went wrong in or");
		//	head = head->next;
		}
		else if(strcmp(head->command,"xor") == 0)
		{
			bit_comp ^= head->argument;
		//		printf("Went wrong in xor");
		//	head = head->next;
		}
		
		counter++;
	}
}
void cont(struct node * head)
{
	int size = 0;
		size = getsize(head);
	for(int i = counter;i <  size; i++)
	{
		step(head);
	}
}

void print()
{
	printf("%x\n",bit_comp);
}

/*
struct node {
    int line;
    char command[MAX_COMMAND_SIZE + 1];
    unsigned int argument;

    struct node *next;
};

*/


void list (struct node *head , int i)
{
	struct node * curr;
	struct node * prev;
	int size = 0;
	size = getsize(head);
	
	int counter = 1;
	assert(head != NULL);
	curr = head;
	prev = head;
	if(curr->next != NULL)
	{
		curr = curr-> next;
		
	}
	for(counter = counter; counter <= 12; counter++)
	{
		if(i== 0 && i == counter - 1)
		{
			 printf("%2d %s %x\n", prev->line,prev->command,prev->argument );
			 printf("%2d %s %x\n", curr->line,curr->command,curr->argument );
		}
		else if ( i >= counter && counter >= size-1)
		{
			printf("%2d %s %x\n", prev->line,prev->command,prev->argument );
			 printf("%2d %s %x\n", curr->line,curr->command,curr->argument );
		}
		else if( i == counter && curr->next != NULL)
		{
			printf("%2d %s %x\n", prev->line,prev->command,prev->argument );
			 printf("%2d %s %x\n", curr->line,curr->command,curr->argument );
			 printf("%2d %s %x\n", curr->next->line,curr->next->command,curr->next->argument );
		}
		else
		{
			if(curr != NULL)
			{
				curr = curr-> next;
				prev = prev->next;
			}
		}
	}
	
	
}




int main(void)
{
    struct node *head = create_list();

  char command[GDB_COMMAND_SIZE];

    while (scanf("%s", command) != EOF) {

        if (strcmp(command, "step") == 0) {
            step(head);
		//	printf("%d %s %d",head->line,head->command,head->argument);
        } else if (strcmp(command, "continue") == 0) {
            cont(head);
        } else if (strcmp(command, "print") == 0) {
            print();
        } else if (strcmp(command, "list") == 0) {
            list(head,counter);
        }

    }
	
	free_list(head);
    return EXIT_SUCCESS;
}