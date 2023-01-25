/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palamede13 <palamede13@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:51:10 by jthibaul          #+#    #+#             */
/*   Updated: 2022/07/04 14:49:51 by palamede13       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_fill(char *buf, char *str, int fd)
{
	int		error;
	char	*new;
	int		i;

	i = 0;
	error = read(fd, buf, BUFFER_SIZE);
	if ((error == -1 || buf[0] == 0) && !str)
		return (NULL);
	if (buf[0] == 0 && str[0])
		return (str);
	while (buf[i] != '\n' && buf[i] != '\0' && i != BUFFER_SIZE)
		i++;
	new = ft_strjoin_gnl(str, buf, i + 1);
	if (new == NULL)
		return (NULL);
	if (buf[i] == '\n' || buf[i] == 0)
		buf_mem_move(buf, &buf[i]);
	if (i == BUFFER_SIZE)
		new = str_fill(buf, new, fd);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	int			i;

	i = 0;
	str = NULL;
	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (buf[fd][0])
	{
		str = read_buf(buf[fd]);
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			return (str);
	}
	str = str_fill(&buf[fd][0], str, fd);
	return (str);
}
