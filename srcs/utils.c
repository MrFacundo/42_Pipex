/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:03:55 by ftroiter          #+#    #+#             */
/*   Updated: 2023/02/12 13:35:25 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

void	error(char *err)
{
	perror(err);
	exit (1);
}

void	close_pipe_ends(int pipe_fd[])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

char	**parse_process_string(char	*process_string)
{
	char	**argv;
	int		i;

	argv = ft_split(process_string, ' ');
	i = 0;
	while (argv[i])
		i++;
	argv[i] = 0;
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
	process = ft_strjoin("/", process);
	while (*paths)
	{
		path = ft_strjoin(*paths, process);
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
