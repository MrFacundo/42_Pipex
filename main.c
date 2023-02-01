#include "pipex.h"
#include "42_Libft/libft.h"
#include "42_ft_printf/ft_printf.h"


int main()
{
	int pipexret;
	
	pipexret = pipex();
	return (ft_printf("%d\n", pipexret));
	
}