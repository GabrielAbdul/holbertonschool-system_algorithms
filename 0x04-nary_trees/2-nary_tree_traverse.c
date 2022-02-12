#include "nary_trees.h"


/**
 * nary_tree_traverse - traverses an nary tree
 * @root: root node of tree to traverse
 * @action: function to perform on each node
 * @node: node being traversed
 * @depth: depth of the node being traversed
 * Return: biggest depth
 */
size_t nary_tree_traverse(nary_tree_t const *root, void (*action)(nary_tree_t const *node, size_t depth))
{
    size_t current_depth = 0, max_depth;

    if (root == NULL)
        return (zero_depth);

    while (root)
    {
        action(root, current_depth++);
        max_depth = nary_tree_traverse(root->children, action);
        root = root->next;
        if (max_depth > current_depth)
            current_depth = max_depth;
    }
    return (max_depth);
}