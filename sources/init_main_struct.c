/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:31:48 by plettie           #+#    #+#             */
/*   Updated: 2020/03/14 17:23:00 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_app()
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


	//printf("out %d and %d\n", first->x, last->y);
	//printf("zoom %d and %d\n", def->zoom_x, def->zoom_y);
	//first->x = first->x * def->zoom_x;
	//first->y = first->y * def->zoom_x;
	//last->x = last->x * def->zoom_x;
	//last->y = last->y * def->zoom_x;
	//printf("first x = %d y = %d\nlast x = %d y = %d\n\n", first->x, first->y, last->x, last->y);
	def->x = my_abs(last->x - first->x);
	def->y = - my_abs(last->y - first->y);
	sx = first->x < last->x ? 1 : -1;
	sy = first->y < last->y ? 1 : -1;
	err = def->x + def->y;
	while (1)
	{
		//printf("segfault last %d %d\n", last->x, last->y);
		//printf("segfault first %d %d\n", first->x, first->y);
		if (first->x > 0 && first->x < WIDTH && first->y > 0 && first->y < HEIGHT)
			adr[first->x + first->y * WIDTH] = first->color;
		if (first->x == last->x && first->y == last->y)
			break;
		e2 = 2 * err;
		if (e2 >= def->y)
		{
			err += def->y;
			first->x += sx;
		}
		if (e2 <= def->x)
		{
			err += def->x;
			first->y += sy;
		}
	}
	free(first);
	free(last);
}

void		print(t_main *data)
{
	int 	x;
	int 	y;
	t_point	**points;

	//printf("%p\n", data);
	//printf("%p\n", data->def);
	//data->def->zoom_x = WIDTH / data->map.width / 10;
	//data->def->zoom_y = HEIGHT / data->map.height /10;
	y = 0;
	points = data->map.points;
	//printf("%d %d\n", data->def->zoom_x, data->def->zoom_y);
	while (y < data->map.height)
	{
		x = 0;
		//printf("lol %d %d\n", points[y][x].x, points[y][x].y);
		while (x < data->map.width)
		  {
			//printf("point_x = %d, point_y = %d, max_x = %d, max_y = %d\n", x, y, data->map.width, data->map.height);
			//printf("x - y - z | %d - %d - %d\n", data->map.points[x][y].x, data->map.points[x][y].y, data->map.points[x][y].z);
			points[y][x].color = 0xFFFFF;
			//printf("\n");
			if (y != data->map.height - 1)
			{
				//printf("in %p and %p\n", &points[y][x], &points[y + 1][x]);
				draw_line(rotate_point(&points[y][x], data), rotate_point(&points[y + 1][x], data), data->image.adr, &data->def);
			}
			if (x != data->map.width - 1)
			{
				//printf("in %p and %p\n", &points[y][x], &points[y][x + 1]);
				draw_line(rotate_point(&points[y][x], data), rotate_point(&points[y][x + 1], data), data->image.adr, &data->def);
				//draw_line(&points[y][x], &points[y][x + 1], data->image.adr, data->def);
			}
			x++;
		}
		//if (y + 1 < data->map.height && (points[y][x].color = 0xFFFFF))
		//	draw_line(&points[y][x], &points[y + 1][x], data->image.adr, data->def);
		y++;
	}
	//free(data->def);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
}

void		initialize_image(t_main *fdf)
{
	t_img	*image;

	image = &fdf->image;
	image->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	image->adr = (int *)mlx_get_data_addr(image->img, &image->bits,
								   &image->size_line, &image->endian);
	image->bits /= 8;
}

void		initialize_rotation(t_main *data)
{
	data->rotate.iso = 0;
	data->rotate.x_angle = 0;
	data->rotate.x_angle = 0;
	data->rotate.x_angle = 0;
}


void 		initialize_offset(t_main *data)
{
	data->offset.offset_x = 0;
	data->offset.offset_y = 0;
}

void		init_struct(t_main *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	initialize_image(data);
	initialize_rotation(data);
	data->view[PAR] = 1;
	print(data);
	mlx_hook(data->win, 2, 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_app, data);
	mlx_loop(data->mlx);
}
