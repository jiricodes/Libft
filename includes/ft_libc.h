/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:22:22 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/20 12:24:09 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBC
# define FT_LIBC

# include <limits.h>
# include <sys/types.h>

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *b, size_t len);

#endif // FT_LIBC
