/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:29:51 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/12 20:54:03 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>

# define FLAG_STR "0#+- "
# define F_HASH_ERR "diucsCSpnm"
# define F_ZERO_ERR "csCSpnm"

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
	char	sign;
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
void	ft_error(t_format *f);

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
** Flags
*/

void	ft_runflags(t_format *f, const char *format);
void	flag_hash(t_format *f, const char *format);
void	flag_zero(t_format *f, const char *format);
void	flag_plus(t_format *f);
void	flag_minus(t_format *f, const char *format);
void	flag_space(t_format *f, const char *format);

/*
** Conversions
*/

void	ft_process_di(t_format *f);

/*
**	Printers
*/

void	ft_print_di(t_format *f);

/*
**	di - tools
*/

void	ft_prec_di(t_format *f);
void	ft_sign(t_format *f);
void	ft_add_sign(t_format *f);

#endif