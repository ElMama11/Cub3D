/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:09:32 by mverger           #+#    #+#             */
/*   Updated: 2021/11/16 16:28:54 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str_malloc;

	str_malloc = NULL;
	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		return (ft_strdup("\0"));
	if (len >= i - start)
		str_malloc = (char *)malloc(((i - start) + 1) * sizeof(char));
	else if (len < i - start)
		str_malloc = (char *)malloc((len + 1) * sizeof(char));
	if (str_malloc == NULL)
		return (NULL);
	i = 0;
	while (i < len && i <= ft_strlen(s))
		str_malloc[i++] = s[start++];
	str_malloc[i] = '\0';
	return (str_malloc);
}

/*int	main(void)
{
	char	str[50] = "tripouille";
	char	*str_malloc = ft_substr(str, 1, 1);
	printf("La nouvelle chaine est %s\n", str_malloc);
	free(str_malloc);
	return (0);
}*/