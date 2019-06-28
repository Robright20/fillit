/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 01:20:54 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/28 19:25:22 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

void	shift_tetris_top(int *tab, int size, int **val)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		tab[i] -= (val[1][0] * size) + val[0][3];
		i++;
	}
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

void	shift_to(int *tab, int size)
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
	int **val;

	i = 0;
	val = (int**)malloc(2 * sizeof(int*));
	if (size != 4)
		shift_all_tetris_to(all_tetris, 4);
	/*printf("shift-----%d\n", size);
	printabs(all_tetris, 9);
	printf("shift-----\n");*/
	while (i < 26 && all_tetris[i])
	{
		if (size != 4)
			shift_to(all_tetris[i], size);
		set_val_max(all_tetris[i], val, size);
		/*printf("val----\n");
		printabs(val, 2);
		printf("val----\n");*/
		shift_tetris_top(all_tetris[i], size, val);
		del_all(val, 2);
		i++;
	}
	/*printf("shifted-----%d\n", size);
	printabs(all_tetris, 9);
	printf("shifted-----\n");*/
}
