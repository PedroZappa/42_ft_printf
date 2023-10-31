# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 12:13:19 by zedr0             #+#    #+#              #
#    Updated: 2023/10/31 08:28:33 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRC			= ft_printf.c ft_parse.c ft_print_chars.c ft_print_diu.c ft_print_hex.c
OBJS		= $(SRC:.c=.o)
LIBFT_OBJS	= $(LIBFT_PATH)/*.o

MAKE		= make -C 
CFLAGS		= -Wall -Wextra -Werror
INC			= -I .
CC			= cc
RM			= rm -f
AR			= ar rcs


all: $(NAME)

.o:.c
	@echo "\nCompiling $<"
	$(CC) $(CFLAGS) $(INC) -c $<

$(NAME): $(OBJS)
	@echo "\nCompiling libft..."
	$(MAKE) $(LIBFT_PATH) extra
	cp $(LIBFT) $(NAME)
	@echo "\nBuilding archive..."
	$(AR) $(NAME) $(OBJS)
	@echo "\n\t\tSUCCESS!"

# bonus: $(NAME)

clean:
	$(MAKE) $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
