#include "graphs.h"

/**
 * graph_delete - frees all allocated space used for graph and members
 * @graph: graph to delete
 */
void graph_delete(graph_t *graph)
{
	vertex_t *v;
	edge_t *e, *node;

	if (graph == NULL)
		exit(EXIT_FAILURE);

	if (graph->vertices == NULL)
		free(graph);
	else
	{
		v = graph->vertices;
		while (v)
		{
			if (v->edges)
			{
				e = v->edges;
				while (e)
				{
					if (e->next)
					{
						node = e;
						e = e->next;
						free(node);
					} else {
						free(e);
					}
				}
			}
			free(v->content);
			free(v);
		}
		free(graph->vertices);
	}
	free(graph);
}
