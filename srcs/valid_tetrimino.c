/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:45:02 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/19 09:00:25 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_file.h"

int		is_inbounds(int *tab, int len, int ubound)
{
	int	i;

	i = 0;
	while (i < len && (tab[i] > 0 && tab[i] <= ubound))
		i++;
	return (i == len);
}

int		istetris(int *rel_pos)
{
	static int	test[5][5][5];

	if (!test[1][4][3])
	{
		test[1][4][3] = 1;
		test[1][4][4] = 1;
		test[1][4][1] = 1;
		test[1][2][1] = 1;
		test[1][3][1] = 1;
		test[1][1][1] = 1;
		test[1][1][2] = 1;
		test[1][1][3] = 1;
		test[1][1][4] = 1;
		test[3][4][1] = 1;
		test[4][4][4] = 1;
	}
	return (test[rel_pos[0]][rel_pos[1]][rel_pos[2]]);
}

int		valid_tetrimino(int *tab)
{
	int rel_pos[3];

	if (!is_inbounds(tab, 4, 416))
		return (0);
	sort(tab, 4);
	rel_pos[0] = tab[1] - tab[0];
	rel_pos[1] = tab[3] - tab[2];
	rel_pos[2] = tab[2] - tab[1];
	if (!(tab[0] % 4) && rel_pos[0] == 1)
		return (0);
	if (!(tab[2] % 4) && rel_pos[1] == 1)
		return (0);
	if (!(tab[1] % 4) && rel_pos[2] == 1)
		return (0);
	sort(rel_pos, 2);
	return (is_inbounds(rel_pos, 3, 4) && istetris(rel_pos));
}
