#ifndef RB_TREES_H
#define RB_TREES_H

#include <limits.h>
#include <stdlib.h>

#define true 1
#define false 0

#define is_leaf(x)(!x->left && !x->right)
#define is_not_leaf(x) !is_leaf(x)
#define is_black(x) (!x || x->color == BLACK)

/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

int black_node_depth(const rb_tree_t *node, int black_depth);
int check_black_node_depths(const rb_tree_t *tree);
int is_binary_search_tree(const rb_tree_t *node, int min, int max);
void rb_tree_print(const rb_tree_t *tree);
void rb_tree_print(const rb_tree_t *tree);
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
int rb_tree_is_valid(const rb_tree_t *tree);
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
rb_tree_t *array_to_rb_tree(int *array, size_t size);
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n);
rb_tree_t *rb_tree_insert_right(rb_tree_t *parent, int value);
rb_tree_t *rb_tree_insert_left(rb_tree_t *parent, int value);
rb_tree_t *bst_insert(rb_tree_t *tree, int value);
void rb_tree_insert_uncle_black(rb_tree_t *tree, rb_tree_t *p, rb_tree_t *gp, rb_tree_t **root);
void rb_tree_repair(rb_tree_t *tree, rb_tree_t **root);
void rb_tree_rotate_right(rb_tree_t *tree);
void rb_tree_rotate_left(rb_tree_t *tree);
void rb_tree_repair_remove(rb_tree_t *removed, rb_tree_t **root);
void rotate_parent(rb_tree_t *rem, rb_tree_t *sib, rb_tree_t **root);
rb_tree_t *get_sibling(rb_tree_t *node);
rb_tree_t *find_replacement(rb_tree_t *node);
rb_tree_t *find_node(rb_tree_t *tree, int value);
/*void rb_tree_repair(rb_tree_t **root, rb_tree_t *tree);*/
/*rb_tree_t *rb_tree_insert_right(rb_tree_t **root, rb_tree_t *parent, int value);*/
/*rb_tree_t *rb_tree_insert_left(rb_tree_t **root, rb_tree_t *parent, int value);*/






#endif /* RB_TREES_H */
