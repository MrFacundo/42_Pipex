/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:26:50 by ftroiter          #+#    #+#             */
/*   Updated: 2022/11/28 21:43:27 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates and returns a new string which is the result of the concatenation
// of ’s1’ and ’s2’.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	i;
	size_t	j;

	buffer = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		buffer[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		buffer[j++] = s2[i];
		i++;
	}
	buffer[j] = 0;
	return (buffer);
}
