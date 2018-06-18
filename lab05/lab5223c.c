// lab5.c - starter code for Lab 5

/*
 * Complete the definitions for the stack_*() functions so that main()
 * prints the reverse of its command-line arguments. For example:
 *
 *  $ ./reverse foo bar baz
 *  zab rab oof
 *
 * Be sure that your code passes "--leak-check=full" with Valgrind.
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct stack {
    struct stack_element *top;
    int element_count;
};

struct stack_element {
    unsigned char c;
    struct stack_element *next;
};

struct stack *stack_create(void)
{
    struct stack *s = malloc(sizeof(struct stack));
    if (s == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    // INSERT CODE HERE 
	// initialize the stack
	s->top = NULL;

    return s;
}

void stack_destroy(struct stack *s)
{
   
	assert(s != NULL);
	struct stack_element *c = NULL;
	while(s->top != NULL)
	{
		c = s->top;
		s->top = s->top->next;
		free(c);
	}
	//free(s->top);
	free(s);
//	s = NULL; stack_destroy(t);
    // INSERT CODE HERE
	// free all the memory allocation
}

void stack_push(struct stack *s, unsigned char c)
{
    assert(s != NULL);
	//struct stack *t =  malloc(sizeof(struct stack));
	if(s->top == NULL)
	{
		struct stack_element *se = malloc(sizeof(struct stack_element));
		se->c = c;
		se->next = NULL;
		s->top = se;
		//free(se);
	}
	else
	{
		struct stack_element *se = malloc(sizeof(struct stack_element));
		se->c = c;
		se->next = s->top;
		s->top = se;
		//free(se);
		
	}
	
	
	
	//*s = *t;
	//stack_destroy(t);
	

    // INSERT CODE HERE
}

//bool last_val = false;

int stack_pop(struct stack *s)
{
	
	assert(s != NULL);

    unsigned char c;
	struct stack_element *v = NULL;
	if(s->top != NULL)
	{
		c = s->top->c;
		v = s->top;
		s->top = s->top->next;
		free(v);
		return c;
	}
	return EOF;
	
	
	
}

int main(int argc, char *argv[])
{
    struct stack *s = stack_create();

    for (int i = argc - 1; i > 0; i--) {
        char *arg = argv[i];

        for (size_t j = 0; j < strlen(arg); j++) {
            stack_push(s, arg[j]);
		//	printf("%c ", arg[j]);
			
        }
		

        char c;
        while ((c = stack_pop(s)) != EOF) {
            printf("%c", c);
        }

        printf(" ");
    }
    printf("\n");

    stack_destroy(s);

    return EXIT_SUCCESS;
}