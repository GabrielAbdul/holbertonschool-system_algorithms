#include "graphs.h"

/**
 * graph_add_vertex - adds a vertex to a graph
 * @graph: input graph
 * @str: string data
 * Return: vertex, null on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	size_t j;
	vertex_t *vertex, *v;
	static size_t i;

	if (!graph || !str)
		return (NULL);

	/* set v = to head of verticies */
	v = graph->vertices;

	/* loop through existing vertices */
	while (v)
	{
		/* ensure there are no duplicates */
		if (!strcmp(v->content, str))
			return (NULL);

		/* ensure we stop on last non null node */
		if (v->next)
			v = v->next;
		else
			break;
	}
	/* instantiate new vertex */
	vertex = graph_create_vertex(str);
	graph->nb_vertices++;

	/* if the head of the vertices was NULL */
	if (v == NULL)
	{
		/* assign our vertex with index 0 */
		vertex->index = 0;
		/* make this vertex, head of vertices list */
		graph->vertices = vertex;
	}
	else
	{
		/* increment our vertex index */
		vertex->index = v->index++;
		/* add it to be the next vertex in list of vertices */
		v->next = vertex;
	}
	return (vertex);
}

/**
 * graph_create_vertex - creates vertex node
 * @str: string to copy over
 * Return: vertex
 */
vertex_t graph_create_vertex(const char *str)
{
	vertex_t *node = malloc(sizeof(vertex_t));

	if (!node)
		return (NULL);

	node->content = strdup(str);
	node->nb_edges = 0;
	node->edges = NULL;
	node->next = NULL;

	return (node);
}
