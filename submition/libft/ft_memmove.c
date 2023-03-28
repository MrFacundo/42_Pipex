/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:32:23 by ftroiter          #+#    #+#             */
/*   Updated: 2023/01/10 21:07:43 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies the values of n bytes from the location pointed by src
// to the memory block pointed by dst. Copying takes place as if
// an intermediate buffer were used, allowing the destination
// and source to overlap.
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;

	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}
