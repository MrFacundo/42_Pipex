/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:26:28 by ftroiter          #+#    #+#             */
/*   Updated: 2022/11/27 17:52:07 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(char start, char end, char c)
{
	return (c >= start && c <= end);
}

// Converts a given character c to uppercase.
int	ft_toupper(int c)
{
	if (contains('a', 'z', c))
		c -= 32;
	return (c);
}
