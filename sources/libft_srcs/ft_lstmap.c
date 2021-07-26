/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:15:01 by jnovotny          #+#    #+#             */
/*   Updated: 2021/07/26 12:41:24 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the successive
** applications of f. If the allocation fails, the function returns NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new_lst;
	t_list	*node;

	new_lst = NULL;
	node = NULL;
	ret = new_lst;
	while (lst && f)
	{
		node = f(lst);
		if (!node)
			return (NULL);
		if (new_lst)
		{
			new_lst->next = node;
		}
		else
		{
			new_lst = node;
			continue ;
		}
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (ret);
}
