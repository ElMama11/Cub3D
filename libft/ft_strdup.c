/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:43:05 by mverger           #+#    #+#             */
/*   Updated: 2021/11/08 16:57:30 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str_malloc;

	i = 0;
	while (s1[i])
		i++;
	str_malloc = (char *) malloc((i + 1) * sizeof(char));
	if (str_malloc == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_malloc[i] = s1[i];
		i++;
	}
	str_malloc[i] = '\0';
	return (str_malloc);
}

/*int	main(void)
{
	char str[15] = "Monq";

	printf("ft_strdup = %s\n", ft_strdup(str));
	printf("strdup = %s\n", strdup(str));
	return (0);
}*/