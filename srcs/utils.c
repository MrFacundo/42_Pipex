/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:03:55 by ftroiter          #+#    #+#             */
/*   Updated: 2023/03/14 10:16:19 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

void	error(char *err)
{
	if (errno == 0)
	{
		write(2, err, ft_strlen(err));
		exit(1);
	}
	perror(err);
	exit(1);
}

void	close_pipe_ends(int pipe_fd[])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

char* escape_spaces(char* str) {
	int spaces;
	int i;
	int j;
	char* new_str;

	spaces = 0;
	i = 0;
	j = 0;
	while (str[i]) {
		if (str[i] == ' ')
			spaces++;
		i++;
	}
	new_str = (char*)malloc(strlen(str) + spaces + 1);
	i = 0;
	while (str[i]) {
		if (str[i] == ' ')
			new_str[j++] = '\\';
		new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return new_str;
}
static size_t pipex_count_tokens(char const *s, char c)
{
	size_t count;
	
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

// You are entering quotes hell, again
char **ft_pipex_split(char const *s, char c)
{
	char **result;
	char *s2;
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
			if (*s == '\'' || *s == '\"')
			{
				s2 = ft_strrchr(s, *s);
				result[i++] = ft_substr(++s, 0, s2 - s - 1);
				s = ++s2;
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
	char	**argv;
	char	*temp;
	char	*bash;
	char	**script_argv;

	if (ft_strnstr(process_string, ".sh", ft_strlen(process_string)))
	{
		if (access(process_string, F_OK))
			error("ERR_SCRIPT");
		script_argv = ft_calloc(3,1);
		if (!script_argv)
			return (0);
		script_argv[0] = ft_strdup("bash");
		script_argv[1] = escape_spaces(process_string);
		return (script_argv);
	}
	argv = ft_pipex_split(process_string, ' ');
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
	while (*paths)
	{
		path = ft_strjoin(*paths, ft_strjoin("/", process));
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

/* 
char	*escape_spaces(char *s)
{
	char	*ret;
	size_t	count;
	size_t	i;	
	int length;
	
	count = 0;
	length = ft_strlen(s) + count;
	i = 0;
	while (s[i]) 
	{
		if (s[i] == ' ')
			count++;
		i++;
	}
	ret = malloc(length);
	while (*s) 
	{
		if (*s == ' ')
		{
			*ret = '\\';
			ret++;
		}
		*ret = *s;
		ret++;
		s++;
	}

	return (ret - length - count);
}
*/