/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:44:01 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/28 18:10:35 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fillit.h"

int		**dup_all_tetris(int **all_tetris, int nbtetris)
{
	int		i;
	int		**all_tetris2;

	i = 0;
	all_tetris2 = (int**)ft_memalloc((nbtetris + 1) * sizeof(int*));
	while (i < nbtetris)
	{
		all_tetris2[i] = (int*)ft_memdup(all_tetris[i], 4 * sizeof(int));
		i++;
	}
	return (all_tetris2);
}

void	fill(int **all_tetris2, int size, int nbtetris)
{
	int		**all_tetris;
	char	*board;

	all_tetris = dup_all_tetris(all_tetris2, nbtetris);
	board = create_board(size);
	//printabs(all_tetris2, nbtetris);
	//printf("fill-----\n");
	shift_all_tetris_to(all_tetris, size);
	//printabs(all_tetris, nbtetris);
	//printf("fill-----\n");
	while (!fillit(all_tetris, board, size, 0))
	{
		//printf("fill-test-size%d\n", size);
		//printf("fill-test-size%d\n", size);
		ft_strdel(&board);
		size++;
		board = create_board(size);
		//del_all(all_tetris, nbtetris);
		all_tetris = dup_all_tetris(all_tetris2, nbtetris);
		shift_all_tetris_to(all_tetris, size);
	}
	//printf("fill-test-size%d\n", size);
	print_board(board, size);
	return;
}

int		main(int ac, char **av)
{
	int		fd;
	int		**all_tetris2;
	int		size = 2;
	int		nbtetris;
	
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit file");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	all_tetris2 = (int**)ft_memalloc(27 * sizeof(int*));
	nbtetris = 0;
	if (valid_file(fd, all_tetris2) == 1)
	{
		while (all_tetris2[nbtetris])
			nbtetris++;
		while (size * size < (nbtetris * 4))
			size++;
		if (size > (nbtetris * 4))
			size--;
		fill(all_tetris2, size, nbtetris);
		close(fd);
		return (0);
	}
	ft_putstr("error");
	close(fd);
	return (0);
}
