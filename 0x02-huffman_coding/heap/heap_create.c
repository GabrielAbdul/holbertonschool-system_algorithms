#include "heap.h"

/**
 * heap_create - creates a heap data structure
 * @data_cmp: pointer to a comparison function
 *		takes two void * parameters, each one being the data stored in a node
 *		will return the difference between the two data stored at those pointers
 *		used to determine if a node’s value is greater or lower than another
 * Return: pointer to new heap
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap = malloc(sizeof(heap_t));

	if (heap == NULL)
		return (NULL);

	heap->root = NULL;
	heap->size = 0;
	heap->data_cmp = data_cmp;

	return (heap);
}
