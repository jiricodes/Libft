/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_hub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:41:58 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/11 19:21:10 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_create_out(t_format *f, const char *format)
{
	if (format[f->i] == 'd' || format[f->i] == 'i')
	{
		f->out_str = ft_itoa_base(va_arg(f->list, int), 2, 1);
		f->i++;
	}
}