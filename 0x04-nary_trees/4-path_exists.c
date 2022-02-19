#include "nary_trees.h"

/**
 * path_exists - checks if a path exists in an N-ary tree
 * @root: pointer to the root node of the tree
 * @path: NULL terminated array of strings
 * Return: 1 if all elements of path are present in tree
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
    int result;
    nary_tree_t const *node;

    /* if root is NULL there is no path */
    if (root == NULL)
        return (0);

    /* loop through level 0 tree nodes */
    node = root;
    while (node)
    {
        result = path_exists_recursive(node, path, 0);
        /* if a match isnt found */
        if (result > 0)
            /* check the next node */
            node = node->next;
        else
            return (result);
    }
    return (1);
}
/**
 * path_exists_recursive - helper that checks if path exists
 * @root: pointer to root node
 * @path: path to find
 * @level: level of tree we're at
 * Return: 1 if path exists, else 0
 */
int path_exists_recursive(nary_tree_t const *root, char const * const *path, int level)
{
    nary_tree_t const *node;

    if (root == NULL)
        return (0);

    node = root;
    while (node && path[level])
    {
        /* check this nodes content with corresponding path */
        if (strcmp(node->content, path[level]) == 0)
        {
            /* if we found a match, check for the next part in the path */
            node = node->children;
            path_exists_recursive(node, path, level++);
        } else {
            node = node->next;
        }
    }
    /* if we reached here and path[level] is NULL then we've checked every
     * part of the path */
    if (path[level] == NULL)
        return (1);
    return (0);
}
