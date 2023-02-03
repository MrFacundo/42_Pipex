#include "pipex.h"
#include "42_Libft/libft.h"

int pipex(char *fd_in, char *process_one, char *process_two, char *fd_out)
{
	int pipe_fd[2];

	int infile_fd;
	char *line;
	char *path;
	char **argv_one;
	char **argv_two;
	int i;
	pid_t pid;
	pid_t pid2;
	int outfile_fd;
	int saved_stdout_fd;

	char *envp[] =
		{
			"HOME=/",
			"PATH=/bin:/usr/bin",
			0};
	// Read infile
	infile_fd = open(fd_in, O_RDONLY);
	line = ft_get_next_line(infile_fd);
	// Parse process one
	argv_one = ft_split(process_one, ' ');
	i = 0;
	while (argv_one[i])
		i++;
	argv_one[i++] = line;
	argv_one[i] = 0;
	// Create path
	path = ft_strjoin("/bin/", argv_one[0]);
	// Open outfile
	outfile_fd = open(fd_out, O_CREAT | O_TRUNC | O_WRONLY);
	// Fork
	pid = fork();
	if (pid == -1)
		return (-1);
	// Route STDOUT to write end of pipe, exec process
	if (pid == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(path, argv_one, envp);
	}
	// wait(NULL);

	// Parse process two
	argv_two = ft_split(process_two, ' ');
	i = 0;
	while (argv_two[i])
		i++;
	// argv_two[i++] = line;
	argv_two[i] = 0;
	// Create path
	path = ft_strjoin("/bin/", argv_two[0]);

	// Fork
	pid2 = fork();
	if (pid2 == -1)
		return (-1);
	// Route STDIN to read end of pipe, exec process
	if (pid2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(path, argv_two, envp);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	// End main process
	wait(NULL);
	printf("Done executing %s", process_one);
	return 0;
}

// dup2(saved_stdout_fd, STDOUT_FILENO);
