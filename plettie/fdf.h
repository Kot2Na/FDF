#ifndef FDF_FDF_H
#define FDF_FDF_H

# include <stdio.h>
# include <unistd.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"

# define WIDTH 1600
# define HEIGHT 900

enum            e_err
{
    MALLOC_ERR = 0,
};

typedef struct s_first
{
    int         x;
    int         y;
    int         z;
}               t_first;

typedef struct  s_img
{
    void        *img;
    int         *adr;
    int         bits;
    int         size_line;
    int         endian;
}               t_img;

typedef	struct	s_last
{
    int			x;
    int			y;
    int			z;
}				t_last;

typedef struct	s_default
{
    int			x;
    int			y;
}				t_default;


typedef struct  s_fdf
{
    void        *mlx;
    void        *win;
    t_img       image;
    t_first     *first;
    t_last  	*last;
    t_default	*def;
}               t_fdf;

#endif //FDF_FDF_H
