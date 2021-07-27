# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 13:07:24 by jnovotny          #+#    #+#              #
#    Updated: 2021/07/27 21:30:53 by jnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET=libft_unittest
LIB=../libft.a

CFLAGS= -I../includes/

ifdef SPEED
CFLAGS+= -DSPEEDTEST=1
endif

ifdef VERB
CFLAGS += -DVERBOSE=1
endif

CC?=clang-7

.PHONY: all clean fclean re build

all: build run

build:
	$(CC) $(CFLAGS) -c libft_test_main.c -o libft_test_main.o
	$(CC) $(CFLAGS) -o $(TARGET) libft_test_main.o $(LIB)

run:
	./$(TARGET) files/loremipsum
	@rm -f files/tmp_gnltest

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(TARGET)
