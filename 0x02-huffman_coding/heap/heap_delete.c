#include "heap.h"
/**
 * binary_tree_delete - deallocates a binary tree
 * @root: root node of tree
 * @free_data: used to free node content
 */
void binary_tree_delete(binary_tree_node_t *root, void (*free_data)(void *))
{
	if (root == NULL)
		return;

	binary_tree_delete(root->left, free_data);
	binary_tree_delete(root->right, free_data);

	if (free_data != NULL)
		free_data(root->data);

	free(root);
}
/**
 * heap_delete - deallocates a heap
 * @heap: pointer to the heap to free
 * @free_data: function that will be used to free nodes content
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (heap == NULL)
		return;

	binary_tree_delete(heap->root, free_data);
	free(heap);
}
