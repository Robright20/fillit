/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 03:59:26 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/28 14:15:46 by fokrober         ###   ########.fr       */
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

void	save_tetris(int *tab, int **all_tetris)
{
	int		i;

	i = 0;
	while (i < 26)
	{
		if (!all_tetris[i])
		{
			all_tetris[i] = (int*)ft_memdup(tab, 4 * sizeof(int));
			break ;
		}
		i++;
	}
}

void	set_val_max(int	*tab, int **val, int size)
{
	int		i;

	i = 0;
	val[0] = (int*)ft_memalloc(4 * sizeof(int));
	val[1] = (int*)ft_memalloc(4 * sizeof(int));
	while (i < 4)
	{
		val[0][i] = (tab[i] - 1) % size;
		val[1][i] = (tab[i] - 1) / size;
		i++;
	}
	sort(val[0], 4);
	sort(val[1], 4);
}