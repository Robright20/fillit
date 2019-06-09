/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:41:36 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/09 16:45:12 by fokrober         ###   ########.fr       */
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
	while (((ret = get_next_line(fd, &line)) > 0) && nblines != 104)
	{
		if ((ret = valid_line(line, tab)) > 0)
			nblines++;
		else if (!(*line) && !(nblines % 4))
		{
			if (((ret = isfull(tab, 4)) != TAB_FULL) ||
					(ret == TAB_FULL && !valid_tetrimino(tab)))
				return (NOT_TETRIS);
			ft_bzero(tab, sizeof(tab));
		}
		else
			return (ret);
		ft_strdel(&line);
	}
	if (!nblines || (ret > 0 && nblines == 104) || (nblines % 4))
		return (INV_NBLINES);
	return (ret);
}
