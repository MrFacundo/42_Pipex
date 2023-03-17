/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:03:55 by ftroiter          #+#    #+#             */
/*   Updated: 2023/03/17 15:34:23 by facundo          ###   ########.fr       */
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
	perror(err);
	exit(1);
}

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
