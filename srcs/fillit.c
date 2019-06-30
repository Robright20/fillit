/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 02:11:16 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/30 20:30:01 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

void	del_all(int **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
	{
		free(tabs[i]);
		tabs[i] = NULL;
		i++;
	}
	free(tabs);
	tabs = NULL;
}

int		**dup_all(int **all_tetris, int nbtetris)
{
	int		**all_tetris2;
	int		i;

	i = 0;
	all_tetris2 = (int**)ft_memalloc((nbtetris + 1) * sizeof(int*));
	while (all_tetris[i])
	{
		all_tetris2[i] = (int*)ft_memdup(all_tetris[i], 4 * sizeof(int*));
		i++;
	}
	return (all_tetris2);
}

char	*create_board(size_t size)
{
	char	*board;

	if ((board = (char*)malloc(size * size)))
		ft_memset(board, '.', size * size);
	return (board);
}

int		fillit(int **all_tetris, char *board, int size, int p)
{
	int		valx[2][4];
	int		i[2];

	if (!all_tetris[p])
		return (1);
	set_shift(all_tetris[p], valx, size);
	ft_bzero(i, 2 * sizeof(int));
	while (i[0] <= (size - 1) - valx[0][3])
	{
		shift_tetris_down(all_tetris[p], size, i[0]);
		while (i[1] <= (size - 1) - valx[1][3])
		{
			if (available(all_tetris[p], board))
			{
				put_tetris(all_tetris[p], board, 'A' + p);
				if (fillit(all_tetris, board, size, p + 1))
					return (1);
				remove_tetris(all_tetris[p], board);
			}
			shift_tetris_right(all_tetris[p], i[1], (size - 1) - valx[1][3]);
			i[1]++;
		}
		shift_tetris_top(all_tetris[p], size);
		i[1] = 0;
		i[0]++;
	}
	return (0);
}

void	fill(int **all_tetris, int size, int nbtetris)
{
	int		**all_tetris2;
	char	*board;

	all_tetris2 = dup_all(all_tetris, nbtetris);
	shift_all_tetris_to(all_tetris, size);
	board = create_board(size);
	while (!fillit(all_tetris, board, size, 0))
	{
		ft_strdel(&board);
		size++;
		board = create_board(size);
		del_all(all_tetris);
		all_tetris = dup_all(all_tetris2, nbtetris);
		shift_all_tetris_to(all_tetris, size);
	}
	print_board(board, size);
	del_all(all_tetris);
	del_all(all_tetris2);
	ft_strdel(&board);
}
