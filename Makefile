# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 16:55:37 by bokim             #+#    #+#              #
#    Updated: 2022/01/11 23:27:51 by bokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
FT_PRINTF_LIB = ./ft_printf/libftprintf.a

SRC_M_PATH = ./src/
SRC_B_PATH = ./bonus/
INC_M_PATH = ./include/
INC_B_PATH = $(SRC_B_PATH)

SRC_M = client.c\
		server.c
SRC_B = client_bonus.c\
		server_bonus.c

SRCS_M = $(addprefix $(SRC_M_PATH), $(SRC_M))
SRCS_B = $(addprefix $(SRC_B_PATH), $(SRC_B))

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

all: $(CLIENT) $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@make HAS_BONUS=1 all

ifdef HAS_BONUS
$(CLIENT): ./bonus/client_bonus.o
	@make -s -C ft_printf
	@$(CC) $(CFLAGS) -o $@ $^ ${FT_PRINTF_LIB}

$(SERVER): ./bonus/server_bonus.o
	@$(CC) $(CFLAGS) -o $@ $^ ${FT_PRINTF_LIB}

else
$(CLIENT): ./src/client.o
	@make -s -C ft_printf
	@$(CC) $(CFLAGS) -o $@ $^ ${FT_PRINTF_LIB}

$(SERVER): ./src/server.o
	@$(CC) $(CFLAGS) -o $@ $^ ${FT_PRINTF_LIB}
endif

clean:
	@$(RM) $(OBJS_M) $(OBJS_B)

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@make -s $@ -C ft_printf
	@echo deleted all files

re: fclean all

.SILENT: $(OBJS)

.PHONY: all clean fclean re bonus