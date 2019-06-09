/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 17:50:20 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/09 17:51:23 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_file.h"

int		sort(int *tab, int n)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (n < 2)
		return (1);
	while (j < (n - 1))
	{
		if (tab[j] > tab[j + 1])
		{
			ft_swap(&tab[j], &tab[j + 1]);
			i++;
		}
		j++;
	}
	if (!i)
		return (1);
	return (sort(tab, n - 1));
}
