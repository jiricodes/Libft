# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 13:07:24 by jnovotny          #+#    #+#              #
#    Updated: 2022/05/07 13:58:42 by jnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET=libft_unittest
LIB=../libft.a

CFLAGS= -I../includes/ -I. -O3

ifdef SPEED
CFLAGS+= -DSPEEDTEST=1
endif

ifdef VERB
CFLAGS += -DVERBOSE=1
endif

CC?=gcc

OGPF = ogprintf
FTPF = ftprintf
OGPF_LOG=files/OGPF_log
FTPF_LOG=files/FTPF_log
PF_TL ?= 2

UNITSRC=unittest_srcs/unit_ft_bzero.c \
		unittest_srcs/unit_ft_memccpy.c \
		unittest_srcs/unit_ft_memcpy.c \
		unittest_srcs/unit_ft_memset.c \
		unittest_srcs/unit_ft_memmove.c \
		unittest_srcs/unit_ft_memchr.c \
		unittest_srcs/unit_ft_memcmp.c \
		unittest_srcs/unit_ft_strlen.c \
		unittest_srcs/unit_ft_strdup.c \
		unittest_srcs/unit_ft_strcpy.c \
		unittest_srcs/unit_ft_strncpy.c \
		unittest_srcs/unit_ft_strcat.c \
		unittest_srcs/unit_ft_strncat.c

UNITOBJ = $(UNITSRC:.c=.o)

.PHONY: all clean fclean re build

all: build run

unittest_srcs/%.o: unittest_srcs/%.c
	@gcc $(CFLAGS) -o $@ -c $<

build: $(UNITOBJ)
	$(CC) $(CFLAGS) -c libft_test_main.c -o libft_test_main.o
	$(CC) $(CFLAGS) -o $(TARGET) libft_test_main.o $(UNITOBJ) $(LIB)

run:
	./$(TARGET) files/loremipsum
	-@rm -f files/tmp_gnltest

printf_test:
	@echo "ft_printf speed test"
	@$(CC) $(CFLAGS) -c test_ft_printf_main.c -o test_ft_printf_main.o
	@$(CC) $(CFLAGS) -o $(FTPF) test_ft_printf_main.o $(LIB)
	@$(CC) $(CFLAGS) -c test_orig_printf.c -o test_orig_printf.o
	@$(CC) $(CFLAGS) -o $(OGPF) test_orig_printf.o
	@./$(FTPF) $(PF_TL) > $(FTPF_LOG)
	@./$(OGPF) $(PF_TL) > $(OGPF_LOG)
	@tail -n 1 $(FTPF_LOG)
	@tail -n 1 $(OGPF_LOG)
	@./scripts/pf_test.sh $(OGPF_LOG) $(FTPF_LOG)

clean:
	@rm -f *.o $(OGPF_LOG) $(FTPF_LOG) $(UNITOBJ)


fclean: clean
	@rm -f $(TARGET) $(OGPF) $(FTPF)
