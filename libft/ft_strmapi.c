/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:10:25 by mverger           #+#    #+#             */
/*   Updated: 2021/11/17 20:05:00 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_malloc;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	str_malloc = NULL;
	i = 0;
	str_malloc = ft_strdup(s);
	if (str_malloc == NULL)
		return (NULL);
	while (str_malloc[i])
	{
		str_malloc[i] = (f)(i, str_malloc[i]);
		i++;
	}
	return (str_malloc);
}

/*int	main(void)
{
	char str[50] = "Marabout";

	printf("La nouvelle chaine est %s", ft_strmapi(str,));
}*/