/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:44:01 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/19 14:43:53 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/valid_file.h"

int		valid_file(int fd);

int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putendl("usage : ./fillit file");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	ft_putnbr(valid_file(fd));
	ft_putchar('\n');
	close(fd);
	return (0);
}
