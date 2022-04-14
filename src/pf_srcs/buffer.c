/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:20:48 by jnovotny          #+#    #+#             */
/*   Updated: 2021/08/04 10:27:42 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** @brief	Flushes buffer to preset fd
** 
** @param	format PF format struct
** 
*/

void flush_buffer_to_fd(t_format *format)
{
	if (format->buf_position > 0)
	{
		format->out_len += write(format->fd, format->buffer, format->buf_position);
		ft_bzero(format->buffer, PF_BUF_SIZE);
		format->buf_position = 0;
	}
}

/*
** @brief	Adds given string into a buffer. Buffer is flushed if not enough space.
** 
** @param	format Pf format struct
** @param	str String to add to buffer
** @param	len Length of the string
** 
*/

void add_string_to_buffer(t_format *format, const char *str, size_t len)
{
	if (format->buf_position + len >= PF_BUF_SIZE)
		flush_buffer_to_fd(format);
	ft_memcpy(&format->buffer[format->buf_position], str, len);
	format->buf_position += len;
}

/*
** @brief	Adds n characters c into the buffer. Buffer is flushed if no space
** 
** @param	format Pf format struct
** @param	c Character to copy to buffer
** @param	n Number of repetitions
** 
*/

void add_n_chars_to_buffer(t_format *format, char c, size_t n)
{
	if (format->buf_position + n >= PF_BUF_SIZE)
		flush_buffer_to_fd(format);
	ft_memset(&format->buffer[format->buf_position], c, n);
	format->buf_position += n;
}