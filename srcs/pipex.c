#include "../includes/pipex.h"
#include "../libft/libft.h"

void	error(char *err)
{
	perror(err);
	exit (1);
}
int pipex(char *infile, char *process_one, char *process_two, char *outfile)
{
	int pipe_fd[2];

	int		infile_fd;
	int		outfile_fd;
	char	*path;
	char	**argv_one;
	char	**argv_two;
	pid_t	pid;
	pid_t	pid2;
	// int		saved_stdout_fd;

	char *envp[] =
		{
			"HOME=/",
			"PATH=/bin:/usr/bin",
			0};
				// Pipe
	if (pipe(pipe_fd) == -1)
		error(ERR_PIPE);
				// Fork
	pid = fork();
	if (pid == -1)
		error(ERR_FORK);
	if (pid == 0)
	{
				// Open infile, route STDIN to infile
		infile_fd = open(infile, O_RDONLY, 0777);
		if (infile_fd == -1)
			error(ERR_INFILE);
		dup2(infile_fd, STDIN_FILENO);
				// Parse process one
		argv_one = parse_process_string(process_one);
				// Create path
		path = ft_strjoin("/bin/", argv_one[0]);
				// Route STDOUT to write end of pipe, exec process
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(path, argv_one, envp);
	}
				// Fork
	pid2 = fork();
	if (pid2 == -1)	return (-1);
	if (pid2 == 0)
	{
				// Open outfile, route STDOUT to outfile
		outfile_fd = open(outfile, O_CREAT | O_TRUNC | O_RDWR, 0000644);
		if (outfile_fd == -1)
			error(ERR_OUTFILE);
		dup2(outfile_fd, STDOUT_FILENO);
				// Parse process two
		argv_two = parse_process_string(process_two);
				// Create path
		path = ft_strjoin("/bin/", argv_two[0]);
				// Route STDIN to read end of pipe, exec process
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(path, argv_two, envp);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
				// End main process
	wait(NULL);
	// printf("Done executing < %s %s | %s > %s", infile, process_one, process_two, outfile);
	return 0;
}

char	**parse_process_string(char	*process_string)
{
	char	**argv;
	int i;

	argv = ft_split(process_string, ' ');
	i = 0;
	while (argv[i])
		i++;
	argv[i] = 0;
	return (argv);
}


int main(int argc, char *argv[])
{
	char	*fd_in;
	char	*process_one;
	char	*process_two;
	char	*fd_out;

	if (argc == 5)
	{

		fd_in = argv[1];
		process_one = argv[2];
		process_two = argv[3];
		fd_out = argv[4];

		return pipex(fd_in, process_one, process_two, fd_out);
	}
	else 
		error(ERR_INPUT);
	return (0);
}