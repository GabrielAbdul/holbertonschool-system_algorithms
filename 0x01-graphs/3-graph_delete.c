#include "graphs.h"

/**
 * graph_delete - frees all allocated space used for graph and members
 * @graph: graph to delete
 */
void graph_delete(graph_t *graph)
{
	vertex_t *v, *tmp;
	edge_t *e, *node;

	if (graph == NULL)
		exit(EXIT_FAILURE);

	v = graph->vertices;
	while (v)
	{
		tmp = v;
		v = v->next;
		e = tmp->edges;
		while (e)
		{
			node = e;
			e = e->next;
			free(node);
		}
		free(tmp->content);
		free(tmp);
	}
	free(graph);
}
