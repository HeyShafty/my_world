/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Everything here is about the displaying part of the map
*/

#include "world.h"

static sfVertexArray *create_line_corner(sfVector2f p1, sfVector2f p2,
                                        interface_t *face, map_t *map)
{
    int i = is_closest_corner(face, map, p1);
    int j = is_closest_corner(face, map, p2);
    sfVertexArray *vertex_array;
    sfVertex vertex = {.position = p1, .color = sfWhite};

    if (i == 0 && j == 0)
        return (NULL);
    vertex_array = sfVertexArray_create();
    if (i == 0)
        vertex.color = sfBlack;
    sfVertexArray_append(vertex_array, vertex);
    vertex.position = p2;
    if (j == 0)
        vertex.color = sfBlack;
    else
        vertex.color = sfWhite;
    sfVertexArray_append(vertex_array, vertex);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

int draw_line_corner(interface_t *face, map_t *map, int i, int j)
{
    grid_point_t **grid = map->grid;
    sfVertexArray *v_array;

    if (j + 1 < map->columns) {
            v_array = create_line_corner((grid[i][j]).point,
(grid[i][j + 1]).point, face, map);
        if (v_array != NULL) {
            sfRenderWindow_drawVertexArray(face->window, v_array, NULL);
            sfVertexArray_destroy(v_array);
        }
    }
    if (i + 1 < map->rows) {
            v_array = create_line_corner((grid[i][j]).point,
(grid[i + 1][j]).point, face, map);
        if (v_array != NULL) {
            sfRenderWindow_drawVertexArray(face->window, v_array, NULL);
            sfVertexArray_destroy(v_array);
        }
    }
    return (0);
}

sfVertexArray *create_line(sfVector2f points[2], sfColor color)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = points[0], .color = color};
    sfVertex vertex2 = {.position = points[1], .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

void draw_lines(interface_t *face, map_t *map, int i, int j)
{
    grid_point_t **grid = map->grid;
    sfColor color = sfBlack;
    sfVertexArray *v_array;
    sfVector2f points[2];

    points[0] = (grid[i][j]).point;
    if (j + 1 < map->columns) {
        points[1] = (grid[i][j + 1]).point;
        v_array = create_line(points, color);
        sfRenderWindow_drawVertexArray(face->window, v_array, NULL);
        sfVertexArray_destroy(v_array);
    }
    if (i + 1 < map->rows) {
        points[1] = (grid[i + 1][j]).point;
        v_array = create_line(points, color);
        sfRenderWindow_drawVertexArray(face->window, v_array, NULL);
        sfVertexArray_destroy(v_array);
    }
}

sfVertexArray *create_holding_line(sfVector2f pos1, sfVector2f pos2)
{
    sfVertexArray *v_array = sfVertexArray_create();
    sfVertex vertex = {.position = pos1, .color = sfBlack};

    sfVertexArray_append(v_array, vertex);
    vertex.position = pos2;
    vertex.color = sfWhite;
    sfVertexArray_append(v_array, vertex);
    sfVertexArray_setPrimitiveType(v_array, sfLinesStrip);
    return (v_array);
}
