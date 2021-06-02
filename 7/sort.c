#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

// Creates and returns a new, empty list
list_t * LLcreate() {
    list_t * ret = malloc(sizeof(list_t));
    if (ret != NULL) {
        ret->head = NULL;
        ret->tail = NULL;
    }
    return ret;
}


// Adds a new element to the tail end of a list
void LLappend(list_t * intlist, int value) {
    element_t * newNode = malloc(sizeof(element_t));
    if (newNode != NULL) {
        newNode->val = value;
        LLappendNode(intlist, newNode);
    }
}


// Adds a new element_t to the tail end of a list
// Pre:  newNode != NULL
void LLappendNode(list_t * intlist, element_t * newNode) {
    if (newNode != NULL) {
        newNode->next = NULL;
        if (intlist->tail == NULL) {
            // empty list
            assert(intlist->head == NULL);
            intlist->head = newNode;
            intlist->tail = newNode;
        } else {
            // non empty list
            intlist->tail->next = newNode; // seg fault
            intlist->tail = newNode;
        }
    }
}


// Outputs the list elements in order from head to tail
void LLprint(list_t * intlist) {
    // for ( init ; entry ; increment ) {
    for ( element_t * current = intlist->head; current != NULL ; current = current->next ) {
        printf(" %d", current->val);
    }
    putchar('\n');

    /*
    element_t * current = intlist->head;
    while (current != NULL) {
        printf(" %d", current->val);
        current = current->next;
    }
    putchar('\n');
    */
}


// Return 1 iff target in intlist; 0 otherwise
int LLsearch(list_t * intlist, int target) {
    // for ( init ; entry ; increment ) {
    /*
    for ( element_t * current = intlist->head; current != NULL ; current = current->next ) {
        printf(" %d", current->val);
    }
    putchar('\n');
    */

    /*
    element_t * current = intlist->head;
    while (current != NULL) {
        if (current->val == target) {
            return 1;
        }
        current = current->next;
    }
    return 0;
    */

    if (intlist->head == NULL) {
        assert(intlist->tail == NULL);
        return 0;
    }
    if (intlist->head->val == target) {
        return 1;
    }
    list_t rest; rest.head = intlist->head->next; rest.tail = (rest.head == NULL) ? NULL : intlist->tail;
    return LLsearch(&rest, target);
}


// joins different L1, L2 such that L1 <- L1 + L2, frees L2
void LLcatenate(list_t * L1, list_t * L2) {
    if (L2->head == NULL) {
        assert(L2->tail == NULL);
    } else if (L1->head == NULL) {
        assert(L1->tail == NULL);
        //L1->head = L2->head;
        //L1->tail = L2->tail;
        *L1 = *L2;
    } else {
        L1->tail->next = L2->head;
        L1->tail= L2->tail;
    }
    free(L2);
}

void list_sort(list_t * intlist) {
    // base case:  0 or 1 node
    if (intlist->head == intlist->tail) {
        return;
    }

    // remove the head from intlist (pivot)
    int pivot = intlist->head->val;
    element_t * pivot_node = intlist->head;
    intlist->head = intlist->head->next;

    // partition
    list_t * first = LLcreate();
    list_t * second = LLcreate();
    element_t * curr = intlist->head;
    element_t * next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = NULL;
        if (curr->val <= pivot) {
            LLappendNode(first, curr);
        } else {
            LLappendNode(second, curr);
        }
        curr = next;
    }
    intlist->head = NULL;
    intlist->tail = NULL;

    //LLprint(first);
    //LLprint(second);

    list_sort(first);
    list_sort(second);

    // join
    LLcatenate(intlist, first);
    LLappendNode(intlist, pivot_node);
    LLcatenate(intlist, second);
}

// Pre/Post:  intlist is sorted; newNode contains val already
void LLinsertNode(list_t * intlist, element_t * newNode) {
    // list empty
    if (intlist->head == NULL) {
        assert(intlist->tail == NULL);
        intlist->head = newNode;
        intlist->tail = newNode;
        newNode->next = NULL;
    } else if (intlist->head->val >= newNode->val) {
        // new head
        newNode->next = intlist->head;
        intlist->head = newNode;
    } else {
        // typical case
        element_t * prev = intlist->head;
        element_t * curr = intlist->head->next;
        while (curr != NULL && curr->val < newNode->val) { // insertion pt found while is False
            curr = curr->next;
            prev = prev->next;
        }
        newNode->next = curr;
        prev->next = newNode;
        if (curr == NULL) {
            // new tail
            intlist->tail = newNode;
        }
    }
}


// Pre: intlist not sorted
// Post:  values in intlist are in sorted order
void LLinsertionSort(list_t * intlist) {
    // create a new [empty] list
    list_t * newlist = LLcreate();

    // scan through all items and insert 'em
    element_t * curr = intlist->head;
    while (curr != NULL) {
        element_t * next = curr->next;
        LLinsertNode(newlist, curr);
        curr = next;
    }

    // recycle old list
    // swap
    list_t tmp; 
    tmp = *intlist;
    *intlist = *newlist;
    *newlist = tmp;
    free(newlist);
    //LLdestroy(newlist);


}
