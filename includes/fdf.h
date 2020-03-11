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
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH 1600
# define HEIGHT 900

# define ESCAPE 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_ZOOM_INC 69
# define KEY_ZOOM_DEC 78

enum				e_err
{
	MALLOC_ERR = 0,
};

enum				e_view
{
	PAR = 0,
	ISO,
	ELEMENTS,
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
    int 			view[ELEMENTS];
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
void				ft_iso(t_main *data);
void				ft_left(t_main *data);
void				ft_rigth(t_main *data);
void				ft_up(t_main *data);
void				ft_down(t_main *data);
int					check_max(t_main *data);
int					check_min(t_main *data);
void 				ft_zoom_min(t_main *data);
void 				ft_zoom_pl(t_main *data);

#endif
