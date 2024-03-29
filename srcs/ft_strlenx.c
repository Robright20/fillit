/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 10:08:54 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/27 20:44:02 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fillit.h"

size_t	ft_strlenx(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\n')
		len++;
	return (len);
}
