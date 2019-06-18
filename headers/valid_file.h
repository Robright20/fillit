/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:47:32 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/18 18:49:35 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_FILE_H
# define VALID_FILE_H
# include "error.h"
# include "../libft/libft.h"
# include <stdio.h>

void	printab(int *tab, int n);
void	ft_swap(int *a, int *b);
int		sort(int *tab, int n);
int		isfull(int *tab, int n);
int		valid_tetrimino(int *tab);
int		valid_line(char *line, int *tab);
int		valid_file(int fd);
int		ret_linedel(char **line, int error);
#endif
