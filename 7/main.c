#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "list.h"

// TASK 1
// returns a pointer to a new header for an empty list, or NULL if
// memory allocation fails.

list_t* list_create2( void )
{
	list_t *new=malloc(sizeof(list_t));
	if (new )
	{
		new->head=NULL;
		new->tail=NULL;
		return new;
	}	
	return NULL;
}

// frees all the memory used by the list
void list_destroy2( list_t* list )
{
	element_t* curr = list->head;
	while (curr)
	{
		element_t* next = curr->next;
		free(curr);
		curr=next;
	}
	free(list);
}

// returns a pointer to a new list element containing integer i and
// next-pointer set to NULL, or NULL if memory allocation fails.
element_t* element_create2( int i )
{
	element_t *new=malloc(sizeof(element_t));
	if (new)
	{
		new->val = i;
		new->next = NULL;
		return new;
	}
	return NULL;
}

// Appends a new element containing integer i to the end of the
// list. Returns 0 on success, else 1.
int list_append2( list_t* list, int i )
{
  element_t* new = malloc(sizeof(element_t));
  if( new == NULL)
  {
  	return 1;
  }
  if (new)
  {
  	new->val = i;
  	new->next = NULL;
  }
  if( list->head == NULL ){
    list->head = new;
  }
  
  if( list->tail ){
    list->tail->next = new;
  }

  list->tail = new;
  return 0;
}
// Prepends a new element containing integer i to the head of the
// list. Returns 0 on success, else 1.
int list_prepend2( list_t* list, int i )
{
	element_t* new = malloc(sizeof(element_t));
	if( new == NULL)
    {
  	  return 1;
    }
    if (new)
    {
  	  new->val = i;
  	  new->next = NULL;
    }
    if (list->tail == NULL)
    {
    	list->tail = new;
    }
    if (list->head)
    {
    	new->next= list->head;
    }	
    list->head = new;
    return 0;
}

// Returns a pointer to the ith list element, where the list head is
// 0, head->next is 1, etc., or NULL if i is out of range (i.e. larger
// than (number of list elements -1 ))
element_t* list_index2( list_t* list, unsigned int i )
{
	element_t* curr = list->head;
	int k=0;
	if (list->head == NULL)
	{
		return NULL;
	}
	while(curr != NULL)
	{
		if (k==i)
		{
			return curr;
		}		
		k++;
		curr = curr->next;
	}
	return NULL;
}

// Prints a list in human-readable form from the first to last
// elements, between curly braces.
void list_print2( list_t* list )
{
	if (list->head == NULL || list->tail == NULL)
	{
		printf("{ }\n");
	}
	else{
		printf("{");
		element_t* curr;
		for (curr=list->head;curr;curr = curr->next)
		{
			printf(" %d,",curr->val);
		}
		printf(" }\n");
	}
}

int main()
{
	list_t* correct = list_create2();
	list_append2(correct, 6);
	list_append2(correct, 10);
	list_append2(correct, 15);
	list_append2(correct, 17);
	list_append2(correct, 20);
	list_append2(correct, 16);
	list_prepend2(correct, 3);
	list_print2(correct);

	list_t* incorrect = list_create();
	list_append(incorrect, 6);
	list_append(incorrect, 10);
	list_append(incorrect, 15);
	list_append(incorrect, 17);
	list_append(incorrect, 20);
	list_append(incorrect, 16);
	list_prepend(incorrect, 3);
	list_print(incorrect);

	printf("%d\n",list_index2(correct,4)->val);
	printf("%d\n",list_index(incorrect,4)->val);

	if (correct->head->val != incorrect->head->val)
		return 1;

	if (list_index2(correct,4)->val != list_index(incorrect,4)->val)
		return 1;
	
	if (incorrect->tail->next != NULL)  //t3
		return 1;
	
	list_t* incorrect2 = list_create();
	/* 
	if (incorrect2 != NULL)
		return 1;
	*/
	list_print(incorrect2);
    list_index(incorrect2,0);

	list_t* l1=list_create();
	element_t* n1=list_index(l1,1);
	
	if (n1!=NULL)     //t1
		return 1;

	list_t* t4=list_create();
	list_prepend(t4,5);      //t4
	if(t4->tail->val == NULL)
		return 1;
	
	list_t* t5=list_create();
	list_append(t5,5);      
	if(t5->head->val == NULL)
		return 1;
	
	list_index(correct, 99);
	
	char *bytes = malloc(1000); // grab 1k bytes from the heap
	memset(bytes, 0x1, 1000); // set them to 0x1
	free(bytes); // free them
	element_t *n2=element_create(5);      // t2

	return 0;


}