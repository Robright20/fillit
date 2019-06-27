/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 01:20:54 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/28 00:29:23 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

void	set_shift_top(int *tab, int *val, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	val[0] = ((tab[0] - 1) / size) * size;
	while (++i < 4)
	{
		if (((tab[j] - 1) % size) > ((tab[i] - 1) % size))
			j = i;
	}
	val[1] = (tab[j] - 1) % size;
}

void	shift_tetris_top(int *tab, int size)
{
	int val[2];
	int i;

	set_shift_top(tab, val, size);
	i = 0;
	while (i < 4)
	{
		tab[i] -= val[0] + val[1];
		i++;
	}
}

void	set_shift_right(int *tab, int *val, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (((tab[j] - 1) % size) < ((tab[i] - 1) % size))
			j = i;
		i++;
	}
	val[1] = (size - 1) - ((tab[j] - 1) % size);
}

void	shift_tetris_right(int *tab, int j, int val)
{
	int i;

	i = 0;
	if (j < val)
	{
		while (i < 4)
		{
			tab[i] += 1;
			i++;
		}
	}
}

void	set_shift_down(int *tab, int *val, int size)
{
	val[0] = (size - 1) - ((tab[3] - 1) / size);
}

void	shift_tetris_down(int *tab, int size, int n)
{
	int i;

	i = 0;
	if (n)
	{
		while (i < 4)
		{
			tab[i] += n * size;
			i++;
		}
	}
}

void	shift(int *tab, int size)
{
	int x;
	int	i;

	x = size - 4;
	i = 0;
	while (i < 4)
	{
		tab[i] += x * ((tab[i] - 1) / 4);
		i++;
	}
}

void	shift_all_tetris_to(int **all_tetris, int size)
{
	int	i;

	i = 0;
	shift_all_tetris(all_tetris, 4);
	while (i < 26 && all_tetris[i])
	{
		shift(all_tetris[i], size);
		shift_tetris_top(all_tetris[i], size);
		i++;
	}
}

void	shift_all_tetris(int **all_tetris, int size)
{
	int i;

	i = 0;
	while (all_tetris[i] && i < 26)
	{
		shift_tetris_top(all_tetris[i], size);
		i++;
	}
}
