#include "graphs.h"

/**
 * graph_create - function that allocates memory to store
 * a graph_t structure, and initializes its content.
 * Return: allocated graph, or NULL on failure
 */
graph_t *graph_create(void)
{
	graph_t *graph;

	graph = malloc(sizeof(graph_t));

	if (!graph)
		return (NULL);

	graph->nb_vertices = 0;
	graph->vertices = NULL;

	return (graph);
}
