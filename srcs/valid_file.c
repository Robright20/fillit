/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:41:36 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/18 22:59:36 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_file.h"

int		chk_line(char **line, int nblines, int *tab, size_t len)
{
	int		ret;

	if (nblines % 5)
	{
		if ((ret = valid_line(*line, tab)) < 0)
			return (ret_linedel(line, ret));
	}
	else if (!(**line))
	{
		if (isfull(tab, 4) != TAB_FULL || !valid_tetrimino(tab))
			return (ret_linedel(line, NOT_TETRIS));
		ft_bzero(tab, len);
	}
	else
		return (ret_linedel(line, INV_LINE));
	ft_strdel(line);
	return (1);
}

int		valid_file(int fd)
{
	int		ret;
	char	*line;
	int		tab[4];
	int		nblines;

	ft_bzero(tab, sizeof(tab));
	nblines = 0;
	while ((ret = get_next_line(fd, &line)) > 0 && nblines != 129)
	{
		nblines++;
		ret = chk_line(&line, nblines, tab, sizeof(tab));
		if (ret != 1)
			return (ret);
	}
	if (!ret && !(nblines % 5))
		return (valid_tetrimino(tab));
	ft_strdel(&line);
	return (ret);
}
