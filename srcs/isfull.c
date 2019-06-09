/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isfull.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:38:15 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/09 17:57:30 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_file.h"

int		isfull(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n && tab[i])
		i++;
	if (i == n)
		return (TAB_FULL);
	return (i);
}