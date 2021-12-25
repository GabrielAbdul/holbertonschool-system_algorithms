#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <stdio.h>
#include <stdlib.h>

queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);

#endif /* PATHFINDING_H */