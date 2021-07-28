/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 23:49:40 by jnovotny          #+#    #+#             */
/*   Updated: 2021/07/28 19:52:18 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	res = ft_strnew(ft_strlen(s));
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(s[i]);
		i = i + 1;
	}
	return (res);
}
