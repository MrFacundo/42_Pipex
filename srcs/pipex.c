/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:40:38 by ftroiter          #+#    #+#             */
/*   Updated: 2023/03/14 22:11:41 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
		return (pipex(argv, envp));
	else
		error(ERR_ARGS);
	return (0);
}

int	pipex(char *argv[], char *envp[])
{

		int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		wpid;
	int		wstatus;


	if (pipe(pipe_fd) == -1)
		error(ERR_PIPE);
	printf("1: %d\n",pid1);
	pid1 = fork();
	printf("2: %d\n",pid1);
	if (pid1 == -1)
		error(ERR_FORK);
	if (pid1 == 0)
		process_one(argv, envp, pipe_fd);
	printf("3: %d\n",pid1);
	waitpid(pid1, &wstatus, 0);
	printf("4: %d\n",pid1);
	check_process_exit(wstatus);
	printf("5: %d\n",pid1);
	pid2 = fork();
	printf("6: %d\n",pid2);
	if (pid2 == -1)
		error(ERR_FORK);
	if (pid2 == 0)
		process_two(argv, envp, pipe_fd);
	close_pipe_ends(pipe_fd);
	printf("7: %d, %d\n",pid2, wstatus);
	waitpid(pid2, &wstatus, 0);
	printf("8: %d, %d \n",pid2, wstatus);
	/*check_process_exit(wstatus);*/
	return (0);

/*	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		wstatus;
	int		wpid;

	if (pipe(pipe_fd) == -1)
		error(ERR_PIPE);
	pid1 = fork();
	if (pid1 == -1)
		error(ERR_FORK);
	if (pid1 == 0)
		process_one(argv, envp, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		error(ERR_FORK);
	if (pid2 == 0)	
		process_two(argv, envp, pipe_fd);
	close_pipe_ends(pipe_fd);
	wpid = waitpid(pid1, &wstatus, 0);
	check_process_exit(wstatus);
	wpid = waitpid(pid2, &wstatus, 0);
	// check_process_exit(wstatus);
	return (0);
	*/
}



void	process_one(char *argv[], char *envp[], int pipe_fd[])
{
	int		infile_fd;
	char	**argv_one;
	char	*path;

	infile_fd = open(argv[1], O_RDONLY, 0777);
	if (infile_fd == -1) {
		error(ERR_INFILE);
	}
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

	outfile_fd = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0000664);
	if (outfile_fd == -1)
		error(ERR_OUTFILE);
	dup2(outfile_fd, STDOUT_FILENO);
	argv_two = parse_process_string(argv[3]);
	path = get_path(envp, argv_two[0]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error(ERR_OUTFILE);
	close_pipe_ends(pipe_fd);
	execve(path, argv_two, envp);
}
