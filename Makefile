NAME			= pipex

SRCS 			= srcs/pipex.c srcs/utils.c srcs/split.c
OBJS 			= $(SRCS:.c=.o)
LIBFT_DIR 		= ./libft

HEADER			= -Iincludes
CC 				= gcc
RM				= rm -f
CFLAGS_DEV 		= -g
CFLAGS_PROD 	= -Wall -Wextra -Werror -g

# --- COLORS ---
NONE=\033[0m
GRAY=\033[2;37m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
MAGENTA=\033[35m

# --- RULES ---
.c.o:		%.o : %.c
			$(CC) $(CFLAGS_PROD) $(HEADER) -c $< -o $(<:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
			@echo  "$(GRAY)----Compiling Libft----$(NONE)"
			make -C $(LIBFT_DIR)
			@echo  "$(GRAY)----Compiling $(NAME)----$(NONE)"
			$(CC) $(OBJS) -Llibft -lft -o $(NAME)
			@echo "$(GREEN)Pipex Compiled! ᕦ($(RED)♥$(GREEN)_$(RED)♥$(GREEN))ᕤ$(NONE)\n"


clean:
			@echo "$(GREEN)Deleting obs! ( ͡° ͜ʖ ͡°) $(NONE)\n"
			$(RM) $(OBJS)
			make -C $(LIBFT_DIR) clean


fclean: 			
			@echo "$(RED)Deleting EVERYTHING! ( ͡° ͜ʖ ͡°) $(NONE)\n"
			$(RM) $(OBJS)
			$(RM) $(NAME)
			@make fclean -C $(LIBFT_DIR)

re:			fclean all

party:
			@printf "\033c"
			@echo "\n$(MAGENTA)┏(・o･)┛♪"
			@sleep 1
			@printf "\033c"
			@echo "$(YELLOW)♪┗(・o･)┓♪"
			@sleep 1
			@printf "\033c"
			@echo "$(MAGENTA)♪┏(・o･)┛♪"
			@sleep 1
			@printf "\033c"
			@echo "$(YELLOW)♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re party