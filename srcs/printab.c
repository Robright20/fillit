/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:33:02 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/26 12:35:34 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

void	print_board(char *board, int size)
{
	int		i;

	i = 0;
	while (i < (size * size))
	{
		ft_putchar(board[i]);
		if (!((i + 1 ) % size))
			ft_putchar('\n');
		i++;
	}
}

void	printab(int *tab, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\t');
		i++;
	}
	ft_putchar('\n');
}
