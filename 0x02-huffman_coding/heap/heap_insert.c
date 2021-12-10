#include "heap.h"
/**
 * retrieve_nth_node - gets nth node of binary_tree
 * @node: root
 * @n: index of node
 * Return: node specified
 */
binary_tree_node_t *retrieve_nth_node(binary_tree_node_t *node, size_t n)
{
	int index = 0, mask;

	for (index = 0; 1 << (index + 1) <= (int)n; ++index)
		;
	for (--index; index >= 0; --index)
	{
		mask = 1 << index;
		if (n & mask)
		{
			if (node->right)
				node = node->right;
			else
				break;
		}
		else
		{
			if (node->left)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

/**
 * heapify - fixes broken heap
 * @heap: heap to fix
 * @node: node to sift up
 * Return: node that was added to heap
 */
binary_tree_node_t *heapify(heap_t *heap, binary_tree_node_t *node)
{
	void *temp;

	if (!node || !node->parent)
		return (node);

	while (node->parent)
	{
		if (heap->data_cmp(node->parent->data, node->data) > 0)
		{
			temp = node->data;
			node->data = node->parent->data;
			node->parent->data = temp;
		}
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - inserts a value into a Min Binary Heap
 * @heap: pointer to heap in which node has to be inserted
 * @data: pointer containing the data to store in the new node
 * Return: node containing data or NULL on failure
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *parent, *bst_node;

	/* if heap or data is NULL return NULL */
	if (heap == NULL || data == NULL)
		return (NULL);

	/* if the first node in tree is NULL, create the root */
	if (heap->root == NULL)
	{
		heap->root = binary_tree_node(NULL, data);
		if (heap->root == NULL)
			return (NULL);
		heap->size = 1;
		return (heap->root);
	}

	/* allocate space for new node */
	bst_node = binary_tree_node(NULL, data);

	/* findind parent of last available insertable position */
	parent = retrieve_nth_node(heap->root, heap->size + 1);

	/* connect the nodes */
	if (parent->left == NULL)
		parent->left = bst_node;
	else
		parent->right = bst_node;
	bst_node->parent = parent;

	heap->size += 1;
	return (heapify(heap, bst_node));

}
