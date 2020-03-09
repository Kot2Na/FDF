
#include "fdf.h"

void		clear_img(t_main *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			data->image.adr[x + y * WIDTH] = 0;
	}
}

void		ft_destroy(t_main *data)
{
	t_img *image;

	image = &data->image;
//	if (data->image.img)
//		printf("%d\n", data->image.ad);
	mlx_destroy_image(data->mlx, image->img);
//	printf("ne lox\n");
	mlx_destroy_window(data->mlx, data->win);
	free(data->def);
	remove_points(&data->map);
	exit(0);
}

int 		key_hook(int key, void *param)
{
	if (key == 53)
		ft_destroy(param);
	if (key == 49)
	{
		//clear_img(param);
//		ft_iso(param);
		//print(param);
	}
	return (0);
}
