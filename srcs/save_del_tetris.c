/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_del_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:18:46 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/28 00:02:29 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

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

void	del_all(void ***all, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(*all[i]);
		*all[i] = NULL;
		i++;
	}
	free(*all);
	all = NULL;
}
