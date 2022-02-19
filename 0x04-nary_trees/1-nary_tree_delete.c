#include "nary_trees.h"

/**
 * nary_tree_delete - deletes a whoel nary tree
 * @tree: tree to delete
 */
void nary_tree_delete(nary_tree_t *tree)
{

	nary_tree_t *node = NULL;

	while (tree)
	{
		node = tree;
		tree = tree->next;
		free(node->content);
		nary_tree_delete(node->children);
		free(node);
	}
}
