/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:03:55 by ftroiter          #+#    #+#             */
/*   Updated: 2023/02/16 17:04:28 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

void	error(char *err)
{
	perror(err);
	exit(1);
}

void	close_pipe_ends(int pipe_fd[])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

// You are entering quotes hell

static	size_t pipex_count_tokens(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (*s == '\'' && ++count)
			{
				s++;
				while (*s && *s != '\'')
					s++;
				if (*s == '\'')
					s++;
			}
			if (*s == '\"' && ++count)
			{
				s++;
				while (*s && *s != '\"')
					s++;
				if (*s == '\"')
					s++;
			}
			else
			{
				count++;
				while (*s && *s != c)
					s++;
			}
		}
	}
	return (count);
}

// You are entering quotes hell, again

char **ft_pipex_split(char const *s, char c)
{
	char **result;
	size_t i;
	size_t len;

	i = 0;
	result = malloc(sizeof(char *) * (pipex_count_tokens(s, c) + 1));
	if (!result || !s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (*s && *s == '\'')
			{
				while (*s == '\'')
					s++;
				len = 2;
				while (*s && *s != '\'' && ++len)
					++s;
				if (*s == '\'')
					++s;
				result[i++] = ft_substr(s - len, 0, len);
			}
			if (*s && *s == '\"')
			{
				while (*s == '\"')
					s++;
				len = 2;
				while (*s && *s != '\"' && ++len)
					++s;
				if (*s == '\"')
					++s;
				result[i++] = ft_substr(s - len, 0, len);
			}
			if (*s && *s != '\'' && *s != '\"')
			{
				len = 0;
				while (*s && *s != c && ++len)
					++s;
				result[i++] = ft_substr(s - len, 0, len);
			}
		}
	}
	result[i] = 0;
	return (result);
}

char	**parse_process_string(char *process_string)
{
	char **argv;
	int i;
	char *temp;

	argv = ft_pipex_split(process_string, ' ');
	i = 0;
	while (argv[i])
	{
		temp = ft_strtrim(argv[i], "\"\'");
		ft_strlcpy(argv[i], temp, ft_strlen(temp) + 1);
		i++;
		free(temp);
	}
	return (argv);
}

char	*get_path(char *envp[], char *process)
{
	char **paths;
	char *path_string;
	char *path;

	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
	path_string = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
	if (!path_string)
		return (0);
	paths = ft_split(path_string, ':');
	free(path_string);
	process = ft_strjoin("/", process);
	while (*paths)
	{
		path = ft_strjoin(*paths, process);
		if (!path)
			return (0);
		if (!access(path, F_OK))
			break;
		free(path);
		paths++;
	}
	if (!*paths)
		error("ERR_CMD");
	return (path);
}

