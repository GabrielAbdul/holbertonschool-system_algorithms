#include "nary_trees.h"

/**
 * nary_tree_traverse - will traverse an n-ary tree
 * @root: pointer to root node of tree
 * @action: action for each node
 * Return: max depth
 */
size_t nary_tree_traverse(nary_tree_t const *root,
	void (*action)(nary_tree_t const *node, size_t depth))
{
	if (root == NULL || action == NULL)
		return (0);
		
	return (helper(root, action, 0));
}

/**
 * helper - will traverse an n-ary tree
 * @root: pointer to root node of tree
 * @action: action for each node
 * @depth: current depth
 * Return: max depth
 */
size_t helper(nary_tree_t const *root,
	void (*action)(nary_tree_t const *node, size_t depth), size_t depth)
{
	size_t max_depth = depth, current_depth;

	if (!root)
		return (0);
	action(root, depth);
	current_depth = helper(root->children, action, depth + 1);
	max_depth = MAX(max_depth, current_depth);
	current_depth = helper(root->next, action, depth);
	max_depth = MAX(max_depth, current_depth);
	return (max_depth);
}