# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zedr0 <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 12:13:19 by zedr0             #+#    #+#              #
#    Updated: 2023/10/31 20:49:15 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT_PATH	= libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRC			= src/ft_printf.c src/ft_parse.c src/ft_print_chars.c \
			  src/ft_print_diu.c src/ft_print_hex.c \
			  src/ft_print_ptr.c

SRCB		= srcb/ft_printf_bonus.c srcb/ft_parse_bonus.c \
			  srcb/ft_print_chars_bonus.c srcb/ft_print_diu_bonus.c \
			  srcb/ft_print_hex_bonus.c srcb/ft_print_ptr_bonus.c

LIBFT_OBJS	= $(LIBFT_PATH)/*.o
OBJS		= $(SRC:.c=.o)
OBJSB		= $(SRCB:.c=.o)

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
	@echo "\n\tSUCCESS!"

bonus: $(OBJSB)
	@echo "\nCompiling libft..."
	$(MAKE) $(LIBFT_PATH) extra
	cp $(LIBFT) $(NAME)
	@echo "\nBuilding archive..."
	$(AR) $(NAME) $(OBJSB)
	@echo "\n\tSUCCESS!"

clean:
	$(MAKE) $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
