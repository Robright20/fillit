/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 03:53:39 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/26 12:23:42 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

char	*create_board(size_t size)
{
	char	*board;

	board = (char*)malloc(size * size);
	ft_memset(board, '.', size * size);
	return (board);
}
