# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 14:37:32 by zedr0             #+#    #+#              #
#    Updated: 2023/10/20 17:37:34 by zedr0            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ftprintf.znet

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a

MUNIT_PATH	= munit/

SRC			= munit/munit.c main.c 
OBJS		= $(SRC:.c=.o)

MAKE		= make -C 
CFLAGS		= -Wall -Werror -Wextra
INC			= -L$(MUNIT_PATH)
CC			= cc
RM			= rm -f
AR			= ar rcs


all: $(NAME)

.o:.c
	@echo "\nCompiling znet..."
	$(CC) $(CFLAGS) $(INC) -c $<

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)

get_libft:

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
