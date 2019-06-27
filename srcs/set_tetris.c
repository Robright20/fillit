/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetris.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 03:59:26 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/27 23:57:57 by fokrober         ###   ########.fr       */
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
