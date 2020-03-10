
#include "fdf.h"

void 		ft_zoom_min(t_main *data)
{
	data->def->zoom_x += 1;
	data->def->zoom_y += 1;
}

void 		ft_zoom_pl(t_main *data)
{
	data->def->zoom_x -= 1;
	data->def->zoom_y -= 1;
}

int			check_max(t_main *data)
{
	int 	x;
	int 	y;

	y = -1;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
		{
			if ((data->map.points[y][x].x + 1) * data->def->zoom_x > WIDTH || (data->map.points[y][x].y + 1) * data->def->zoom_y > HEIGHT)
				return (0);
		}
	}
	return (1);
}

int			check_min(t_main *data)
{
	int 	x;
	int 	y;

	y = -1;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
		{
			if ((data->map.points[y][x].x - 1) * data->def->zoom_x < 0 || (data->map.points[y][x].y - 1) * data->def->zoom_y < 0)
				return (0);
		}
	}
	return (1);
}
