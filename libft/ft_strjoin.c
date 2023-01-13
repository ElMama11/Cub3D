/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:34:56 by mverger           #+#    #+#             */
/*   Updated: 2021/11/17 20:09:38 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str_malloc;

	str_malloc = NULL;
	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str_malloc = (char *)malloc((i + j + 1) * sizeof(char));
	if (str_malloc == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str_malloc[i] = s1[i];
		i++;
	}
	while (s2[j])
		str_malloc[i++] = s2[j++];
	str_malloc[i] = '\0';
	return (str_malloc);
}

/*int	main(void)
{
	char	s1[15] = "Mara";
	char	s2[15] = "bout";

	printf("La nouvelle chaine = %s", ft_strjoin(s1,s2));
	return (0);
}*/