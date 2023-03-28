/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:27:56 by ftroiter          #+#    #+#             */
/*   Updated: 2022/11/28 21:48:37 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Allocates and returns a copy of s with the characters specified in set
// removed from the beginning and the end of the string.
static size_t	strstart(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_strchr(set, s[i]))
	{
		i++;
	}
	return (i);
}

static size_t	strend(char const *s, char const *set)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while (ft_strchr(set, s[i]))
	{
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = strstart(s1, set);
	end = strend(s1, set);
	if (!s1 || !set)
		return (NULL);
	if (start > end)
		return (ft_strdup(s1));
	return (ft_substr(s1, start, (end - start + 1)));
}
