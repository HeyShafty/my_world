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
#include <stdbool.h>
#include <math.h>

#define IN_RADIANS(angle) (angle * M_PI / 180)

extern const int start_x;
extern const int start_y;
extern const int start_step;
extern const int window_x;
extern const int window_y;
extern const int start_angle_x;
extern const int start_angle_y;
extern const sfVector2i toolbox_pos;
extern const sfColor start_color;
extern const sfVector2f start_offset;
extern const char *input_font_path;
extern const char *cursor_path;
extern const sfColor toolbox_color;
extern const char *icon_fp[7];
extern const sfVector2f icon_pos[6];

typedef enum {
    square,
    corner
} my_mode_t;

typedef enum {
    translation,
    rotation
} my_viewmode_t;

typedef struct toolbox_s {
    sfRenderWindow *win;
    sfSprite **sprites;
    sfTexture **textures;
    int *state;
} toolbox_t;

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
    int angle_degrees[2];
    double angle[2];
    grid_point_t **grid;
} map_t;

typedef struct interface_s {
    sfRenderWindow *window;
    my_viewmode_t viewmode;
    my_mode_t mode;
    sfView *view;
    void (*highlight)(struct interface_s *, struct map_s *);
    void (*action)(struct interface_s *, struct map_s *);
} interface_t;

void destroy_map(map_t *map);
char *prompt_user_input(void);
void update_points(map_t *map);
int loop_editor(interface_t *face, map_t *map, toolbox_t *tool);
sfVector2f project_iso_point(sfVector3f point, map_t *map);
void manage_zoom(interface_t *face, sfEvent event);
void manage_zoom_at(sfVector2i m, interface_t *face, float zoom);
int is_on_tile(interface_t *face, grid_point_t **point, int j);
int is_closest_corner(interface_t *face, map_t *map, sfVector2f point);
float distance_between_points(sfVector2f p1, sfVector2f p2);
float calcul_points(sfVector2f p1, sfVector2f p2, sfVector2f p3);
void manage_mouse(interface_t *face, map_t *map);
int transfer_mouse_press(int tag);
void analyse_events_win2(sfEvent event, toolbox_t *tool, interface_t *face);
void is_on_button(toolbox_t *toolbox, sfVector2f mouse, interface_t *face);
void check_zoom(toolbox_t *tool, interface_t *face);

/* EVENTS */
void change_mode(interface_t *face);
void manage_rotate(sfKeyCode key, map_t *map);
void reset_view(interface_t *face, map_t *map);
void manage_translation(sfKeyCode key, map_t *map);
void resize_window(interface_t *face, sfSizeEvent size);
void analyse_click(sfEvent event, sfMouseButton clicked);
void change_sprite(toolbox_t *toolbox, int i, interface_t *face);
void analyse_events(interface_t *face, map_t *map, sfEvent event,
                    toolbox_t *tool);
void analyse_key_pressed(interface_t *face, map_t *map, sfKeyCode key,
                         toolbox_t *tool);


/* CREATE */
toolbox_t *create_toolbox(void);
map_t *create_map(char *filepath);
interface_t *create_interface(void);
sfVector2f **create_2d_map(map_t *map);
sfVertexArray *create_line(sfVector2f points[2], sfColor color);
sfVertexArray *create_holding_line(sfVector2f pos1, sfVector2f pos2);
sfRenderWindow *create_window(unsigned int width, unsigned int height,
                              sfVector2i pos, char *name);

/* DRAW */
int draw_tiles(interface_t *face, map_t *map);
void draw_lines(interface_t *face, map_t *map, int i, int j);
int draw_line_corner(interface_t *face, map_t *map, int i, int j);
void draw_square(sfRenderWindow *win, grid_point_t **point, int j, sfColor);

/* HIGHLIGHT */
void highlight_square(interface_t *face, map_t *map);
void highlight_corner(interface_t *face, map_t *map);

/* ACTIONS */
int *transfer_indexes(int *indexes);
void dig_nothing(interface_t *face, map_t *map);
void dig_up_square(interface_t *face, map_t *map);
void dig_up_corner(interface_t *face, map_t *map);
void dig_down_square(interface_t *face, map_t *map);
void dig_down_corner(interface_t *face, map_t *map);
void update_selected_point(interface_t *face, map_t *map);

#endif
