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
		adr[first->x1 + first->y1 * WIDTH] = 0xFFFFF;
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

void		print(t_main *data, t_img *img)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	if (!(data->def = malloc(sizeof(t_default) * data->map.width * data->map.height)))
		on_crash(MALLOC_ERR);
	data->def->zoom_x = WIDTH / data->map.width;
	data->def->zoom_y = HEIGHT / data->map.height;
	while (y < data->map.height)
	{
		x = 0;
		while (x + 1 < data->map.width)
		{
			if (y + 1 < data->map.height)
				draw_line(&data->map.points[y][x], &data->map.points[y + 1][x], img->adr, data->def);
			draw_line(&data->map.points[y][x], &data->map.points[y][x + 1], img->adr, data->def);
			x++;
		}
		if (y + 1 < data->map.height)
			draw_line(&data->map.points[y][x], &data->map.points[y + 1][x], img->adr, data->def);
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
}

void		init_struct(t_main *data)
{
	t_img	*img;

	img = &data->image;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->adr = (int*)mlx_get_data_addr(img->img, &img->bits, &img->size_line, &img->endian);
	print(data, img);
	mlx_hook(data->win, 17, 0L, close_app, &data);
	mlx_loop(data->mlx);
}