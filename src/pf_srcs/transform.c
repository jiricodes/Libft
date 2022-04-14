/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:57:05 by jnovotny          #+#    #+#             */
/*   Updated: 2021/08/05 09:30:36 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void	handle_sign(t_format *f)
{
	if (f->flag.sign == -1)
	{
		add_n_chars_to_buffer(f, '-', 1);
	}
}

void	transform_int_with_precision(t_format *f, unsigned long number)
{
		
}