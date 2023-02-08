#include "pipex.h"
#include "42_Libft/libft.h"

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
	{
		printf("Usage: ./pipex filein cmd1 cmd2 fileout\n");
	}
	return (0);
}