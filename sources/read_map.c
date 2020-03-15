#include "fdf.h"

void		del_double_arr(char **arr)
{
	int		i;

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

void		add_to_list(char *str, int i, t_lst **list)
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

int			check_line(char *line)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	if (line[i] == '\0')
		 result = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != '-' && line[i] != ' ' && line[i] != '+')
			result = 0;
		i++;
	}
	return (result);
}

int			create_list(t_lst **list, t_map *map, int fd)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (!check_line(line))
		{
			free(line);
			return(0);
		}
		if (map->width == 0)
			map->width = ft_count_wrd(line, ' ');
		else if (map->width != ft_count_wrd(line, ' '))
		{
			free(line);
			return (0);
		}
		lst_to_end(list, lst_new(line));
		free(line);
	}
	return (1);
}

int			set_zoom(int width, int height)
{
	if (width > 0 || height > 0)
	{
		if (width > height)
			return (WIDTH / width / 2);	
		else
			return (HEIGHT / height / 2);
	}
	return (1);
}

int			read_map(t_map *map, int fd)
{
	t_lst	*list;

	list = NULL;
	map->width = 0;
	if (!create_list(&list, map, fd))
	{
		lst_del(list);
		return(0);
	}
	map->height = count_list(list);
	if (map->height == 0 || !(fill_map(map, list)))
	{
		lst_del(list);
		return(0);
	}
	map->zoom = set_zoom(map->width, map->height);
	lst_del(list);
	return(1);
}