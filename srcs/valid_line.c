/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:56:08 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/26 12:36:51 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

int		valid_line(char *line, int *tab, int *nblines)
{
	static int	pos = 1;
	int			i;
	int			j;

	if (ft_strlenx(line) != 4)
		return (INV_LINE);
	j = 0;
	i = 0;
	if (!(nblines[1] % 4))
		pos = 1;
	while (i < 4 && line[i] != '\n')
	{
		if (line[i] == '.')
			pos++;
		else if (line[i] == '#')
		{
			if ((j = isfull(tab, 4)) == TAB_FULL)
				return (NOT_TETRIS);
			tab[j] = pos;
			pos++;
		}
		else
			return (INV_LINE);
		i++;
	}
	return (1);
}
