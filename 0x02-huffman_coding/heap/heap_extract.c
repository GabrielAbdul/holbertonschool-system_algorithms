#include "heap.h"

/**
 * swap - swap two nodes
 * @node1: node 1
 * @node2: node 2
 */
void swap(binary_tree_node_t *node1, binary_tree_node_t *node2)
{
	void *temp;

	temp = n1->data;
	n1->data = n2->data;
	n2->data = temp;
}

/**
 * sift_down - sifts down root node of a broken min binary heap
 * @heap: heap
 */
void sift_down(heap_t *heap)
{
	binary_tree_node_t *largest, *node;

	if (!heap || !heap->root || heap->size < 2)
		return;

	node = heap->root;
	while (node->left)
	{
		largest = node->left;
		if (node->right && heap->data_cmp(node->data, node->right->data) >= 0
			&& heap->data_cmp(node->right->data, node->left->data) < 0)
			swap(node->right, node), largest = node->right;
		else if (heap->data_cmp(node->left->data, node->data) <= 0)
			swap(node->left, node);
		node = largest;
	}
}

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 * @heap: heap
 * Return: data
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *bottom_node;
	void *data;

	if (!heap || !heap->root || heap->size <= 0)
		return (NULL);
	data = heap->root->data;

	/* get last node in tree */
	bottom_node = retrieve_nth_node(heap->root, heap->size);

	/* replace root node data with bottom node data */
	heap->root->data = bottom_node->data;

	if (bottom_node->parent)
	{
		/* remove the bottom node from the tree */
		if (bottom_node->parent->left == bottom_node)
			bottom_node->parent->left = NULL;
		else
			bottom_node->parent->right = NULL;
	}
	else
		heap->root = NULL;

	/* delete bottom node from memory */
	free(bottom_node);
	heap->size -= 1;
	/* fix heap */
	sift_down(heap);
	return (data);
}
