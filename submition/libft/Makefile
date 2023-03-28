# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: facundo <facundo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:32:50 by ftroiter          #+#    #+#              #
#    Updated: 2023/02/21 13:33:36 by facundo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa \
					ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar_fd ft_putendl_fd \
					ft_putnbr_fd ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
					ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim \
					ft_substr ft_tolower ft_toupper ft_get_next_line \

BSRCS 			= 	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
					ft_lstiter ft_lstmap ft_lstdelone ft_lstclear 
					
OBJS			= $(SRCS:=.o)
BOBJS			= $(BSRCS:=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS) $(BOBJS)
				ar rcs $(NAME) $(OBJS) $(BOBJS)

clean:
				$(RM) $(OBJS) $(BOBJS)

fclean:			clean
				$(RM) $(NAME)

re:					fclean $(NAME)

.PHONY:			all clean fclean re