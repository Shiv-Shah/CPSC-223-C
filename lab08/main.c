#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_BYTE_COMMAND_SIZE 3
#define MAX_DEBUG_COMMAND_SIZE 8
#define PROGRAM_SIZE 13

struct node {
    int line;
    char command[MAX_BYTE_COMMAND_SIZE + 1];
    unsigned int argument;

    struct node *next;
};



struct node *head = NULL;
struct node *current = NULL;

uint8_t byte = 0;

struct node *create_node(int line, char *command, unsigned int argument)
{
    assert(strlen(command) <= MAX_BYTE_COMMAND_SIZE);

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

  //  struct node *current = start;
  current = start;
    
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

void print_list(struct node *start)
{
    //struct node *current = start;
	current = start;
    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
}



void free_list(struct node *start)
{
    struct node *prev;// *current;

    current = start;
    while (current != NULL) {
        prev = current;    
        current = current->next;
        free(prev);
    }
}

void do_step()
{
    if (current == NULL) {
        return;
    }

    if (strcmp(current->command, "set") == 0) {
        byte = current->argument;
    } else if (strcmp(current->command, "and") == 0) {
        byte &= current->argument;
    } else if (strcmp(current->command, "or") == 0) {
        byte |= current->argument;
    } else if (strcmp(current->command, "xor") == 0) {
        byte ^= current->argument;
    } else if (strcmp(current->command, "shr") == 0) {
        byte >>= current->argument;
    } else if (strcmp(current->command, "shl") == 0) {
        byte <<= current->argument;
    }

    current = current->next;
}

void do_continue()
{
    while (current != NULL) {
        do_step();
    }
}

void do_vcontinue()
{
    while (current != NULL) {
      	printf("%2d %s %x => %x\n", current->line, current->command, current->argument,byte);
        do_step();
        
    }
}






void do_print()
{
    printf("%x\n", byte);
}



struct node *find_prev(struct node *start)
{
    struct node *prev = head;

    while (prev->next != start) {
        prev = prev->next;
    }

    return prev;
}

void do_list(struct node *heads)
{
    if (current == heads) {
        print_node(current);
        print_node(current->next);
    } else if (current == NULL) {
        struct node *prev = find_prev(current);
        struct node *prevprev = find_prev(prev);

        print_node(prevprev);
        print_node(prev);
    } else {
        struct node *prev = find_prev(current);

        print_node(prev);
        print_node(current);
        print_node(current->next);
    }
}



int main(int argc, char * argv[])
{
	int verbose = 0;
	int debug = 0;
	int opt = 0;
	char str_val [5];
	unsigned int hex_val = 0;
	int line = 0;
	FILE *fp;
	
	
	// while loop that takes in argc,argv,and the values for the switch which would be -v and -d
	struct node  *next;
	
		
	while((opt = getopt(argc,argv,"dv"))!= -1) 
	{
		switch(opt)
		{
		case 'd':
			debug = 1;
		break;
		case 'v':
			verbose = 1;
		break;
		default:
			abort();
		break;
		}
	
	}
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	
	char debug_val[10];
	for(; optind < argc; optind++)
	{
		fp = fopen(argv[optind],"r");
	//	printf("%d",i);
		
		//printf("this is argv[optind] %s\n", argv[optind]);
		while(fscanf(fp,"%s %x",str_val,&hex_val) != EOF)
		{
			if(line == 0)
			{
				head = create_node(line++,str_val,hex_val);
		
			}
			else if(line == 1)
			{
				next = append_node(head, create_node(line++, str_val, hex_val));
			}
			else
			{
				next = append_node(next, create_node(line++, str_val, hex_val));
			}
	
		}
		fclose(fp);
	}
	current = head;
	
	if(debug == 1)
		{
		//int read = ;
			while(scanf("%s",debug_val) != EOF)
			{
				if(strcmp(debug_val,"print") == 0)
				{
					do_print();
				}
				else if(strcmp(debug_val,"step") == 0)
				{
					do_step();
				}
				else if(strcmp(debug_val,"continue") == 0)
				{
					do_continue();
				}
				else if(strcmp(debug_val,"list") == 0)
				{
					do_list(head);
				}
				else if(strcmp(debug_val,"quit") == 0)
				{
					abort();
				}
				else 
				{
					printf("invalid value");
				}
			
			}
		}
		//current = head;
		
		
		if(verbose == 1)
		{
			do_vcontinue();
		}
		
		if(verbose == 0 && debug == 0)
		{
			do_continue();
			do_print();
		
		}
	free_list(head);
	free_list(current);
	
//	printf("got to the end");
	
}
	
