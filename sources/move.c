/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:50:17 by plettie           #+#    #+#             */
/*   Updated: 2020/03/10 20:50:20 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_offset(int key, t_main *data)
{
	if (key == KEY_LEFT)
		data->offset.offset_x -= 10;
	if (key == KEY_RIGHT)
		data->offset.offset_x += 10;
	if (key == KEY_UP)
		data->offset.offset_y -= 10;
	if (key == KEY_DOWN)
		data->offset.offset_y += 10;
}

void	change_angle(int key, t_main *data)
{
	if (key == KEY_Q)
		data->rotate.x_angle += 0.05;
	if (key == KEY_E)
		data->rotate.x_angle -= 0.05;
	if (key == KEY_A)
		data->rotate.y_angle += 0.05;
	if (key == KEY_D)
		data->rotate.y_angle -= 0.05;
	if (key == KEY_Z)
		data->rotate.z_angle += 0.05;
	if (key == KEY_C)
		data->rotate.z_angle -= 0.05;
	if (key == KEY_ISO)
	{
		if (data->rotate.iso == 1)
			data->rotate.iso = 0;
		else
			data->rotate.iso = 1;
	}
}

void 	change_zoom(int key, t_main *data)
{
	if (key == KEY_ZOOM_INC && data->map.zoom < 100)
		data->map.zoom += 1;
	if (key == KEY_ZOOM_DEC && data->map.zoom > 2)
		data->map.zoom -= 1;
}