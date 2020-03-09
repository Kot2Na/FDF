#include "fdf.h"

void		*on_crash(int err)
{
    (err == MALLOC_ERR) ? ft_putstr("Malloc error") : 0;
    ft_putstr("\n");
    exit(err);
}

static int        close_app()
{
    exit(0);
}

void		ft_swap(int *a, int *b)
{
    int		t;

    t = *a;
    *a = *b;
    *b = t;
}

void drawline(t_fdf *data, int *adr)
{
    int p, x, y;

    if (data->last->x < data->first->x || data->last->y < data->first->y)
    {
        ft_swap(&data->first->x, &data->last->x);
        ft_swap(&data->first->y, &data->last->y);
    }
    printf("%d\n%d\n%d\n%d\n", data->first->x, data->first->y, data->last->x, data->last->y);
    data->def->x = data->last->x - data->first->x;
    data->def->y = data->last->y - data->first->y;
    x = data->first->x;
    y = data->first->y;
    p = 2 * data->def->y - data->def->x;
    while(x != data->last->x)
    {
        if(p >= 0)
        {
            printf("x = %d y = %d\n", x, y);
            adr[x + y * WIDTH] = 0xFFFFF;
            y = y + 1;
            p = p + 2 * data->def->y - 2 * data->def->x;
        }
        else
        {
            printf("x = %d y = %d\n", x, y);
            adr[x + y * WIDTH] = 0xFFFFF;
            p = p + 2 * data->def->y;
        }
        x = x + 1;
    }
    data->def->x = 0;
    data->def->y = 0;
}

//int			key_hook(int key, void *param)
//{
//    if (key == 34)
//    {
//        clear_image(param);
//        ft_iso(param);
//        ft_print(param);
//    }
//    return (0);
//}

void        init_all(t_fdf *data)
{
    t_img   *img;

    img = &data->image;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
    img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    img->adr = (int*)mlx_get_data_addr(img->img, &img->bits, &img->size_line, &img->endian);
    if (!(data->first = malloc(sizeof(t_first) * 4000)) ||
        !(data->last = malloc(sizeof(t_last) * 4000)) ||
        !(data->def = malloc(sizeof(t_default) * 1000)))
        on_crash(MALLOC_ERR);
    data->first->x = 100;
    data->first->y = 100;
    data->first->z = 0;
    data->last->x = 200;
    data->last->y = 250;
    data->last->z = 10;
    drawline(data, img->adr);
    data->first->x = 200;
    data->first->y = 250;
    data->first->z = 10;
    data->last->x = 100;
    data->last->y = 700;
    data->last->z = 20;
    drawline(data, img->adr);
//    data->first->x = 600;
//    data->first->y = 770;
//    data->first->z = 20;
//    data->last->x = 830;
//    data->last->y = 170;
//    data->last->z = 0;
 //   drawline(data, img->adr);
    mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
    //mlx_hook(data->win, 2, 0, key_hook, &data);
    mlx_hook(data->win, 17, 0L, close_app, &data);
    mlx_loop(data->mlx);
}

int main()
{
    t_fdf   data;

    init_all(&data);
    return (0);
}
