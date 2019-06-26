/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:44:01 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/26 20:59:20 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		**all_tetris;
	int		ret;
	int		size = 20;
	char	*board;
	int		i;
	
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit file");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	all_tetris = (int**)ft_memalloc(26 * sizeof(int*));
	if ((ret = valid_file(fd, all_tetris)) != 1)
		del_all((void***)&all_tetris, 26);
	shift_all_tetris_to(all_tetris, size);
	board = create_board(size);
	i = 0;
	while (i < 26)
	{
		place_on_board(all_tetris[i], board, size, i);
		i++;
	}
	print_board(board, size);
	//ft_putnbr(ret);
	//ft_putchar('\n');
	close(fd);
	return (0);
}
/*
int		main(void)
{
	char	*board;

	board = create_board(8);
	print_board(board, 8);
	return (0);
}*/
