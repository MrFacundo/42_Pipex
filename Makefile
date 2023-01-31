NAME			= pipex.a

SRCS			= pipex.c
					
OBJS			= $(SRCS:=.o)

LIBFT_OBJS	= libft/*.o

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS) libft
				ar rcs $@ $(OBJS) $(LIBFT_OBJS)

%.o: %.c
				$(CC) -c $(CFLAGS) $?


libft:
				make -C libft

clean:
				$(RM) $(OBJS)
				make -C libft clean

fclean:			clean
					$(RM) $(NAME) libft/libft.a

re:					fclean $(NAME)

.PHONY:			all libft clean fclean re