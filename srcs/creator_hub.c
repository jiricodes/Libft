/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_hub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:41:58 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/13 16:25:58 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Functions Hub
** Mandatory conversions: c s p d i o u x X f
** Bonus conversions: b
*/

void	ft_create_out(t_format *f, const char *format)
{
	if (format[f->i] == 'd' || format[f->i] == 'i')
		ft_process_di(f);
	else if (format[f->i] == 'x' || format[f->i] == 'X')
		ft_process_xx(f, format);
	else if (format[f->i] == 'o')
		ft_process_o(f);
	else if (format[f->i] == 'b')
		ft_process_b(f);
	else if (format[f->i] == 'u')
		ft_process_u(f);
	// else if (format[f->i] == 'f')
	// 	ft_process_f(f, format);
	// else if (format[f->i] == 'c')
	// 	ft_process_c(f, format);
	// else if (format[f->i] == 's')
	// 	ft_process_s(f, format);
	// else if (format[f->i] == 'p')
	// 	ft_process_p(f, format);
}