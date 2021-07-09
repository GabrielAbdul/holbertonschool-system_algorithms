#include "rb_trees.h"
#include "2-rb_tree_insert.c"

/**
 * rb_tree_remove - removes a node from a Red-Black tree
 * @root: root node
 * @n: value of node to remove
 * Return: new root of tree
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *removed_node, *replacement_node;

	/* need to find the node were trying to remove */
	removed_node = find_node(root, n);
	if (!removed_node)
		return (root);

	/* transferring removed node to laef position */
	while (is_not_leaf(removed_node))
	{
		replacement_node = find_replacement(removed_node);
		removed_node->n = replacement_node->n;
		removed_node = replacement_node;
	}

	if (removed_node == root)
	{
		free(removed_node);
		return (NULL);
	}
	if (removed_node->color == BLACK)
		rb_tree_repair_remove(removed_node, &root);

	if (removed_node->parent->right == removed_node)
		removed_node->parent->right = NULL;
	else
		removed_node->parent->left = NULL;

	free(removed_node);
	return (root);
}

/**
 * rb_tree_repair_remove - helper
 * @removed: removed node
 * @root: root node
 */
void rb_tree_repair_remove(rb_tree_t *removed, rb_tree_t **root)
{
	rb_tree_t *sibling;

	sibling = get_sibling(removed);

	/* CASE 1 */
	if (sibling && sibling->color == RED)
	{
		sibling->parent->color = RED;
		sibling->color = BLACK;
		if (sibling->parent == (*root))
			(*root) = sibling;
		if (removed == sibling->parent->left)
			rb_tree_rotate_left(sibling->parent);
		else
			rb_tree_rotate_right(sibling->parent);
		rb_tree_repair_remove(removed, root);
		return;
	}

	/* CASE 2 */
	if (!sibling || (is_black(sibling->left) && is_black(sibling->right)))
	{
		if (sibling)
			sibling->color = RED;
		if (removed != (*root))
		{
			if (removed->parent->color == RED)
				removed->parent->color = BLACK;
			else
				rb_tree_repair_remove(removed->parent, root);
		}
		return;
	}

	/* CASE 3 */
	rotate_parent(removed, sibling, root);
	return;
}

/**
 * rotate_parent - rotates paretn
 * @rem: removed node
 * @sib: sibling node
 * @root: root node
 */
void rotate_parent(rb_tree_t *rem, rb_tree_t *sib, rb_tree_t **root)
{
	rb_color_t tmp;
	rb_tree_t *close_neph, *far_neph;

	if (rem == rem->parent->left)
	{
		close_neph = sib->left;
		far_neph = sib->right;
	}
	else
	{
		far_neph = sib->left;
		close_neph = sib->right;
	}
	/* CASE 1 */
	if (close_neph && close_neph->color == RED)
	{
		sib->color = RED;
		close_neph->color = BLACK;
		if (close_neph == sib->left)
			rb_tree_rotate_right(sib);
		else
			rb_tree_rotate_left(sib);
		sib = get_sibling(rem);
		if (rem == rem->parent->left)
		{
			close_neph = sib->left;
			far_neph = sib->right;
		}
		else
		{
			far_neph = sib->left;
			close_neph = sib->right;
		}
	}
	/* CASE 2 */
	far_neph->color = BLACK;
	tmp = sib->color;
	sib->color = sib->parent->color;
	sib->parent->color = tmp;
	if(rem->parent == (*root))
		(*root) = sib;
	if (rem == rem->parent->left)
		rb_tree_rotate_left(rem->parent);
	else
		rb_tree_rotate_right(rem->parent);
}

/**
 * get_sibling - gets sibling node
 * @node: node to get sibling of
 * Return: sib
 */
rb_tree_t *get_sibling(rb_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}

/**
 * find_replacement - finds node replacement
 * @node: node to find replacement fo
 * Return: replacement
 */
rb_tree_t *find_replacement(rb_tree_t *node)
{
	if (!node->right)
		return (node->left);
	node = node->right;
	while (node->left)
		node = node->left;
	return (node);
}

/**
 * find_node - finds node given a value
 * @tree: tree
 * @value: value
 * Return: node
 */
rb_tree_t *find_node(rb_tree_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return (tree);

	if (tree->n > value)
		return find_node(tree->left, value);
	return find_node(tree->right, value);
}