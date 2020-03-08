#include "fdf.h"
#include <stdio.h>

int compare_with_max(char *str)
{
	int result;

	result = 1;
	if (*str == '-' || *str == '+')
		str++;
	if (ft_strlen(str) > ft_strlen("2147483648"))
		result = 0;
	else if (ft_strlen(str) == ft_strlen("2147483648")) 
		if (ft_strcmp(str, "2147483647") >= 0)
			result = 0;
	return(result);
}

int check_number(char *str)
{
	int i;
	int result;

	i = 0;
	result = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			result = 0;
		i++;
	}
	if (result)
		result = compare_with_max(str);
	return (result);
}

void remove_points(t_map *map)
{
	t_point **points;
	int y;

	y = 0;
	if (map)
	{
		points = map->points;
		while (y < map->height)
		{
			free(points[y]);
			y++;
		}
		free(points);
	}
}

void malloc_points(t_map *map)
{
	t_point **points;
	int y;

	y = 0;
	if (map)
	{
		points = (t_point **)malloc(map->height * sizeof(t_point *));
		while (y < map->height)
		{
			points[y] = (t_point *)malloc(map->width * sizeof(t_point));
			y++;
		}
		map->points = points;
	}
}

int	fill_map(t_map *map, t_lst *list)
{
	char	**number;
	t_point **points;
	int x;
	int y;

	y = 0;
	malloc_points(map);
	points = map->points;
	while (list)
	{
		x = 0;
		number = ft_strsplit(list->data, ' ');
		while (number[x])
		{
			if (check_number(number[x]))
			{
				points[y][x].x = x;
				points[y][x].y = y;
				points[y][x].z = ft_atoi(number[x]);
			}
			else
			{
				del_double_arr(number);
				remove_points(map);
				return (0);
			}
			x++;
		}
		y++;
		del_double_arr(number);
		list = list->next;
	}
	/*
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			printf("x = %d, y = %d, z = %d | ", points[y][x].x, points[y][x].y, points[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}
	
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
	*/
	return (1);
}