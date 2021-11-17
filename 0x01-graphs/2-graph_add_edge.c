#include "graphs.h"

/**
 * add_edges_to_vertices - add edge(s) between to vertices
 * @vsrc: source vertext pointer
 * @vdest: destination vertex pointer
 * Return: int
 */
int add_edges_to_vertices(vertex_t *vsrc, vertex_t *vdest)
{
	edge_t *edge, **edgep;

	for (edgep = &vsrc->edges; *edgep; edgep = &(*edgep)->next)
		if ((*edgep)->dest == vdest)
			return (0);

	if (vsrc == NULL || vdest == NULL)
		return (0);

	edge = malloc(sizeof(edge_t));
	if (!edge)
		return (0);

	edge->dest = vdest;
	edge->next = NULL;
	*edgep = edge;

	vsrc->nb_edges += 1;

	return (1);
}

/**
 * retrieve_vertices - finds 2 vertices based on their content
 * @graph: graph in which vertices are contained
 * @vsrc: vertex pointer we need to retrieve
 * @vdest: vertex pointer we need to retrieve
 * @vsrc_content: content we are searching for
 * @vdest_content: content we are searching for
 * Return: int
 */
int retrieve_vertices(graph_t *graph, vertex_t **vsrc, vertex_t **vdest, const char *vsrc_content, const char *vdest_content)
{
	vertex_t *v = NULL;

	/* loop through graph vertices to find match of content */
	v = graph->vertices;
	while (v)
	{
		/* find and update vertices we are trying to add edges to*/
		if (!strcmp(v->content, vsrc_content))
			*vsrc = v;
		if (!strcmp(v->content, vdest_content))
			*vdest = v;
		v = v->next;
	}
	return ((*vsrc == NULL || *vdest == NULL) ? 0 : 1);
}
/**
 * graph_add_edge - adds an edge between two vertices to an existing graph
 * @graph: pointer to the graph to add edge to
 * @src: src vertex edge is coming from
 * @dest: dest vertex edge is going to
 * @type: type
 * Return: 0
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
	vertex_t *vsrc = NULL, *vdest = NULL;

	if (!graph || !src || !dest || type > BIDIRECTIONAL)
		return (0);

	if (retrieve_vertices(graph, &vsrc, &vdest, src, dest) == 0)
		return (0);

	if (type == UNIDIRECTIONAL)
		return (add_edges_to_vertices(vsrc, vdest));

	add_edges_to_vertices(vsrc, vdest);
	add_edges_to_vertices(vdest, vsrc);
	return (1);
}
