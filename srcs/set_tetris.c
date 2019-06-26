/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 03:59:26 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/26 22:01:14 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

int		available(int *tab, char *board)
{
	int		i;
	
	i = 0;
	while (i < 4)
	{
		if (board[tab[i] - 1] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	put_tetris(int *tab, char *board, char c)
{
	int		i;
	
	i = -1;
	while (++i < 4)
		board[tab[i] - 1] = c;
}

void	remove_tetris(int *tab, char *board)
{
	int	i;

	i = -1;
	while (++i < 4)
		board[tab[i] - 1] = '.';
}

int		place_on_board(int *tab, char *board, int size, int p)
{
	int		val[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	set_shift_right(tab, val, size);
	set_shift_down(tab, val, size);
	while (i < (val[0] / size))
	{
		shift_tetris_down(tab, size, i);
		while (j < val[1])
		{
			if (available(tab, board))
			{
				put_tetris(tab, board, 'A' + p);
				return (1);
			}
			shift_tetris_right(tab);
			j++;
		}
		shift_tetris_top(tab, size);
		j = 0;
		i++;
	}
	return (0);
}
