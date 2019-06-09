/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:45:02 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/09 17:57:35 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_file.h"

int		chk_res(int *res)
{
	int	i;

	i = 0;
	while (i < 3 && (res[i] >= 0 && res[i] <= 4))
		i++;
	return (i == 3);
}

int		chk_values(int *res)
{
	int	test[5][5][5];

	ft_bzero(test, sizeof(test));
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
	return (test[res[0]][res[1]][res[2]]);
}

int		valid_tetrimino(int *tab)
{
	int res[3];

	sort(tab, 4);
	res[0] = tab[1] - tab[0];
	res[1] = tab[3] - tab[2];
	res[2] = tab[2] - tab[1];
	sort(res, 2);
	return (chk_res(res) && chk_values(res));
}
