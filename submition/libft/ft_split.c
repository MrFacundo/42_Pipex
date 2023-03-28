/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:50:36 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/04 21:05:44 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_tokens(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

// Allocates and returns an array of strings obtained by splitting
// ’s’ using the character ’c’ as a delimiter. The array must end
// with a NULL pointer.
char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	len;

	i = 0;
	result = malloc(sizeof(char *) * (count_tokens(s, c) + 1));
	if (!result || !s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			result[i++] = ft_substr(s - len, 0, len);
		}
	}
	result[i] = 0;
	return (result);
}
