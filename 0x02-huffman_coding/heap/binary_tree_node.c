#include "heap.h"

/**
 * binary_tree_node - creates a generic binary tree node
 * @parent: parent node of node to create
 * @data: node data to assign
 * Return: new node or NULL on failure
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *btn = malloc(sizeof(binary_tree_node_t));

	if (btn == NULL)
		return (NULL);

	btn->data = data;
	btn->parent = parent;
	btn->left = NULL;
	btn->right = NULL;

	return (btn);
}
