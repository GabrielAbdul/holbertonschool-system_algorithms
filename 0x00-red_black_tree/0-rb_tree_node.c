#include "rb_trees.h"


/**
 * rb_tree_node - creates a Red Black tree node
 * @parent: parent node
 * @value: value
 * @color: red or black
 * Return: node we created
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *node;

	/* if parent is NULL */
	if (parent == NULL)
	{
		/* make parent root */
		parent = malloc(sizeof(rb_tree_t));
		if (parent == NULL)
			return (NULL);

		/* init node values */
		parent->n = value;
		parent->color = color;
		parent->left = NULL;
		parent->right = NULL;
		parent->parent = NULL;

		return (parent);
	}

	/* otherwise create a new node */
	node = malloc(sizeof(rb_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->color = color;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
