/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:05:29 by ftroiter          #+#    #+#             */
/*   Updated: 2023/03/17 15:39:52 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> 	// open
# include <stdlib.h> 	// malloc, exit
# include <stdio.h> 	// perror, printf
# include <string.h> 	// strerror
# include <sys/types.h> // fork, wait
# include <sys/wait.h>  // wait, waitpid
# include <errno.h>  	// errno
# include <unistd.h>	// close, read, write, access
						// dup, dup2, execve, fork, pipe

# define ERR_ARGS "Invalid number of arguments.\n"
# define ERR_INFILE "In file"
# define ERR_OUTFILE "Out file"
# define ERR_PIPE "Pipe"
# define ERR_FORK "Fork"
# define ERR_CMD "Command"
# define ERR_SCRIPT "Script"
# define ERR_CHILD "Error in process "

// pipex.c
int		pipex(char *argv[], char *envp[]);
void	process_one(char *argv[], char *envp[], int pipe_fd[]);
void	process_two(char *argv[], char *envp[], int pipe_fd[]);

// utils.c
void	check_process_exit(int wstatus, int process);
void	error(char *err);
char	**parse_process_string(char	*process_string);
char	*get_path(char *envp[], char *process);

// split.c
char	**ft_pipex_split(char const *s, char c);

#endif
