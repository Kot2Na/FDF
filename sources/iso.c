/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:32:19 by plettie           #+#    #+#             */
/*   Updated: 2020/03/10 18:32:23 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_iso(t_main *data)
{
	int 	x;
	int 	y;
	int		previous_x;
	int		previous_y;

	x = 0;
	while (x < data->map.width && data->view[ISO] == 0)
	{
		y = 0;
		while (y < data->map.height)
		{
			previous_x = data->map.points[y][x].x;
			previous_y = data->map.points[y][x].y;
			data->map.points[y][x].x = (previous_x - previous_y) * cos(0.523599);
			data->map.points[y][x].y = -data->map.points[y][x].z + (previous_x + previous_y) * sin(0.523599);
			x++;
		}
		y++;
	}
	data->view[PAR] = 0;
	data->view[ISO] = 1;
}
