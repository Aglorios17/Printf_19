# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglorios <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 12:05:15 by aglorios          #+#    #+#              #
#    Updated: 2020/01/20 14:48:30 by aglorios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c

NAME = libft.a

OBJS = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

GCC = gcc

RM = rm -rf

HEADER = ./

all: $(NAME)

$(OBJS): $(SRC)
	$(GCC) -I$(HEADER) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:
	$(GCC) $(CFLAGS) -I$(HEADER) -c $(SBONUS) $(SRC)
	ar rc $(NAME) $(BOBJS)
	ranlib $(NAME)

.PHONY: all test clean fclean re
