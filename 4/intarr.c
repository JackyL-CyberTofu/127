#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//#include "intarr.h"
typedef struct {
  int* data;
  unsigned int len;
} intarr_t;

// A type for returning status codes 
typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;

//task 1
// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len )
{    
    intarr_t *arr=malloc(sizeof(intarr_t));
    if (arr == NULL)
    {
        return NULL;
    }
    arr->len=len;
    arr->data=malloc(sizeof(int)*arr->len);
    return arr;
    
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia )
{
    if (ia != NULL)
    {
        free(ia);
    }
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia,
                           unsigned int index,
                           int val )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    else if (index < ia->len)
    {
        ia->data[index] = val;
        return INTARR_OK;
    }
    else
    {
        return INTARR_BADINDEX;
    }
}

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia,
                           unsigned int index,
                           int* i )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    else if (index<ia->len && i != NULL)
    {
        *i = ia->data[index];
        return INTARR_OK;
    }
    else
    {
        return INTARR_BADINDEX;
    }
}



/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
intarr_t* intarr_copy( const intarr_t* ia )
{
    intarr_t *duplicate=malloc(sizeof(intarr_t));
    if (duplicate==NULL)
    {
        return NULL;
    }
    duplicate->len=ia->len;
    duplicate->data=malloc(sizeof(int)*duplicate->len);
    //memcpy(duplicate->data, ia->data, ia->len*sizeof(int));
    int i;
    for (i=0;i<ia->len;i++)
    {
        duplicate->data[i]=ia->data[i];
    }
    return duplicate;
}


/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia )
{
    if (ia==NULL)
    {
        return INTARR_BADARRAY;
    }
    else
    {
        int i,k,min,minpos,tmp;
        min=ia->data[0];
        for (i=0;i<ia->len;i++)
        {
            min = ia->data[i];
            for (k=i;k<ia->len;k++)
            {
                if (ia->data[k]<=min)
                {
                    min=ia->data[k];
                    minpos=k;
                }
            }
            tmp=ia->data[i];
            ia->data[i]=min;
            ia->data[minpos]=tmp;
        }
        return INTARR_OK;
    }
}


