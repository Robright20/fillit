/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:41:36 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/15 10:20:37 by fokrober         ###   ########.fr       */
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
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("ici");
		nblines++;
		if (nblines % 5 && (ret = valid_line(line, tab)) < 0)
			return (ret);
		else if (!(*line) && !(nblines % 5))
		{
			if (((ret = isfull(tab, 4)) != TAB_FULL) ||
					(ret == TAB_FULL && !valid_tetrimino(tab)))
				return (NOT_TETRIS);
			ft_bzero(tab, sizeof(tab));
		}
		else if (*line && !(nblines % 5))
			return (INV_LINE);
		ft_strdel(&line);
	}
	if (!ret)
		return (valid_tetrimino(tab));
	return (ret);
}
