#include "huffman.h"

/**
 * cmp_node_freq - compare requency value of nodes
 * @p1: pointer 1
 * @p2: pointer 2
 * Return: the difference between the first and second frequency
 */
int cmp_node_freq(void *p1, void *p2)
{
	binary_tree_node_t *n1, *n2;
	symbol_t *s1, *s2;

	/* assign nodes so we can access node values */
	n1 = (binary_tree_node_t *)p1;
	n2 = (binary_tree_node_t *)p2;

	/* assign symbol pointers */
	s1 = (symbol_t *)n1->data;
	s2 = (symbol_t *)n2->data;

	/* return the difference in the character frequencies */
	return (s1->freq - s2->freq);
}

/**
 * huffman_priority_queue - create a priority queue out of arrays of
 * character data and their respective frequencies
 * @data: array of characters of size size
 * @freq: array containing the associated frequencies
 * @size: size of arrays
 * Return: pointer to min heap
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *heap;
	symbol_t *symbol;
	binary_tree_node_t *node;
	size_t i;

	/* create heap */
	heap = heap_create(cmp_node_freq);

	for (i = 0; i < size; i++)
	{
		/* create symbols */
		symbol = symbol_create(data[i], freq[i]);
		/* make node */
		node = binary_tree_node(NULL, symbol);
		/* insert node into heap */
		node = heap_insert(heap, node);
	}

	return (heap);
}
