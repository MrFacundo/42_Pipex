/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:03:55 by ftroiter          #+#    #+#             */
/*   Updated: 2023/03/15 17:34:30 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

void	check_process_exit(int wstatus, int process)
{
	if (WEXITSTATUS(wstatus) == 0)
		return ;
	ft_putstr_fd(ERR_CHILD, 2);
	ft_putnbr_fd(process, 2);
	exit(1);
}

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

static size_t	pipex_count_tokens(char const *s, char c)
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

char    *handle_quotes(char const *s, char **result, size_t *i)
{
	char    *s2;

	s2 = ft_strrchr(s, *s);
	result[(*i)++] = ft_substr(++s, 0, s2 - s);
	return (++s2);
}


char	**ft_pipex_split(char const *s, char c)
{
	char	**result;
	char	*s2;
	size_t	i;
	size_t	len;

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
				handle_quotes(s, result, &i);
				// s2 = ft_strrchr(s, *s);
				// result[i++] = ft_substr(++s, 0, s2 - s - 1);
				// s = ++s2;
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

// char    **ft_pipex_split(char const *s, char c)
// {
// 	char    **result;
// 	size_t  i;

// 	i = 0;
// 	result = malloc(sizeof(char *) * (pipex_count_tokens(s, c) + 1));
// 	if (!result || !s)
// 		return (NULL);
// 	while (*s)
// 	{
// 		if (*s == c)
// 			s++;
// 		else
// 		{
// 			if (*s == '\'' || *s == '\"')
// 				s = handle_quotes(s, result, &i);
// 			else if (*s)
// 				s = handle_token(s, result, &i, c);
// 		}
// 	}
// 	result[i] = 0;
// 	return (result);
// }


// char    *handle_token(char const *s, char **result, size_t *i, char c)
// {
// 	size_t  len;

// 	len = 0;
// 	while (*s && *s != c && ++len)
// 		++s;
// 	result[(*i)++] = ft_substr(s - len, 0, len);
// 	return (s);
// }

char	**parse_script(char *process_string)
{
	char	**script_argv;

	if (access(process_string, F_OK))
		error("ERR_SCRIPT");
	script_argv = ft_calloc(3, 1);
	if (!script_argv)
		return (0);
	script_argv[0] = ft_strdup("bash");
	script_argv[1] = process_string;
	return (script_argv);
}

char	**parse_process_string(char *process_string)
{
	char	**argv;
	char	*temp;
	char	*bash;
	char	**script_argv;

	if (ft_strnstr(process_string, ".sh", ft_strlen(process_string)))
		return (parse_script(process_string));
	argv = ft_pipex_split(process_string, ' ');
	return (argv);
}

char	*get_path(char *envp[], char *process)
{
	char	**paths;
	char	*path_string;
	char	*path;

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
			break ;
		free(path);
		paths++;
	}
	if (!*paths)
		error("ERR_CMD");
	return (path);
}
