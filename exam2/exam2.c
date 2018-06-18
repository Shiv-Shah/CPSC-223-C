// exam2.c - starter code for Exam 2

/*
 *  This code should compile cleanly with the following options:
 *
 
    -std=c11 -Wall -Wextra -Wpedantic -Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default -Wbad-function-cast -Wcast-qual -Waggregate-return

 */


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef WANT_BSTRING
#include "bstrlib.h"
#else
#include <string.h>
#endif

#define PRIORITY_SIZE 2

struct queue {
    struct queue_element *front;
    struct queue_element *back;
    int element_count;
};

struct queue_element {
    int label;
    struct queue_element *next;
};

struct queue *queue_create(void)
{
    struct queue *q = malloc(sizeof(struct queue));
    if (q == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    q->front = NULL;
    q->back = NULL;
    q->element_count = 0;

    return q;
}

void queue_add(struct queue *q, int label)
{
    assert(q != NULL);
    struct queue_element *qe = malloc(sizeof(struct queue_element));
    if (qe == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    if(q->front == NULL)
    {
    	qe->label = label;
    	qe->next = NULL;
    	//qe->back = NULL
    	q->front = qe;
    	q->back = qe;
    	q->element_count++;
    }
    else
    {
    	if(q->front->next == NULL)
    	{
    		qe->label = label;
    		qe->next = q->front;
    		q->back = qe;
    	}
    	else
    	{
    		qe->label = label;   		
    		qe->next = q->back;
    		q->back = qe;
    	}
    	
    	
    }
    
    

    // REMOVE THE FOLLOWING LINE BEFORE ADDING YOUR CODE
    //(void) label;

    // INSERT CODE HERE
}

int queue_remove(struct queue *q)
{
	int label = -1;
    assert(q != NULL);
    
    //int temp = 0;
    
    
	 struct queue_element *qe = malloc(sizeof(struct queue_element));
	 qe = q->back;
	 while (qe != q->front && qe->next != q->front)
	 {
	 	qe=qe->next;
	 }
	 if(qe->next == q->front)
	 {
	 label = q->front ->label;
	 	free(q->front);
	 	q->front = qe;
	 	free(qe);
	 	return label;
	 }
	 else if(qe == q->front)
	 {
	 	label = q->front->label;
	 	free (qe);
	 	return label;
	 }

  return -1;
  }
   

    



void queue_destroy(struct queue *q)
{
    assert(q != NULL);

    while (q->element_count > 0) {
        queue_remove(q);
    }

    free(q);
}

int main(int ardc, char*argv[])
{
	//char c;
	char *arg;
	int highvlow = 0;
    struct queue *high_priority = queue_create();
    struct queue *low_priority = queue_create();

    for(int i = 0; i < 2; i++)
    {
    	arg = argv[i];
    }
	
	if(strcmp(arg,"hi") == 0)
	{
		queue_add(high_priority,ardc);
	}
	else if(strcmp(arg,"lo") == 0)
	{
		queue_add(low_priority,ardc);
	}
	else
	{
		printf("invalid value");
	}
	
	int t = 0; int k = 0;
	while(t != -1)
	{
		if(k >=1 && high_priority != NULL)
		{
			queue_remove(high_priority);
			k++;
		}
		else
		{
			queue_remove(low_priority);
			k++;
		}
	}
	 
  

    queue_destroy(high_priority);
    queue_destroy(low_priority);

    return EXIT_SUCCESS;
}
