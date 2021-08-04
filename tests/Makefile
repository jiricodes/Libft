# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 13:07:24 by jnovotny          #+#    #+#              #
#    Updated: 2021/08/04 10:01:20 by jnovotny         ###   ########.fr        #
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

OGPF = ogprintf
FTPF = ftprintf
OGPF_LOG=files/OGPF_log
FTPF_LOG=files/FTPF_log
PF_TL ?= 2

.PHONY: all clean fclean re build

all: build run

build:
	$(CC) $(CFLAGS) -c libft_test_main.c -o libft_test_main.o
	$(CC) $(CFLAGS) -o $(TARGET) libft_test_main.o $(LIB)

run:
	./$(TARGET) files/loremipsum
	@rm -f files/tmp_gnltest
	# @make printf_test

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
	@rm -f *.o $(OGPF_LOG) $(FTPF_LOG)


fclean: clean
	@rm -f $(TARGET) $(OGPF) $(FTPF)
