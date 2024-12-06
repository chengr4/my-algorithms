/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Feng-Shih Cheng
 * Email: chengf@oregonstate.edu
 */

#include <stdlib.h>

#include "pq.h"
#include "dynarray.h"
#include <stdio.h>
/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data neededi to implement a priority queue.
 */
struct pq {
   struct dynarray* dynarr;
};

/*
 *
 */
struct hnode {
    void* value;
    int priority;
};

/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
    struct pq* pq = malloc(sizeof(struct pq));
    struct dynarray* dynarr = dynarray_create();
    pq->dynarr = dynarr;
	return pq;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
    // free each node
    for (int i = 0;i<dynarray_size(pq->dynarr);i++) {
        free(dynarray_get(pq->dynarr, i));
    }
    dynarray_free(pq->dynarr);
    free(pq);
    return;
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
   if (dynarray_size(pq->dynarr)==0) {
        return 1;
   }
   return 0;
}

/**
 * This function takes two integer arguments and compares them. If the first integer
 * is less than the second integer, it returns 1. Otherwise, it returns 0.
 */
int pick_min(int a, int b) {
    if (a < b) {
       return 1;
    }

    return 0;
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *i   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
    int next_open_spot = dynarray_size(pq->dynarr);
    struct hnode* current_node = malloc(sizeof(struct hnode));
    current_node->value = value;
    current_node->priority = priority;

    // Add the node to the end of the heap to add the array size
    dynarray_insert(pq->dynarr, current_node);

    // case: root
    if (next_open_spot == 0) {
	return;
    }

    // case: other position
    int parent_index = (next_open_spot - 1) / 2;
    struct hnode* parent_node = dynarray_get(pq->dynarr, parent_index); 
    int parent_priority = parent_node->priority;

    while (next_open_spot > 0 && pick_min(priority, parent_priority) == 1) {
        // percolate up
	dynarray_set(pq->dynarr, next_open_spot, parent_node);
	next_open_spot = parent_index;

	if (next_open_spot > 0) {
	parent_index = (next_open_spot - 1) / 2;
	parent_node = dynarray_get(pq->dynarr, parent_index);
	parent_priority = parent_node->priority;
	}
    }
    dynarray_set(pq->dynarr, next_open_spot, current_node);
    
    return;
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {
    struct hnode* first_node = dynarray_get(pq->dynarr, 0);

    return first_node->value;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
    struct hnode* first_node = dynarray_get(pq->dynarr, 0);

    return first_node->priority;
}

/**
 * Swaps the elements at the specified indices in the dynamic array.
 *
 * @param da A pointer to the dynamic array.
 * @param i The index of the first element to swap.
 * @param j The index of the second element to swap.
 */
void _swap(struct dynarray* da, int i, int j) {
    void* temp = dynarray_get(da, i);
    dynarray_set(da, i, dynarray_get(da, j));
    dynarray_set(da, j, temp);

    return;
}

/**
 * This function ensures that the heap property is maintained by comparing the 
 * current node with its children and swapping it with the smaller child if necessary.
 * It recursively continues this process until the node is in the correct position.
 *
 * @param heap A pointer to the dynamic array representing the heap.
 * @param last_index The index of the last element in the heap.
 * @param curr_index The index of the current node to percolate down.
 */
void _percolate_down(struct dynarray* heap, int last_index, int curr_index) {
    int left_index = curr_index * 2 + 1;
    int right_index = curr_index * 2 + 2;
    if (right_index <= last_index) { // two children cases
        int smaller_index = 0;
	struct hnode* left_node = dynarray_get(heap, left_index);
	int left_priority = left_node->priority;
	struct hnode* right_node = dynarray_get(heap, right_index);
        int right_priority = right_node->priority;
	if(left_priority < right_priority) {
            smaller_index = left_index;   
	} else {
	    smaller_index = right_index;
	}

	struct hnode* child_node_to_compare = dynarray_get(heap, smaller_index);
	struct hnode* current_node = dynarray_get(heap, curr_index);
	if(pick_min(child_node_to_compare->priority, current_node->priority) == 1) {
	    _swap(heap, curr_index, smaller_index);
	    _percolate_down(heap, last_index, smaller_index); 
	}
    } else if (left_index <= last_index) { // one children cases
        struct hnode* child_node_to_compare = dynarray_get(heap, left_index);
        struct hnode* current_node = dynarray_get(heap, curr_index);
	if(pick_min(child_node_to_compare->priority, current_node->priority) == 1) {
            _swap(heap, curr_index, left_index);
            _percolate_down(heap, last_index, left_index);
        }
    }

    return;
}

/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {
    int new_last_position = dynarray_size(pq->dynarr) - 1;
    struct hnode* return_node = dynarray_get(pq->dynarr, 0);
    void* return_val = return_node->value;
    if(new_last_position != 0) {
	// copy the last element to the first
        dynarray_set(pq->dynarr, 0, dynarray_get(pq->dynarr, new_last_position));
    }
    free(return_node);
    dynarray_remove(pq->dynarr, new_last_position); // aka. size--
    // rebuild heap property
    _percolate_down(pq->dynarr, new_last_position-1, 0);

    return return_val;
}
