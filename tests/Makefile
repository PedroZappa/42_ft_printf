# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 14:37:32 by zedr0             #+#    #+#              #
#    Updated: 2023/10/20 16:23:22 by zedr0            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ftprintf.znet

SRC		= munit/munit.c main.c 
OBJS	= $(SRC:.c=.o)

CFLAGS	= -Wall -Werror -Wextra
INC		= -I munit/
CC		= cc
RM		= rm -f
AR		= ar rcs


all: $(NAME)

.o:.c
	$(CC) $(CFLAGS) $(INC) -c $<

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
