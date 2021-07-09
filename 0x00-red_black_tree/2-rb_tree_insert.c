#include "rb_trees.h"
#include <stdlib.h>
#include "3-array_to_rb_tree.c"

/**
 * rb_tree_insert - inserts rb_tree_t node
 * @tree: tree
 * @value: value
 * Return: inserted node
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *node;

	node = bst_insert(*tree, value);
	if (!node)
		return (NULL);
	if (!tree)
		*tree = node;
	rb_tree_repair(node, tree);
	return (node);
}

/**
 * rb_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 **/
rb_tree_t *rb_tree_insert_left(rb_tree_t *parent, int value)
{
	rb_tree_t *tmp;
	rb_tree_t *node = rb_tree_node(parent, value, RED);

	if (parent->left == NULL)
	{
		parent->left = node;
		node->parent = parent;
	}
	else
	{
		tmp = parent->left;
		node->left = tmp;
		tmp->parent = node;
		parent->left = node;
	}
	return (node);
}
/**
 * rb_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 **/
rb_tree_t *rb_tree_insert_right(rb_tree_t *parent, int value)
{
	rb_tree_t *tmp;
	rb_tree_t *node = rb_tree_node(parent, value, RED);

	if (parent->right == NULL)
	{
		parent->right = node;
		node->parent = parent;
	}
	else
	{
		tmp = parent->right;
		node->right = tmp;
		tmp->parent = node;
		parent->right = node;
	}
	return (node);
}
/**
 * rb_tree_rotate_left - performs left rotation around node for an rb tree
 * @tree: node to rotate around
 */
void rb_tree_rotate_left(rb_tree_t *tree)
{
	rb_tree_t *node = tree->right;
	rb_tree_t *parent = tree->parent;

	tree->right = node->left;
	node->left = tree;
	tree->parent = node;

	if (tree->right != NULL)
		tree->right->parent = tree;

	if (parent)
	{
		if (tree == parent->left)
			parent->left = node;
		else if (tree == parent->right)
			parent->right = node;
	}

	node->parent = parent;
}

/**
 * rb_tree_rotate_right - performs right rotation around node for an rb tree
 * @tree: node to rotate around
 */
void rb_tree_rotate_right(rb_tree_t *tree)
{
	rb_tree_t *node = tree->left;
	rb_tree_t *parent = tree->parent;

	/* node is going to be the node that rotates over and takes tree's place */

	tree->left = node->right;
	node->right = tree;
	tree->parent = node;

	if (tree->left != NULL)
		tree->left->parent = tree;

	if (parent)
	{
		if (tree == parent->left)
			parent->left = node;
		else if (tree == parent->right)
			parent->right = node;
	}

	node->parent = parent;
}

/**
 * rb_tree_repair - repairs rb tree
 * @tree: node
 * @root: root
 */
void rb_tree_repair(rb_tree_t *tree, rb_tree_t **root)
{
	rb_tree_t *uncle, *grandparent;

	/* CASE 1 and 2 */
	if (tree->parent == NULL)
	{
		tree->color = BLACK;
		*root = tree;
		return;
	}

	if (tree->parent->color == BLACK)
		return;

	/* FIND UNCLE FOR CASES 3 AND 4 */
	/* make sure grandparent exists. if not, uncle is NULL */
	grandparent = tree->parent->parent;
	if (grandparent)
	{
		/* finding the uncle by checking the parent */
		if (grandparent->left == tree->parent)
			uncle = grandparent->right;
		else
			uncle = grandparent->left;
	}
	else
		uncle = NULL;

	/* CASE 3: Uncle is RED */
	if (uncle != NULL  && uncle->color == RED)
	{
		tree->parent->color = BLACK;
		uncle->color = BLACK;
		if (grandparent)
			grandparent->color = RED;
		rb_tree_repair(grandparent, root);
		return;
	}

	/* CASE 4: Uncle is BLACK */
	rb_tree_insert_uncle_black(tree, tree->parent, grandparent, root);
}


/**
 * rb_tree_insert_uncle_black - repairs case where uncle is black
 * @tree: pointer to tree
 * @p: parent of tree
 * @gp: grandparent of tree
 * @root: root of tree
 */
void rb_tree_insert_uncle_black(rb_tree_t *tree, rb_tree_t *p, rb_tree_t *gp, rb_tree_t **root)
{
	if (tree == p->right && p == gp->left)
	{
		rb_tree_rotate_left(p);
		tree = tree->left;
	}
	else if (tree == p->left && p == gp->right)
	{
		rb_tree_rotate_right(p);
		tree = tree->right;
	}

	p = tree->parent;
	gp = p->parent;

	if (tree == p->left)
		rb_tree_rotate_right(gp);
	else
		rb_tree_rotate_left(gp);

	p->color = BLACK;
	gp->color = RED;

	if (p->parent == NULL)
		*root = p;
}
