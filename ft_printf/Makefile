# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bokim <bokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:50:58 by bokim             #+#    #+#              #
#    Updated: 2021/07/08 22:14:48 by bokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ft_printf.c \
	   ft_puts.c \
	   ft_parse.c \
	   ft_conversion.c \
	   ft_convert_char.c \
	   ft_convert_int.c \
	   ft_convert_str.c \
	   ft_convert_percent.c \
	   ft_convert_unsigned.c \
	   ft_convert_hex.c \
	   ft_convert_ptr.c
INCLUDE = ft_printf.h
OBJS = ${SRCS:.c=.o}
RM = rm -rf

LIBC = ar rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCLUDE}

${NAME} : ${OBJS}
	make all -C ${LIBFT}/
	cp ${LIBFT}/${LIBFT_LIB} ${NAME}
	${LIBC} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}
		make clean -C ${LIBFT}

fclean: clean
		${RM} ${NAME}
		make fclean -C ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
