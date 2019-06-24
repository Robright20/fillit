/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:41:36 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/24 10:54:48 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_file.h"

int		chk_line(char *line, int *nblines, int *tab, size_t len)
{
	int		ret;

	if (nblines[0] % 5)
	{
		if ((ret = valid_line(line, tab)) < 0)
			return (ret);
		nblines[1]++;
	}
	else if (*line == '\n')
	{
		if (isfull(tab, 4) != TAB_FULL || !valid_tetrimino(tab))
			return (NOT_TETRIS);
		ft_bzero(tab, len);
	}
	else
		return (INV_LINE);
	return (1);
}

int		chk_buff(char *buf, int ret)
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
		if (chk_line(line, nblines, tab, sizeof(tab)) != 1)
			return (0);
		nblines[0] % 5 == 0 ? i++ : (i += 5);
	}
	return ((i >= ret) && (!(nblines[1] % 4) && valid_tetrimino(tab)));
}

int		valid_file(int fd)
{
	int		ret;
	char	buf[BUF_SIZE];

	ft_bzero(buf, sizeof(buf));
	ret = read(fd, buf, BUF_SIZE);
	if (ret > BUF_SIZE || ret <= 0)
		return (INV_FILE);
	if (chk_buff(buf, ret))
		return (VALID_FILE);
	return (INV_FILE);
}
