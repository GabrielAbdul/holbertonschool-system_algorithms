#include "graphs.h"


/**
 * dft_traversal - helper
 * @v: head of vertices list
 * @action: action to perform on each vertex
 * @grey_nodes: int [] where each element represents GREY or WHITE
 *              nodes. WHITE are unvisited nodes.
 * @depth: depth to keep track of and return
 * Return: total depth of graph
 */
size_t dft_traversal(const vertex_t *v, action_t action, int *grey_nodes, size_t depth)
{
	edge_t *edge;
	size_t current_depth, total_depth;

	/* if we're at grey node get outta there */
	if (grey_nodes[v->index] == GREY)
		return (depth - 1);

	/* turn visited vertex grey */
	grey_nodes[v->index] = GREY;

	/* perform action on visited vertex if unseen */
	action(v, depth);

	edge = v->edges;
	/* use edges to loop through each vertex */
	while (edge)
	{
		current_depth = dft_traversal(edge->dest, action, grey_nodes, depth + 1);
		total_depth = current_depth > total_depth ? current_depth : total_depth;
	}

	return (total_depth);
}
/**
 * depth_first_traverse - goes through a graph using depth-first algorithm
 * @graph: pointer to the graph to traverse
 * @action: pointer to a function to be called for each visited vertex
 * Return: biggest vertex depth
 */
size_t depth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *v, size_t depth))
{
	int *grey_nodes;
	size_t depth = 0;

	if (graph && graph->vertices)
	{
		/* init int [] to store seen nodes */
		grey_nodes = calloc(sizeof(int));

		if (grey_nodes == NULL)
			return (0);
		depth = dfs_traversal(graph->vertices, action, grey_nodes, depth);
		free(grey_nodes);
	}

	return (depth);
}
