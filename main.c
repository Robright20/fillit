/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:44:01 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/28 00:30:03 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fillit.h"

int		fillit(int **all_tetris, char *board, int size, int p)
{
	int		val[2];
	int		i;
	int		j;

	if (!all_tetris[p])
		return (1);
	set_shift_right(all_tetris[p], val, size);
	set_shift_down(all_tetris[p], val, size);
	i = 0;
	j = 0;
	while (i <= val[0])
	{
	/*	print_board(board, size);
		usleep(1000);
		system("clear");*/
		shift_tetris_down(all_tetris[p], size, i);
		while (j <= val[1])
		{
			if (available(all_tetris[p], board))
			{
				put_tetris(all_tetris[p], board, 'A' + p);
				if (fillit(all_tetris, board, size, p + 1))
					return (1);
				remove_tetris(all_tetris[p], board);
			}
			shift_tetris_right(all_tetris[p], j, val[1]);
			j++;
		}
		shift_tetris_top(all_tetris[p], size);
		j = 0;
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	int		**all_tetris;
	int		**all_tetris2;
	int		ret;
	int		size = 2;
	char	*board;
	int		i;
	
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit file");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	all_tetris = (int**)ft_memalloc(27 * sizeof(int*));
	all_tetris2 = (int**)ft_memalloc(27 * sizeof(int*));
	if ((ret = valid_file(fd, all_tetris)) != 1)
	{
		printf("%d\n", ret);
		return (0);
	}
	i = 0;
	while (all_tetris[i] && i < 26)
	{
		all_tetris2[i] = (int*)ft_memdup(all_tetris[i], 4 * sizeof(int*));
		i++;
	}
	while (size * size < i * 4)
		size++;
	if (size != i * 4)
		size--;
	shift_all_tetris_to(all_tetris, size);
	board = create_board(size);
	while (!fillit(all_tetris, board, size, 0))
	{
		ft_strdel(&board);
		size++;
		board = create_board(size);
		i = 0;
		while (all_tetris[i] && i < 26)
		{
			free(all_tetris[i]);
			all_tetris[i] = NULL;
			all_tetris[i] = (int*)ft_memdup(all_tetris2[i], 4 * sizeof(int*));
			i++;
		}
		shift_all_tetris_to(all_tetris, size);
	}
	print_board(board, size);
	printf("%d\n", ret);
	close(fd);
	return (0);
}
