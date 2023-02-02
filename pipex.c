#include "pipex.h"
#include "42_Libft/libft.h"

int	pipex(char *fd_in, char *process_one, char *process_two, char *fd_out)
{

	int fd1;
	char	*line;
	char	*path;
	char	**process_contents;
	char 	**argv;
	int	i;
	int	j;

    char *envp[] =
    {
        "HOME=/",
        "PATH=/bin:/usr/bin",
        0
    };
	fd1 = open(fd_in, O_RDONLY);
	line = ft_get_next_line(fd1);
	process_contents = ft_split(process_one, ' ');
	argv = process_contents;
	i = 0;
	while (process_contents[i])
		i++;
	i++;
	argv[i] = line;
	i++;
	argv[i] = 0;
	j = 0;
	while (argv[j]){
		printf("%s\n", argv[j]);
		j++;
	}
	path = ft_strjoin("/bin/", process_contents[0]);
	// printf("%s", path);
	// execve(path, argv, envp);

	// printf("\nfd_in: %s\nprocess_one: %s\nprocess_two: %s\nfd_out: %s\n", fd_in, process_one, process_two, fd_out);
	return 0;
}