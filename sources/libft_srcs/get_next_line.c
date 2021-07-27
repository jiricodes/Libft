/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:47:46 by jnovotny          #+#    #+#             */
/*   Updated: 2021/07/27 20:46:48 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*assign_str(char **stack, const int fd)
{
	int		i;
	char	*res;
	char	*extr;

	i = 0;
	while (stack[fd][i] != '\n' && stack[fd][i] != '\0')
		i = i + 1;
	if (stack[fd][i] == '\n')
	{
		res = ft_strsub(stack[fd], 0, i);
		extr = ft_strsub(stack[fd], i + 1, ft_strlen(stack[fd]) - (i + 1));
		free(stack[fd]);
		stack[fd] = extr;
	}
	else
	{
		res = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	return (res);
}

static char	*strjoin_clean(char *stack, char const *buf)
{
	char	*res;
	size_t	len_stack;
	size_t	len_buf;

	if (!stack)
		return (ft_strdup(buf));
	else if (!buf)
		return (stack);
	len_stack = ft_strlen(stack);
	len_buf = ft_strlen(buf);
	res = ft_memalloc(len_stack + len_buf + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, stack, len_stack);
	ft_memcpy(res + len_stack, buf, len_buf);
	if (len_stack > 0)
		free(stack);
	return (res);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stack[GNL_MAX_FD];
	char		buf[GNL_BUFF_SIZE + 1];
	int			ret;
	char		*temp;

	if (fd < 0 || fd > GNL_MAX_FD || !line)
		return (-1);
	ret = read(fd, buf, GNL_BUFF_SIZE);
	while (0 < ret)
	{
		buf[ret] = '\0';
		temp = strjoin_clean(stack[fd], buf);
		stack[fd] = temp;
		if (ft_strchr(buf, 10))
			break ;
		ret = read(fd, buf, GNL_BUFF_SIZE);
	}
	if (ret == -1)
		return (ret);
	if (ret == 0 && (stack[fd] == NULL || stack[fd][0] == '\0'))
		return (ret);
	*line = assign_str(stack, fd);
	return (*line != NULL);
}
