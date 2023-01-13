/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:18:32 by mverger           #+#    #+#             */
/*   Updated: 2021/11/17 19:09:37 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc_memory;

	alloc_memory = malloc(count * size);
	if (alloc_memory == NULL)
		return (NULL);
	ft_bzero(alloc_memory, count * size);
	return (alloc_memory);
}

/*int	main(void)
{
	char *str = "";
	int size = 8539;
	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));

	printf("ft_calloc = %s\n", ft_calloc(0, 0));
	printf("calloc = %s\n", calloc(0, 0));

	return (0);
}*/