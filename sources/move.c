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
	data->offset.offset_x -= 10;
}

void		ft_rigth(t_main *data)
{
	data->offset.offset_x += 10;
}

void		ft_up(t_main *data)
{
	data->offset.offset_y -= 10;
}

void		ft_down(t_main *data)
{
	data->offset.offset_y += 10;
}
