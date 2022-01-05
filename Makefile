# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bokim <bokim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 16:55:37 by bokim             #+#    #+#              #
#    Updated: 2022/01/05 17:19:56 by bokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SRC_M_PATH = ./src/
SRC_B_PATH = ./bonus/
INC_M_PATH = ./include/
INC_B_PATH = $(SRC_B_PATH)

SRC_M = client.c\
		server.c\
		utils.c
SRC_B = client_bonus.c\
		server_bonus.c\
		utils_bonus.c

SRCS_M = $(addprefix $(SRC_M_PATH), $(SRC_M))
SRCS_B = $(addprefix $(SRC_B_PATH), $(SRC_B))

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(CLIENT) $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@make HAS_BONUS=1 all

ifdef HAS_BONUS
$(CLIENT): ./bonus/client_bonus.o ./bonus/utils_bonus.o
	@$(CC) $(CFLAGS) -o $@ $^

$(SERVER): ./bonus/server_bonus.o ./bonus/utils_bonus.o
	@$(CC) $(CFLAGS) -o $@ $^

else
$(CLIENT): ./src/client.o ./src/utils.o
	@$(CC) $(CFLAGS) -o $@ $^

$(SERVER): ./src/server.o ./src/utils.o
	@$(CC) $(CFLAGS) -o $@ $^
endif

clean:
	@$(RM) $(OBJS_M) $(OBJS_B)

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)
	@echo deleted all files

re: fclean all

.SILENT: $(OBJS)

.PHONY: all clean fclean re bonus