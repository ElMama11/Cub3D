/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthibaul <jthibaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:51:07 by jthibaul          #+#    #+#             */
/*   Updated: 2022/03/17 17:39:12 by jthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove_gnl(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	if (dest > src)
	{
		n++;
		while (--n > 0)
			*(dest + n) = *(src + n);
	}
	else
		while (++i < n)
			dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen2(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int size)
{
	char	*news;
	int		i;
	int		a;

	a = ft_strlen(s1);
	i = 0;
	news = malloc(a + ft_strlen(s2) + 1);
	if (news == NULL)
		return (NULL);
	if (s1)
	{
		i--;
		while (s1[++i])
			news[i] = s1[i];
	}
	if (s2)
	{
		i--;
		while (s2[++i - a] && (i - a) < size)
			news[i] = s2[i - a];
	}
	news[i] = '\0';
	if (s1)
		free(s1);
	return (news);
}

void	buf_mem_move(char *buf, char *c)
{
	int	i;

	i = 0;
	if (*c == '\0')
	{
		while (buf[i])
		{
			buf[i] = 0;
			i++;
		}
	}
	if (*c == '\n')
		ft_memmove_gnl(buf, c + 1, ft_strlen2(&buf[i]));
}

char	*read_buf(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen2(buf) + 1);
	if (str == NULL)
		return (str);
	while (buf[i] != '\n' && buf[i])
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		str[i] = '\n';
		str[i + 1] = '\0';
	}
	else
		str[i] = '\0';
	buf_mem_move(buf, &buf[i]);
	return (str);
}
