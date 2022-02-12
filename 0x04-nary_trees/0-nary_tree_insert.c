#include "nary_trees.h"

/**
 * nary_tree_insert -
 * @parent: parent to the pointer node
 * @str: string to be stored, must be duped
 * Return: pointer to new node
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
    nary_tree_t *node;

    node = malloc(sizeof(nary_tree_t *));

    if (node == NULL)
        return (NULL);

    node->content = strdup(str);
    node->nb_children = 0;
    node->children = NULL;

    if (parent == NULL)
    {
        node->parent = NULL;
        node->next = NULL;
        return (node);
    }

    node->next = parent->children;
    node->parent = parent;
    parent->children = node;
    parent->nb_children++;

    return node;
}