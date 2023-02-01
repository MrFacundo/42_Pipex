NAME			= pipex.a

SRCS			= pipex
					
OBJS			= $(SRCS:=.o)

LIBFT_OBJS		= 42_Libft/*.o
FT_PRINTF_OBJS	= 42_ft_printf/*.o

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS) ft_printf libft
				ar rcs $@ $(OBJS) $(FT_PRINTF_OBJS) $(LIBFT_OBJS)
				@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

%.o: %.c
				$(CC) -c $(CFLAGS) $?

ft_printf:
				make -C 42_ft_printf

libft:
				make -C 42_Libft

clean:
				$(RM) $(OBJS)
				make -C 42_Libft clean
				make -C 42_ft_printf clean
				@echo "\n\033[31mCleaning done! ⌐(ಠ۾ಠ)¬\n]"


fclean:			clean
				$(RM) $(NAME) 42_Libft/libft.a

compile_main:
				$(CC) $(CFLAGS) main.c pipex.a 42_Libft/libft.a 42_ft_printf/libftprintf.a -o exe 
				./exe

re:				fclean $(NAME)

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"


.PHONY:			all ft_printf libft clean fclean re