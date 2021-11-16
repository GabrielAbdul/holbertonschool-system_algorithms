#include "graphs.h"

/**
 * graph_delete - frees all allocated space used for graph and members
 * @graph: graph to delete
 */
void graph_delete(graph_t *graph)
{
    vertex_t *v, tmp;
    edge_t *e, *next;

    if (graph == NULL)
        exit(EXIT_FAILURE);

    if (graph->vertices == NULL)
        free(graph);
    else
    {
        v = graph->verticies;
        while (v)
        {
            if (v->edges)
            {
                e = v->edges;
                while (e)
                {
                    if (e->next)
                        tmp = e->next;
                    free(e)
                    e = tmp;
                }
            }
            free(v->content);
            free(v)
        }
        free(graph->vertices);
    }
    free(graph);

        
}