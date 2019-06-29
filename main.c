/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:44:01 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/29 02:20:16 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		**all_tetris;
	int		size;
	int		nbtetris;

	if (ac != 2)
	{
		ft_putendl("usage : ./fillit file");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	all_tetris = (int**)ft_memalloc(27 * sizeof(int*));
	if (valid_file(fd, all_tetris) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	nbtetris = 0;
	size = 2;
	while (all_tetris[nbtetris] && nbtetris < 26)
		nbtetris++;
	while (size * size < nbtetris * 4)
		size++;
	if (size != nbtetris * 4)
		size--;
	fill(all_tetris, size, nbtetris);
	close(fd);
	return (0);
}
