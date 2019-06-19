/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:48:52 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/19 11:33:21 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_file.h"

int		blocs_gen(int *tab)
{
	tab[0] = arc4random_uniform(17);
	tab[1] = arc4random_uniform(17);
	tab[2] = arc4random_uniform(17);
	tab[3] = arc4random_uniform(17);
	return (valid_tetrimino(tab));
}

void	tetris_gen(char *tetris)
{
	int			tab[4];
	int			ret;
	int			i;

	ret = 0;
	i = 0;
	while (!ret)
		ret = blocs_gen(tab);
	ret = 0;
	while (ret < 16)
	{
		if (tab[i] == ret + 1)
		{
			tetris[ret] = '#';
			i++;
		}
		else
			tetris[ret] = '.';
		ret++;
	}
}

void	print_tetris(char *tetris)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		ft_putchar(tetris[i]);
		if (!((i + 1) % 4))
			ft_putchar('\n');
		i++;
	}
}

int		main(void)
{
	char	tetris[16];
	int		nbtetris;
	int		i;

	i = 1;
	//nbtetris = arc4random_uniform(27);
	nbtetris = 27;
	while (i < nbtetris)
	{
		ft_putnbr(i);
		ft_putchar('\n');
		tetris_gen(tetris);
		print_tetris(tetris);
		i++;
		if (i != nbtetris)
			ft_putchar('\n');
	}
	return (0);
}