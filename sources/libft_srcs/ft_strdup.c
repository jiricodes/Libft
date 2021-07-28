/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:48:15 by jnovotny          #+#    #+#             */
/*   Updated: 2021/07/28 19:50:50 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * (l + 1));
	if (cpy == NULL)
		return (NULL);
	while (i < l)
	{
		cpy[i] = s1[i];
		i = i + 1;
	}
	cpy[i] = '\0';
	return (cpy);
}
