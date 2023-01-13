/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:35:42 by mverger           #+#    #+#             */
/*   Updated: 2021/11/06 18:14:40 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	searched_char;

	i = 0;
	str = (unsigned char *)s;
	searched_char = (unsigned char) c;
	while (i < n)
	{
		if (searched_char == *str)
			return ((char *)str);
		i++;
		str++;
	}
	return (NULL);
}

/*int main(void)
{
	char str[20] = "Marabobaboutage";

	printf("ft_memchr premiere occurence = %s\n", ft_memchr(str, 'o', 15));
	printf("memchr premiere occurence = %s", memchr(str, 'o', 15));
	return (0);
}*/