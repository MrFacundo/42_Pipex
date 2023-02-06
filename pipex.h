#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> // open
# include <unistd.h> // close, read, write, access, dup, dup2, execve, fork, pipe
# include <stdlib.h> // malloc, exit
# include <stdio.h> // perror, printf
# include <string.h> // strerror
#include <sys/types.h> // fork, wait
#include <sys/wait.h>  // wait, waitpid
#include <errno.h>  // errno

int		pipex(char *fd_in, char *process_one, char *process_two, char *fd_out);
char	**parse_process_string(char	* process_string);

#endif
