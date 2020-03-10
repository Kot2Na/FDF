/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:31:48 by plettie           #+#    #+#             */
/*   Updated: 2020/03/10 18:31:51 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int        close_app()
{
	exit(0);
}

int			my_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

void		draw_line(t_point *first, t_point *last, int *adr, t_default *def)
{
	int		sx;
	int		sy;
	int		err;
	int		e2;

	first->x1 = first->x * def->zoom_x;
	first->y1 = first->y * def->zoom_y;
	last->x1 = last->x * def->zoom_x;
	last->y1 = last->y * def->zoom_y;
	//printf("x=%d y=%d\nx=%d y=%d\n\n", first->x1, first->y1, last->x1, last->y1);
	def->x = my_abs(last->x1 - first->x1);
	def->y = - my_abs(last->y1 - first->y1);
	sx = first->x1 < last->x1 ? 1 : -1;
	sy = first->y1 < last->y1 ? 1 : -1;
	err = def->x + def->y;
	while (1)
	{
		adr[first->x1 + first->y1 * WIDTH] = first->color;
		if (first->x1 == last->x1 && first->y1 == last->y1)
			break;
		e2 = 2 * err;
		if (e2 >= def->y)
		{
			err += def->y;
			first->x1 += sx;
		}
		if (e2 <= def->x)
		{
			err += def->x;
			first->y1 += sy;
		}
	}
}

void		print(t_main *data)
{
	int 	x;
	int 	y;
	t_point	**points;

	y = 0;
	points = data->map.points;
	while (y < data->map.height)
	{
		x = 0;
		while (x + 1 < data->map.width && (points[y][x].color = 0xFFFFF))
		{
			if (y + 1 < data->map.height)
				draw_line(&points[y][x], &points[y + 1][x], data->image.adr, data->def);
			draw_line(&points[y][x], &points[y][x + 1], data->image.adr, data->def);
			x++;
		}
		if (y + 1 < data->map.height && (points[y][x].color = 0xFFFFF))
			draw_line(&points[y][x], &points[y + 1][x], data->image.adr, data->def);
		y++;
	}
	free(data->def);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
}

void		initialize_image(t_main *fdf)
{
	t_img	*image;

	image = &fdf->image;
	image->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	image->adr = (int*)mlx_get_data_addr(image->img, &image->bits,
								   &image->size_line, &image->endian);
	image->bits /= 8;
}

void		init_struct(t_main *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	initialize_image(data);
	if (!(data->def = malloc(sizeof(t_default) * (data->map.height + data->map.width))))
		on_crash(MALLOC_ERR);
	data->def->zoom_x = WIDTH / data->map.width;
	data->def->zoom_y = HEIGHT / data->map.height;
	data->view[PAR] = 1;
	print(data);
	mlx_hook(data->win, 17, 0, close_app, data);
	mlx_hook(data->win,  2, 0, key_hook, data);
	mlx_loop(data->mlx);
}
