/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:40:38 by ftroiter          #+#    #+#             */
/*   Updated: 2023/02/26 15:56:20 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
		return (pipex(argv, envp));
	else
		error(ERR_INPUT);
	return (0);
}

int	pipex(char *argv[], char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid;
	char	*argtest;

	argtest = argv[4];
	if (pipe(pipe_fd) == -1)
		error(ERR_PIPE);
	pid = fork();
	if (pid == -1)
		error(ERR_FORK);
	if (pid == 0)
		process_one(argv, envp, pipe_fd);
	pid = fork();
	if (pid == -1)
		error(ERR_FORK);
	if (pid == 0)
		process_two(argv, envp, pipe_fd);
	close_pipe_ends(pipe_fd);
	wait(NULL);
	return (0);
}

void	process_one(char *argv[], char *envp[], int pipe_fd[])
{
	int		infile_fd;
	char	**argv_one;
	char	*path;
	char	*argtest;

	argtest = argv[4];
	infile_fd = open(argv[1], O_RDONLY, 0777);
	if (infile_fd == -1)
		error(ERR_INFILE);
	dup2(infile_fd, STDIN_FILENO);
	argv_one = parse_process_string(argv[2]);
	path = get_path(envp, argv_one[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close_pipe_ends(pipe_fd);
	execve(path, argv_one, envp);
}

void	process_two(char *argv[], char *envp[], int pipe_fd[])
{
	int		outfile_fd;
	char	**argv_two;
	char	*path;
	char	*argtest;

	argtest = argv[4];
	outfile_fd = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0000664);
	if (outfile_fd == -1)
		error(ERR_OUTFILE);
	dup2(outfile_fd, STDOUT_FILENO);
	argv_two = parse_process_string(argv[3]);
	path = get_path(envp, argv_two[0]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close_pipe_ends(pipe_fd);
	execve(path, argv_two, envp);
}
