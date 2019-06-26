/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:20:03 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/26 15:01:47 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include "valid_file.h"
# include <stdio.h>

void	print_board(char *board, int size);
void	printab(int *tab, int n);
void	ft_swap(int *a, int *b);
int		sort(int *tab, int n);
size_t	ft_strlenx(const char *s);
void	save_tetris(t_mem tab, int **all_tetris);
void	del_all(void ***all, int n);
t_mem	buildmem(void *mem, size_t size);
char	*create_board(size_t size);
void	put_tetris(int *tab, char *board, char c);
int		available(int *tab, char *board);
void	remove_tetris(int *tab, char *board);
void	shift_all_tetris(int **all_tetris, int size);
void	set_shift_top(int *tab, int *val, int size);
void	shift_tetris_top(int *tab, int size);
void	set_shift_right(int *tab, int *val, int size);
void	shift_tetris_right(int *tab);
void	set_shift_down(int *tab, int *val, int size);
void	shift_tetris_down(int *tab, int size, int n);
void	shift_all_tetris_to(int **all_tetris, int size);
int		place_on_board(int *tab, char *board, int size, int p);