/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:41:36 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/08 15:30:04 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		isfull(int *tab, int n)
{
	int	j;

	j = 0;
	while (j < n && tab[j])
		j++;
	if (j == n)
		return (-1);
	return (j);
}

void	printab(int *tab, int n)
{
	int j;

	j = 0;
	while (j < n)
	{
		ft_putnbr(tab[j]);
		ft_putchar('\t');
		j++;
	}
	ft_putchar('\n');
}

int		valid_line(char *line, int *tab)
{
	static int	pos = 1;
	int			i;
	int			j;

	if (ft_strlen(line) != 4)
		return (0);
	j = 0;
	i = 0;
	while (i < 4 && line[i])
	{
		printf("pos : [%d]\tchar :[%c]\n", pos, line[i]);
		if (line[i] == '.')
			pos++;
		else if (line[i] == '#')
		{
			if ((j = isfull(tab, 4)) == -1)
				return (-1);
			tab[j] = pos;
			pos++;
		}
		else
			return (0);
		i++;
	}
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
	while (((ret = get_next_line(fd, &line)) > 0) && nblines != 104)
	{
		if (valid_line(line, tab) > 0)
			nblines++;
		else if (!(*line) && !(nblines % 4))
		{
			if (isfull(tab, 4) != -1)
				return (-1);
			else
				ft_bzero(tab, sizeof(tab));
		}
		else
			return (-1);
		ft_strdel(&line);
	}
	if (ret > 0 && nblines == 104)
		return (-1);
	return (ret);
}

int		main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putendl("usage : ./fillit file");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	printf("%d\n", valid_file(fd));
	close(fd);
	return (0);
}
