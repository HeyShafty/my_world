/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** Header file for the my_world project
*/

#ifndef WORLD_H_
#define WORLD_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IN_RADIANS(angle) (angle * M_PI / 180)

#define ANGLE_X 0.785398
#define ANGLE_Y 0.610865

extern const int start_x;
extern const int start_y;
extern const int start_step;
extern const sfColor start_color;
extern const sfVector2f start_offset;
extern const char *input_font_path;

typedef enum mode_e {
    corner,
    tile,
    zoom,
    rotation
} my_mode_t;

typedef struct grid_point_s {
    int altitude;
    sfVector2f point;
} grid_point_t;

typedef struct map_s {
    char *name;
    int columns;
    int rows;
    unsigned int step;
    sfVector2f offset;
    grid_point_t **grid;
    sfView *view;
    void (*dislay_lines)(void);
    void (*dislay_tiles)(void);
    void (*dip_up)(void);
    void (*dip_down)(void);
    my_mode_t mode;
} map_t;

/* Read note in create_window.c */
sfRenderWindow *create_window(unsigned int width, unsigned int height,
                              unsigned int fps, char *name);

void destroy_map(map_t *map);
char *prompt_user_input(void);
void update_points(map_t *map);
map_t *create_map(char *filepath);
sfVector2f **create_2d_map(map_t *map);
int loop_editor(sfRenderWindow *window, map_t *map);
int draw_2d_map(sfRenderWindow *window, map_t *map);
int draw_tiles(sfRenderWindow *window, map_t *map);
void analyse_events(sfRenderWindow *window, map_t *map, sfEvent event);
sfVector2f project_iso_point(sfVector3f point, sfVector2f offset);
void manage_zoom_at(sfVector2i m, map_t *map, float zoom, sfRenderWindow *win);
void manage_zoom(sfRenderWindow *win, map_t *map, sfEvent event);
void manage_arrows(sfEvent event, map_t *map);
int is_on_tile(sfRenderWindow *win, map_t *map, grid_point_t **point, int j);
void reset_view(map_t *map);
void analyse_key_pressed(sfEvent event, map_t *map);
int find_corner_color(sfRenderWindow *win, map_t *map, sfVector2f point);
float distance_between_points(sfVector2f p1, sfVector2f p2);
float calcul_points(sfVector2f p1, sfVector2f p2, sfVector2f p3);
void manage_dig_up(map_t *map, sfRenderWindow *win);
void manage_mouse(map_t *map, sfRenderWindow *win);
int transfer_mouse_press(int tag);

#endif
