#include "fdf.h"
#include "stdio.h"

void	del_double_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	add_to_list(char *str, int i, t_lst **list)
{
	char	*line;
	char	*save;

	if (list)
	{
		line = ft_strnew(i + 1);
		line = ft_strncpy(line, str, i);
		lst_to_end(list, lst_new(line));
		free(line);
	}
}

int	check_line(char *line)
{
	int i;
	int result;

	i = 0;
	result = 1;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != '-' && line[i] != ' ' && line[i] != '+')
			result = 0;
		i++;
	}
	return (result);
}

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

int	fill_map(t_map *map, t_lst *list)
{
	char	**number;
	t_point **points;
	int x;
	int y;

	y = 0;
	printf("y = %d, x = %d\n", map->height, map->width);
	points = map->points;
	points = (t_point **)malloc(map->height * sizeof(t_point *));
	while (y < map->height)
	{
		points[y] = (t_point *)malloc(map->width * sizeof(t_point));
		y++;
	}
	y = 0;
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
				return (0);
			}
			x++;
		}
		y++;
		del_double_arr(number);
		list = list->next;
	}
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
	y = 0;

	while (y < map->height)
	{
		free(points[y]);
		y++;
	}
	free(points);
	/*
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
	*/
	return (1);
}

int read_map(t_map *map, int fd)
{
	t_lst	*list;
	char	*line;

	list = NULL;
	map->width = 0;
	while (get_next_line(fd, &line))
	{
		if (!check_line(line))
			return(0);
		if (map->width == 0)
			map->width = ft_count_wrd(line, ' ');
		else if (map->width != ft_count_wrd(line, ' '))
			return (0);
		lst_to_end(&list, lst_new(line));
		free(line);
	}
	map->height = count_list(list);
	if (map->height == 0 || !(fill_map(map, list)))
		return(0);
	lst_del(list);
	return(1);
}