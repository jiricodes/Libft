/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v1_0_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:52:04 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/20 13:13:37 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V1_0_FUNCTIONS
# define V1_0_FUNCTIONS

# include <string.h>


void	*v1_0_ft_memset(void *b, int c, size_t len);
void	v1_0_ft_bzero(void *s, size_t n);
void	*v1_0_ft_memcpy(void *dst, const void *src, size_t n);

#endif // V1_0_FUNCTIONS