#include "fdf.h"

void	add_to_list(char *str, int i, t_lst **list)
{
	char	*line;
	char	*save;

	if (list)
	{
		line = ft_strnew(i + 1);
		line = ft_strncpy(line, str, i);
		to_end(list, new_lst(line));
		free(line);
	}
}

char	**str_split(char *str, char c)
{
	t_lst	*argv;
	char	**result;
	int		i;

	i = 0;
	argv = NULL;
	while (str[i])
	{
		if (str[i] && str[i] == c)
		{
			add_to_list(str, i, &argv);
			str += i + 1;
			i = 0;
		}
		i++;
	}
	add_to_list(str, i, &argv);
	result = cnvrt_to_arr(argv);
	lst_del(argv);
	return (result);
}

int	check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) && line[i] != '-' && line[i] != '+')
			return(0);
		i++;
	}
	return (1);
}

int read_map(t_map *map, int fd)
{
	t_lst	*list;
	char	*line;

	list = NULL;
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
	//fill_map(map, list);
	lst_del(&list);
	return(1);
}