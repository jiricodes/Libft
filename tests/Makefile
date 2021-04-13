# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 22:21:08 by jnovotny          #+#    #+#              #
#    Updated: 2021/04/14 00:16:30 by jnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_test
CC ?= gcc

# ORIG_NAME ?= ../ft_ssl

ARGS =

ifdef SPEED
ARGS += -s
endif

ifdef TL
ARGS += -t $(TL)
endif


INCLUDES = -I ../includes/

CFLAGS = -DDEBUG=0 -DLOG=0

ifdef VERB
CFLAGS += -DVERBOSE=1
endif

LDFLAGS = -L ../ -lft

SRC_FILES =

# SOURCES_DIR = ../sources

SOURCES = 
# $(addprefix $(SOURCES_DIR)/, $(SRC_FILES))

GEN_SRCS =
			
GEN_N ?= 1000


TEST_SRCS = test.c

SOURCES += $(TEST_SRCS)

# TEST_FILES =	result \
# 				simple \
# 				tmp_leftshiftgen

OBJECTS = $(SOURCES:.c=.o)

FILE_SIZE ?= 1024

.PHONY: all clean fclean re

all: build run

# gen-files:
# 	./scripts/create_list_md5funcs.sh $(GEN_N) $(GEN_MD5_PREFIX)
# 	@sleep 1

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

build:
	make -C ../
	make $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LDFLAGS)

run:
	@./$(NAME) $(ARGS)

clean:
	-@rm $(OBJECTS) 2> /dev/null || true
	-@rm $(GEN_SRCS) 2> /dev/null || true
	# -@rm $(TEST_FILES) 2> /dev/null || true
	# -@rm files/$(TEST_FILES) 2> /dev/null || true
	# -@rm scripts/$(TEST_FILES) 2> /dev/null || true

fclean: clean
	-@rm $(NAME) 2> /dev/null || true

re: fclean all

print:
	@echo "$(SOURCES)"
	@echo "$(OBJECTS)"