/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** event_win2
*/

#include "world.h"

void update_button(toolbox_t *toolbox)
{
    for (int i = 0; i < 4; i++)
        if (toolbox->state[i] == 1) {
            sfSprite_setColor(toolbox->sprites[i], sfRed);
            toolbox->state[i] = 2;
        }
    for (int i = 4; i < 6; i++) {
        toolbox->state[i] = 0;
        sfSprite_setColor(toolbox->sprites[i], sfWhite);
    }
}

void analyse_events_win2(sfEvent event, toolbox_t *tool, interface_t *face)
{
    sfVector2f mouse_pos;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(tool->win);
    if (event.type == sfEvtMouseButtonPressed &&
event.mouseButton.button == sfMouseLeft) {
        mouse_pos.x = event.mouseButton.x;
        mouse_pos.y = event.mouseButton.y;
        is_on_button(tool, mouse_pos, face);
    }
    if (event.type == sfEvtMouseButtonReleased)
        update_button(tool);
}