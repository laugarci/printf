# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 09:51:44 by laugarci          #+#    #+#              #
#    Updated: 2022/10/25 11:13:18 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

HEADER	= 
INCLUDE = -I ./

CFLAGS	= -Wall -Wextra -Werror
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -f
AR		= ar -rcs

SRC_FILES	= ft_printf.c \
			  ft_numbers.c \
			  ft_putchar.c \

SRC_OBJ		= $(SRC_FILES:.c=.o)

SRC_DEPS	= $(SRC_FILES:.c=.d)

all: $(NAME)

%.o : %.c Makefile
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "Compiling $<..."

$(NAME) : $(SRC_OBJ)
	@$(AR) $(NAME) $(SRC_OBJ)
	@echo Compiled!

clean:
	@$(RM) $(SRC_OBJ) $(SRC_DEPS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	$(NORM)

-include $(SRC_DEPS)

.PHONY: all clean fclean re norm
