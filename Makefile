# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 15:44:22 by jnovotny          #+#    #+#              #
#    Updated: 2022/04/20 21:56:24 by jnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME = libft.a

# Source Files
CFILES = libc/ft_memset.c \
		 libc/ft_bzero.c \
		 libc/ft_memcpy.c

# Object Files
OFILES = $(CFILES:.c=.o)

# Folders
SRC_DIR = src
OBJ_DIR = tmp


# Pathing
SRCS = $(addprefix $(SRC_DIR)/, $(CFILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(OFILES))

# Flags
INCLUDES = -I includes/
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

# Colors
C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_GREEN = \033[1;32m
C_BLUE = \033[1;34m
C_L_BLUE = \033[1;34m
C_WHITE = \033[1;37m
C_RES = \033[0m

# Tools and Utils
LOGO = yes
COMP = yes

.PHONY: all clean fclean re test

all: $(NAME)

logo:
ifeq (yes, $(LOGO))
	@echo "$(C_BLUE) _     _ _    ______ _____ $(C_RES)"
	@echo "$(C_BLUE)| |   (_) |   |  ___|_   _|$(C_RES)"
	@echo "$(C_BLUE)| |    _| |__ | |_    | |  $(C_RES)"
	@echo "$(C_BLUE)| |   | | '_ \|  _|   | |  $(C_RES)"
	@echo "$(C_BLUE)| |___| | |_) | |     | |  $(C_RES)"
	@echo "$(C_BLUE)\_____/_|_.__/\_|     \_/  $(C_RES)"
	@echo "\n"
LOGO = no
endif

$(OBJ_DIR): logo
	@/bin/mkdir -p $(OBJ_DIR)/libc

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(CFLAGS) -o $@ -c $<
	@echo "*\c"

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rcs $@ $(OBJS)
	@echo "$(C_GREEN)\n[Library Created!]$(C_RES)"

clean: logo
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(C_RED)[Objects deleted!]$(C_RES)"
	@make -C tests clean --no-print-directory

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(C_RED)[Removed $(NAME)]$(C_RES)"
	@make -C tests fclean --no-print-directory

re: fclean all


test:
	make -C tests VERB=1 SPEED=1 --no-print-directory