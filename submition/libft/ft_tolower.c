/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:40:38 by ftroiter          #+#    #+#             */
/*   Updated: 2022/11/27 17:52:07 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(char start, char end, char c)
{
	return (c >= start && c <= end);
}

// Converts a given character c to lowercase.
int	ft_tolower(int c)
{
	if (contains('A', 'Z', c))
		c += 32;
	return (c);
}
