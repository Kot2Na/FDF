#include "fdf.h"

void rotate_x(t_point *point, double angle)
{
    int old_y;

    old_y = point->y;
    point->y = old_y * cos(angle) + point->z * sin(angle);
    point->z = -old_y * sin(angle) + point->z * cos(angle);
}

void rotate_y(t_point *point, double angle)
{
    int old_x;

    old_x = point->x;
    point->x = old_x * cos(angle) + point->z * sin(angle);
    point->z = -old_x * sin(angle) + point->z * cos(angle);
}

void rotate_z(t_point *point, double angle)
{
    int old_y;
    int old_x;

    old_x = point->x;
    old_y = point->y;
    point->x = -old_y * sin(angle) + old_x * cos(angle);
    point->y = old_y * cos(angle) + old_x * sin(angle);
}

void rotate_point(t_point *point, t_rotation *angles)
{
    rotate_x(point, angles->x_angle);
    rotate_y(point, angles->y_angle);
    rotate_z(point, angles->z_angle);
}