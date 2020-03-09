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
	printf("x=%d y=%d\nx=%d y=%d\n\n", first->x1, first->y1, last->x1, last->y1);
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
	t_map	*map;
	t_img	*img;

	x = 0;
	y = 0;
	map = &data->map;
	img = &data->image;
	if (!(data->def = malloc(sizeof(t_default))))
		on_crash(MALLOC_ERR);
	data->def->zoom_x = WIDTH / map->width;
	data->def->zoom_y = HEIGHT / map->height;
	while (y < map->height)
	{
		x = 0;
		while (x + 1 < map->width && (map->points[y][x].color = 0xFFFFF))
		{
			if (y + 1 < map->height)
				draw_line(&map->points[y][x], &map->points[y + 1][x], img->adr, data->def);
			draw_line(&map->points[y][x], &map->points[y][x + 1], img->adr, data->def);
			x++;
		}
		if (y + 1 < map->height && (map->points[y][x].color = 0xFFFFF))
			draw_line(&map->points[y][x], &map->points[y + 1][x], img->adr, data->def);
		y++;
	}
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
	t_img	*img;

	img = &data->image;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	initialize_image(data);
	print(data);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	free(data->def);
	mlx_hook(data->win, 17, 0L, close_app, &data);
	mlx_hook(data->win,  2, 0, key_hook, &data);
	mlx_loop(data->mlx);
}