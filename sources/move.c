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

void		ft_left(t_main *data)
{
	int 	x;
	int 	y;

	y = -1;
	while (check_min(data) && ++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
			data->map.points[y][x].x -= 1;
	}
}

void		ft_rigth(t_main *data)
{
	int 	x;
	int 	y;
	t_point **points;
	//printf("%p\n", data);
	points = data->map.points;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			points[y][x].x += 1;
			x++;
		}
		y++;
	}
	print(data);
}

void		ft_up(t_main *data)
{
	int 	x;
	int 	y;

	y = -1;
	while (check_min(data) && ++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
			data->map.points[y][x].y -= 1;
	}
}

void		ft_down(t_main *data)
{
	int 	x;
	int 	y;

	y = -1;
	while (check_max(data) && ++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
			data->map.points[y][x].y += 1;
	}
}
