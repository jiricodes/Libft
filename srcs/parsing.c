/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:44:15 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/11 18:04:41 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getinfo(t_format *f, const char *format)
{
	f->i++;
	ft_getflag(f, format);
	ft_getwidth(f, format);
	ft_getprecision(f, format);
}

void	ft_parse(t_format *f, const char *format)
{
	/* get values */
	ft_getinfo(f, format);
	/* create string */
	// ft_create_out(f, format);
	/* output string */
	/* free string? */
}