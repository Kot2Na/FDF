/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:32:05 by plettie           #+#    #+#             */
/*   Updated: 2020/03/10 18:32:09 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		clear_img(t_main *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->image.adr[x + y * WIDTH] = 0;
			x++;
		}
		y++;
	}
}

void		ft_destroy(t_main *data)
{
	t_img *image;

	image = &data->image;
	mlx_destroy_image(data->mlx, image->img);
	mlx_destroy_window(data->mlx, data->win);
	remove_points(&data->map);
	exit(0);
}

int 		key_hook(int key, void *param)
{
	t_main *lol;

	if (key == ESCAPE)
		ft_destroy(param);
	if (key == 34)
	{
		clear_img(param);
		//ft_iso(param);
		print(param);
	}
	if (key == KEY_LEFT)
	{
		clear_img(param);
		ft_left(param);
		print(param);
	}
	if (key == KEY_RIGHT)
	{
		clear_img(param);
		ft_rigth(param);
		//print(param);
	}
	if (key == KEY_UP)
	{
		clear_img(param);
		ft_up(param);
		print(param);
	}
	if (key == KEY_DOWN)
	{
		clear_img(param);
		ft_down(param);
		print(param);
	}
	if (key == KEY_ZOOM_DEC)
	{
		clear_img(param);
		ft_zoom_min(param);
		print(param);
	}
	if (key == KEY_ZOOM_INC)
	{
		clear_img(param);
		ft_zoom_pl(param);
		print(param);
	}
	return (0);
}
