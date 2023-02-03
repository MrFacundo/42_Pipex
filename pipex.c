#include "pipex.h"
#include "42_Libft/libft.h"

int pipex(char *fd_in, char *process_one, char *process_two, char *fd_out)
{

	int fd1;
	char *line;
	char *path;
	char **argv;
	int i;
	pid_t pid;
	int infile_fd;
	int saved_stdout_fd;

	char *envp[] =
		{
			"HOME=/",
			"PATH=/bin:/usr/bin",
			0
		};

	fd1 = open(fd_in, O_RDONLY);
	line = ft_get_next_line(fd1);
	argv = ft_split(process_one, ' ');
	i = 0;
	while (argv[i])
		i++;
	argv[i++] = line;
	argv[i] = 0;
	path = ft_strjoin("/bin/", argv[0]);

	infile_fd = open(fd_out, O_CREAT | O_TRUNC | O_WRONLY);
	// saved_stdout_fd = dup(STDOUT_FILENO);

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		dup2(infile_fd, STDOUT_FILENO);
		execve(path, argv, envp);
	}
	wait(NULL);
	// dup2(saved_stdout_fd, STDOUT_FILENO);

	printf("Done executing %s", process_one);

	return 0;
}