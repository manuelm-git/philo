# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manumart <manumart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 15:38:55 by manumart          #+#    #+#              #
#    Updated: 2024/02/27 21:47:42 by manumart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#$(VERBOSE).SILENT:

NAME = philo

SRCS_NAME =	main.c \
			utils.c	\
			init.c	\
			timeNclean.c \
			philo_tse.c	\
			philo_tseutils.c \
			routine.c
			

CC = cc
CFLAGS = -Wall -Werror -Wextra  -g -fsanitize=thread

RM = rm -rf

SRC_PATH = ./

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRCS_NAME))

all: $(NAME)

$(NAME) : $(OBJS)
		@echo "\e[0;32m Project : ($(NAME)) compiled successfully\033[0m"
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c 
	mkdir -p objects
	$(CC) $(CFLAGS)	-c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rmdir objects
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

