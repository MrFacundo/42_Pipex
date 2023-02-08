NAME			= pipex.a

SRCS			= pipex
					
OBJS			= $(SRCS:=.o)

LIBFT_OBJS		= 42_Libft/*.o

CC				= gcc
RM				= rm -f
CFLAGS			=  -Wall -Werror -Wextra

# --- COLORS ---
NONE='\033[0m'
GRAY='\033[2;37m'
RED='\033[31m'
GREEN='\033[32m'
YELLOW='\033[33m'
MAGENTA='\033[35m'


all:			$(NAME)

$(NAME):		$(OBJS) libft
				ar rcs $@ $(OBJS) $(LIBFT_OBJS)
				@echo "$(GREEN)Pipex Compiled! ᕦ($(RED)♥$(GREEN)_$(RED)♥$(GREEN))ᕤ" $(NONE)

%.o: %.c
				$(CC) -c $(CFLAGS) $?


libft:
				@echo $(GRAY) "- Compiling Libft..." $(NONE)
				make -C 42_Libft

clean:
				$(RM) $(OBJS)
				make -C 42_Libft clean
				@echo "\n$(RED)Cleaning done! ⌐(ಠ۾ಠ)¬\n" $(NONE)

fclean:			clean
				$(RM) $(NAME) 42_Libft/libft.a

l_main:
				$(CC) $(CFLAGS) main.c pipex.a 42_Libft/libft.a -o pipex 
				@echo "$(GRAY)Executable compiled! (=ʘᆽʘ=)∫" $(NONE)

re:				fclean $(NAME)

party:
					@printf "\033c"
					@echo "\n$(MAGENTA)♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "$(YELLOW)♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n$(MAGENTA)♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "$(YELLOW)♪┗(・o･)┓♪\n"


.PHONY:			all libft clean fclean re