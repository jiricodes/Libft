/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:39:15 by jnovotny          #+#    #+#             */
/*   Updated: 2021/08/04 20:06:43 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <inttypes.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** String manipulation
*/

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
int					ft_atoi(const char *str);
int					ft_atoi_and_index(const char *str, size_t *index);
long long			ft_latoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_itoa_into_buf(int n, char *buf, size_t *buf_len);
char				*ft_uitoa(unsigned int n);
char				*ft_itoa_base(int value, int base, int upcase);
char				*ft_uitoa_base(unsigned int value, int base, int upcase);
char				*ft_ltoa(long n);
char				*ft_ultoa(unsigned long n);
void				ft_ultoa_into_buf(unsigned long n, \
									  char *buf, \
									  size_t *buf_len);
char				*ft_ltoa_base(long value, int base, int upcase);
char				*ft_ultoa_base(unsigned long value, int base, int upcase);
char				*ft_lftoa(long double n, unsigned int precision);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, \
								const char *needle, \
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_isspace(char c);
void				ft_strset(char *str, char c, size_t n);
int					ft_strendwith(const char *src, const char *suffix);

/*
** Output functions
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Calculus
*/

int					ft_min_sqrt(int nb);
int					ft_power(int nb, int power);
long				ft_power_l(long nb, long power);
unsigned long		ft_power_ul(unsigned long nb, long power);
long				ft_base_len(long nb, long base);
size_t				ft_base_ulen(unsigned long nb, long base);

/*
** MEMORY MANIIPULATION
*/

void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_memdel(void **ap);
void				*ft_realloc(void *ptr, size_t original, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** LISTS MANIPULATION
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
#endif
