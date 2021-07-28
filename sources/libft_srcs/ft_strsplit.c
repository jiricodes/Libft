/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:46:11 by jnovotny          #+#    #+#             */
/*   Updated: 2021/07/28 19:40:27 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) obtained
** by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL. Example:
** ft_strsplit("*hello*fellow***students*", ’*’)
** returns the array ["hello", "fellow", "students"].
*/

static size_t	ft_wrdcnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (s[i] == '\0')
		return (cnt);
	if (s[i] != c)
		cnt = cnt + 1;
	i++;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i - 1] == c))
			cnt = cnt + 1;
		i = i + 1;
	}
	return (cnt);
}

static char	*ft_strsplit_loop(const char *s, char c, size_t *i)
{
	size_t	wrd_l;
	char	*res;

	res = NULL;
	wrd_l = 0;
	while (s[*i] == c)
		*i = *i + 1;
	while ((s[*i + wrd_l] != c) && (s[*i + wrd_l] != '\0'))
		wrd_l++;
	if (s[*i] != '\0')
		res = ft_strsub(s, *i, wrd_l);
	*i = *i + wrd_l;
	return (res);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	wrd_i;
	size_t	wrd_count;

	if (!s)
		return (NULL);
	wrd_count = ft_wrdcnt(s, c);
	res = (char **)malloc(sizeof(char *) * (wrd_count + 1));
	if (!res)
		return (NULL);
	i = 0;
	wrd_i = 0;
	while (s[i] != '\0' && wrd_i < wrd_count)
	{
		res[wrd_i] = ft_strsplit_loop(s, c, &i);
		wrd_i = wrd_i + 1;
	}
	res[wrd_i] = NULL;
	return (res);
}
