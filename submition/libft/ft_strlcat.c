/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:49:28 by ftroiter          #+#    #+#             */
/*   Updated: 2022/11/28 20:26:28 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Appends no more than size characters from the string pointed to by src
// into the string pointed to by dst and always terminates the result with
// null if size is greater than zero. Both the strings s1 and s2 must be
// terminated with null on entry and a byte for the terminating null should
// be included in size.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;

	i = 0;
	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	if (!size)
		return (src_length);
	while (src[i] && dst_length + i < size - 1)
	{
	dst[dst_length + i] = src[i];
	i++;
	}
	dst[dst_length + i] = 0;
	if (dst_length > size)
		return (src_length + size);
	return (src_length + dst_length);
}
