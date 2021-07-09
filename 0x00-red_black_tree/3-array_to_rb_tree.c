#include "rb_trees.h"

/**
 * array_to_rb_tree - builds an rb tree from an array
 * @array: arr to convert to rb tree
 * @size: size of array
 * Return: new tree
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
    size_t i;
    rb_tree_t *tree = NULL;

    if (!array)
        return (NULL);

    for (i = 0; i < size; i++)
        rb_tree_insert(&tree, array[i]);

    return (tree);
}

/**
 * bst_insert - inserts a node into a rb tree
 * for 2-rb_tree_insert.c
 * @tree: root of tree
 * @value: value new node will have once inserted
 * Return: new node
 */
rb_tree_t *bst_insert(rb_tree_t *tree, int value)
{
	if (tree == NULL)
	{
		tree = rb_tree_node(tree, value, BLACK);
		return (tree);
	}

	if (value < tree->n)
	{
		/**
		 * if there's a left child, then we recurse down that left child. and once
		 * there is no left child, THEN we insert left.
		 */
		if (tree->left == NULL)
			return (rb_tree_insert_left(tree, value));
		return (bst_insert(tree->left, value));
	}
	else if (value > tree->n)
	{
		if (tree->right == NULL)
			return (rb_tree_insert_right(tree, value));
		return (bst_insert(tree->right, value));
	}

	return (NULL);
}
