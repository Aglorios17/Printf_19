# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 10:57:10 by hbuisser          #+#    #+#              #
#    Updated: 2020/02/03 16:32:48 by aglorios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS_LIST = \
			ft_charconverter.c \
			ft_ltoa_base.c \
			ft_converterandstruct.c \
			ft_printf.c \
			ft_utoa_base.c \
			ft_flagcheck.c \
			ft_strcpy2.c \
			ft_utils.c \
			ft_converter.c \
			ft_converter_c.c \
			ft_converter_s.c \
			ft_converter2_s.c \
			ft_converter_i.c \
			ft_converter2_i.c \
			ft_converter3_i.c \
			ft_converter4_i.c \
			ft_converter_x.c \
			ft_converter2_x.c \
			ft_converter3_x.c \
			ft_converter4_x.c \
			ft_converter5_x.c \
			ft_converter_x_norme.c \
			ft_converter_u.c \
			ft_converter2_u.c \
			ft_converter3_u.c \
			ft_converter4_u.c \
			ft_converter_p.c \
			ft_converter2_p.c \
			ft_converter_modulo.c \

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})
OBJS			= ${SRCS:.c=.o}
HEADER			= include
FOLDER			= srcs
LIBFT 			= libft
CC				= clang
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}
$(NAME):		${OBJS}
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar rcs $(NAME) $(OBJS)
bonus:			${NAME}
%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<
clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)
fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)
re:				fclean all
.PHONY: 		all fclean clean re
