NAME			= pipex.a

SRCS			= pipex
					
OBJS			= $(SRCS:=.o)

LIBFT_OBJS	= 42_Libft/*.o

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS) libft
				ar rcs $@ $(OBJS) $(LIBFT_OBJS)

%.o: %.c
				$(CC) -c $(CFLAGS) $?


libft:
				make -C 42_Libft

clean:
				$(RM) $(OBJS)
				make -C 42_Libft clean

fclean:			clean
					$(RM) $(NAME) 42_Libft/libft.a

re:					fclean $(NAME)

.PHONY:			all libft clean fclean re