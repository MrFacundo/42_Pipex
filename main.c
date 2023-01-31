#include "pipex.h"

void main()
{
	int pfret;
	int ftpfret;

	void *ptr = (void *)NULL;
	pfret = printf("%x\n", 42);
	ftpfret = ft_printf("%x\n", 42);
	printf("%d\n", pfret);
	printf("%d\n", ftpfret);

}