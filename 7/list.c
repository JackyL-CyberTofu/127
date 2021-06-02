#include <stdio.h>
#include <stdlib.h>

#include "list.h"


// TASK 1
// returns a pointer to a new header for an empty list, or NULL if
// memory allocation fails.

list_t* list_create( void )
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
void list_destroy( list_t* list )
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
element_t* element_create( int i )
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
int list_append( list_t* list, int i )
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
int list_prepend( list_t* list, int i )
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
element_t* list_index( list_t* list, unsigned int i )
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
void list_print( list_t* list )
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