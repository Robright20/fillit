/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:41:36 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/26 12:34:54 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

int		chk_line(char *line, int *nblines, t_mem tab, int **all_tetris)
{
	int		ret;

	if (nblines[0] % 5)
	{
		if ((ret = valid_line(line, tab.ptr, nblines)) < 0)
			return (ret);
		nblines[1]++;
	}
	else if (*line == '\n')
	{
		if (isfull(tab.ptr, 4) != TAB_FULL || !valid_tetrimino(tab.ptr))
			return (NOT_TETRIS);
		save_tetris(tab, all_tetris);
		ft_bzero(tab.ptr, tab.size);
	}
	else
		return (INV_LINE);
	return (1);
}

int		chk_buff(char *buf, int ret, int **all_tetris)
{
	char	*line;
	int		i;
	int		tab[4];
	int		nblines[2];

	ft_bzero(tab, sizeof(tab));
	ft_bzero(nblines, sizeof(nblines));
	i = 0;
	while (i < ret)
	{
		nblines[0]++;
		line = &buf[i];
		if (chk_line(line, nblines, buildmem(tab, sizeof(tab)), all_tetris) != 1)
			return (0);
		nblines[0] % 5 == 0 ? i++ : (i += 5);
	}
	save_tetris(buildmem(tab, sizeof(tab)), all_tetris);
	return ((i >= ret) && (!(nblines[1] % 4) && valid_tetrimino(tab)));
}

int		valid_file(int fd, int **all_tetris)
{
	int		ret;
	char	buf[BUF_SIZE];

	ft_bzero(buf, sizeof(buf));
	ret = read(fd, buf, BUF_SIZE);
	if (ret > BUF_SIZE || ret <= 0)
		return (INV_FILE);
	if (chk_buff(buf, ret, all_tetris))
		return (VALID_FILE);
	return (INV_FILE);
}
