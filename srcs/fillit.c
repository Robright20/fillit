/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 02:11:16 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/28 18:22:24 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

void	del_all(int **tabs, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(tabs[i]);
		i++;
	}
}

int		fillit(int **all_tetris, char *board, int size, int p)
{
	int		val[2];
	int		**vals;
	int		index[2];

	ft_bzero(index, 2 * sizeof(int));
	if (!all_tetris[p])
		return (1);
	vals = (int**)malloc(4 * sizeof(int*));
	set_val_max(all_tetris[p], vals, size);
	val[1] = (size - 1) - vals[0][3];
	val[0] = (size - 1) - vals[1][3];
	/*printf("test-size%d\n", size);
	printab(val, 2);
	printab(all_tetris[p], 4);*/
	while (index[0] <= val[0])
	{
		print_board(board, size);
		usleep(500000);
		system("clear");
		shift_tetris_down(all_tetris[p], size, index[0]);
		while (index[1] <= val[1])
		{
			if (available(all_tetris[p], board))
			{
				put_tetris(all_tetris[p], board, 'A' + p);
				if (fillit(all_tetris, board, size, p + 1))
					return (1);
				remove_tetris(all_tetris[p], board);
			}
			shift_tetris_right(all_tetris[p], index[1], val[1]);
			index[1]++;
		}
		shift_tetris_top(all_tetris[p], size, vals);
		index[1] = 0;
		index[0]++;
	}
	//(void)nbtetris;
	//del_all(vals, 4);
	//printf("fill-test-size%d\n", size);
	return (0);
}
