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

# include <stdio.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH 1600
# define HEIGHT 900

enum				e_err
{
	MALLOC_ERR = 0,
};

typedef struct		s_lst
{
	char			*data;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_default
{
	int				x;
	int				y;
	int 			zoom_x;
	int 			zoom_y;
}					t_default;

typedef struct  	s_point
{
	int				x;
    int				y;
    int				z;
    int				color;
    int				x1;
    int				y1;
}					t_point;

typedef struct		s_map
{
    int				width;
    int				height;
    t_point			**points;
}					t_map;

typedef struct		s_img
{
	void			*img;
	int				*adr;
	int				bits;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_main
{
	void			*mlx;
	void			*win;
    t_map			map;
    t_img			image;
    t_default		*def;
}					t_main;

int					read_map(t_map *map, int fd);
int					count_list(t_lst *list);
int					fill_map(t_map *map, t_lst *list);
void				init_struct(t_main *data);
void				remove_points(t_map *map);
void				lst_del(t_lst *head);
void				del_double_arr(char **arr);
void				lst_to_end(t_lst **head, t_lst *new);
char				**cnvrt_to_arr(t_lst *list);
t_lst				*lst_new(char *content);
void				*on_crash(int err);
void				print(t_main *data);
int 				key_hook(int key, void *param);

#endif
