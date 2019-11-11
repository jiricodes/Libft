/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:29:51 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/11 18:47:33 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>

# define FLAG_STR "0#+- "

/*
** Flag management struct
*/

typedef struct	s_flag
{
	char	zero;
	char	hash;
	char	plus;
	char	minus;
	char	space;
}				t_flag;

/*
** Lenght modifier struct
*/

typedef enum	e_lmod
{
	nomod = 0,
	hh,
	h,
	l,
	ll,
	L
}				t_lmod;

/*
** Core format struct
*/

typedef struct	s_format
{
	va_list list;
	char	*out_str;
	size_t	out_len;
	size_t	i;
	t_flag	flag;
	int		width;
	int		precision;
	t_lmod	len_mod;
	int		conversion;
	int		caps;
}				t_format;

/*
** Core Logistics
*/

int		ft_printf(const char *format, ...);
void	ft_parse(t_format *f, const char *format);
void	ft_getinfo(t_format *f, const char *format);

/*
**	Information fetching
*/

void	ft_getflag(t_format *f, const char *format);
void	ft_getwidth(t_format *f, const char *format);
void	ft_getprecision(t_format *f, const char *format);
void	ft_getlmod(t_format *f, const char *format);


/*
**	Output generators
*/

void	ft_create_out(t_format *f, const char *format);

/*
**	Printers
*/

#endif