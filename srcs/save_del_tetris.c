/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_del_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:18:46 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/26 12:26:40 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

void	save_tetris(t_mem tab, int **all_tetris)
{
	int		i;

	i = 0;
	while (i < 26)
	{
		if (!all_tetris[i])
		{
			all_tetris[i] = (int*)ft_memdup(tab.ptr, tab.size);
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

t_mem	buildmem(void *mem, size_t size)
{
	t_mem tmp;

	tmp.ptr = mem;
	tmp.size = size;
	return (tmp);
}
