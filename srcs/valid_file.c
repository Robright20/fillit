/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:41:36 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/18 18:06:04 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_file.h"

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
		if (nblines % 5)
		{
			if ((ret = valid_line(line, tab)) < 0)
				return (ret);
		}
		else if (!(*line))
		{
			ret = isfull(tab, 4);
			if (ret != TAB_FULL || !valid_tetrimino(tab))
				return (NOT_TETRIS);
			ft_bzero(tab, sizeof(tab));
		}
		else
			return (INV_LINE);
		ft_strdel(&line);
	}
	if (!ret && !line)
		return (valid_tetrimino(tab));
	return (ret);
}
