/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:48:44 by crycherd          #+#    #+#             */
/*   Updated: 2020/03/01 22:05:08 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_error(char *text, int code)
{
        ft_putstr_fd(text, 2);
        exit(code);
}

int	main(int ac, char **av)
{
	t_main	fdf;
	int		fd;

	if (ac < 2)
		print_error("usage: ./fdf *file_name*\n", 0);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		print_error("Cannot open the file\n", 2);
	if (!read_map(&fdf.map, fd))
		print_error("\n", 0);
		
	ft_putstr("anime top\n");
	return (0);
}
