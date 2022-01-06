#ifndef __PATHFINDING_H__
#define __PATHFINDING_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "graphs.h"
#include "queues.h"

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

int backtrack(char **map, int rows, int cols, point_t const *target,
	int x, int y, queue_t *path);
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target);

#endif /* __PATHFINDING_H__ */