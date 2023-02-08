# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: facundo <facundo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 17:08:06 by facundo           #+#    #+#              #
#    Updated: 2023/02/08 17:36:27 by facundo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
# NAME_B  = pipex_bonus

SRCS 	= srcs/pipex.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

# SRCS_B	= srcs/pipex_bonus.c srcs/utils.c srcs/utils_bonus.c
# OBJS_B	= ${SRCS_B:.c=.o}
# MAIN_B	= srcs/pipex_bonus.c

HEADER	= -Iincludes

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@$(CC) ${OBJS} -Llibft -lft -o ${NAME}
					@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"


# bonus:		${NAME_B}

# ${NAME_B}:	${OBJS_B}
# 					@echo "\033[33m----Compiling lib----"
# 					@make re -C ./libft
# 					@$(CC) ${OBJS_B} -Llibft -lft -o ${NAME_B}
# 					@echo "\033[32mPipex Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${NAME}
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

# re_bonus:	fclean bonus

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

.PHONY: all clean fclean re re_bonus bonus party