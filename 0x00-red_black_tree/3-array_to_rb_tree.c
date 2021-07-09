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
