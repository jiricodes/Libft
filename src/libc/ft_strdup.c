/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:48:15 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/07 12:14:47 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strdup() function returns a pointer to a new string
 * 		  which is a duplicate of the string s. Memory for the new string
 * 		  is obtained with malloc(3), and can be freed with free(3).
 * 
 * 		  On success, the strdup() function returns a pointer to the duplicated
 * 		  string. It returns NULL if insufficient memory was available,
 * 		  with errno set to indicate the cause of the error.
 * 
 * @param s pointer to the original string
 * @return char* pointer to the duplicate string or NULL
 */
char	*ft_strdup(const char *s)
{
	char			*ret;
	register size_t	len;

	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	ft_memcpy(ret, s, len);
	return (ret);
}
