
#include "fdf.h"

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
			if ((data->map.points[y][x].x + 1) * data->map.zoom > WIDTH || (data->map.points[y][x].y + 1) * data->map.zoom > HEIGHT)
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
			if ((data->map.points[y][x].x - 1) * data->map.zoom < 0 || (data->map.points[y][x].y - 1) * data->map.zoom < 0)
				return (0);
		}
	}
	return (1);
}
