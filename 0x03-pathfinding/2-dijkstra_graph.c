#include "pathfinding.h"
#define CHECK "Checking %s, distance from %s is %d\n"

static int *dis;
static vertex_t **from;
static vertex_t **verts;
static ssize_t i, d, j = -1;
static char *str;

/**
 * dijkstra_graph - uses Dijkstra's pathfinder algorithm
 * @graph: pointer to graph struct
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 * Return: path queue or NULL
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
	vertex_t const *target)
{
	vertex_t *vertex;
	edge_t *e;
	queue_t *path = queue_create();

	if (!graph || !start || !target || !path)
		return (NULL);
	dis = calloc(graph->nb_vertices, sizeof(*dis));
	if (!dis)
		return (NULL);
	from = calloc(graph->nb_vertices, sizeof(*from));
	if (!from)
		return (NULL);
	verts = calloc(graph->nb_vertices, sizeof(*verts));
	if (!verts)
		return (NULL);
	for (vertex = graph->vertices; vertex; vertex = vertex->next)
		verts[vertex->index] = vertex, dis[vertex->index] = INT_MAX;
	dis[start->index] = 0, from[start->index] = NULL;
	while (j != (ssize_t)target->index)
	{
		j = -1, i = 0;
		for (d = INT_MAX; i < (ssize_t)graph->nb_vertices; i++)
			if (dis[i] >= 0 && dis[i] < d)
				d = dis[i], j = i;
		if (j == -1)
			break;
		printf(CHECK, verts[j]->content, start->content, dis[j]);
		for (e = verts[j]->edges; e; e = e->next)
			if (dis[e->dest->index] >= 0 && dis[j] + e->weight < dis[e->dest->index])
				dis[e->dest->index] = dis[j] + e->weight, from[e->dest->index] = verts[j];
		dis[j] = -1;
	}
	if (j != -1)
		for (queue_push_front(path, STRDUP(verts[j]->content));
			j != (ssize_t)start->index; j = from[j]->index)
			queue_push_front(path, STRDUP(from[j]->content));
	else
		path = (free(path), NULL);
	free(dis), free(from), free(verts);
	return (path);
}
