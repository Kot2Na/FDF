/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:49:26 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 21:50:55 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

typedef struct		s_lst
{
	char			*data;
	struct s_lst	*next;
}					t_lst;

typedef struct  s_point
{
    int         x;
    int         y;
    int         z;
    int         color;
}               t_point;

typedef struct  s_map
{
    int         width;
    int         height;
    t_point     **points;
}               t_map;


typedef struct  s_main
{
    t_map       map;
}               t_main;

int				read_map(t_map *map, int fd);
int				count_list(t_lst *list);
void			lst_del(t_lst *head);
void			del_double_arr(char **arr);
void			lst_to_end(t_lst **head, t_lst *new);
char			**cnvrt_to_arr(t_lst *list);
t_lst			*lst_new(char *content);

#endif
