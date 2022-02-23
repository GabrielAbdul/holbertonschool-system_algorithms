#include "nary_trees.h"

/**
 * nary_tree_diameter - computes the diameter of an N-ary tree
 * @root: pointer to root node of tree
 * Return: diameter
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diameter = 0;
	nary_tree_t const *node;

	if (root == NULL)
		return (0);

	node = root;
	while (node)
	{
		if (node->children)
			diameter++;
		node = node->next;
		diameter++;
	}
	return (diameter);
}
