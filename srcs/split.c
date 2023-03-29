/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:37:33 by facundo           #+#    #+#             */
/*   Updated: 2023/03/29 14:47:46 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

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
			if (*s == '\"' || *s == '\'')
				s = ft_strrchr(s, *s);
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	*get_quoted_string(char const **s)
{
	char	*s2;
	char	*ret;

	s2 = ft_strrchr(*s, **s);
	++*s;
	ret = ft_substr(*s, 0, s2 - *s);
	*s = ++s2;
	return (ret);
}

char	*get_unquoted_string(char const **s, char c)
{
	size_t	len;

	len = 0;
	while (**s && **s != c && ++len)
		++*s;
	return (ft_substr(*s - len, 0, len));
}

char	**ft_pipex_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	i = 0;
	result = malloc(sizeof(char *) * (count_tokens(s, c) + 1));
	if (!result || !s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else if (*s == '\'' || *s == '\"')
			result[i++] = get_quoted_string(&s);
		else
			result[i++] = get_unquoted_string(&s, c);
	}
	result[i] = 0;
	return (result);
}
