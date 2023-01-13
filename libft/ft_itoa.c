/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:07:47 by mverger           #+#    #+#             */
/*   Updated: 2023/01/09 16:52:41 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	int	nb_digit;

	nb_digit = 0;
	if (n < 0)
		nb_digit++;
	while (n != 0)
	{
		nb_digit++;
		n /= 10;
	}
	return (nb_digit);
}

static char	*malloc_str(char *str_output, int nb_digit)
{
	str_output = (char *)malloc(sizeof(char) * (nb_digit + 1));
	if (str_output == NULL)
		return (NULL);
	str_output[nb_digit] = '\0';
	return (str_output);
}

static char	*output_cpy(int n, int nb_digit, char *str_output, int neg)
{
	int	i;
	int	r;
	int	j;

	j = 0;
	i = 0;
	nb_digit -= 1;
	if (neg == 1)
		str_output[i++] = '-';
	while (n != 0)
	{
		r = n % 10;
		if (r < 0)
		{
			r *= -1;
		}
		str_output[nb_digit--] = r + '0';
		j++;
		n = n / 10;
	}
	return (str_output);
}

char	*ft_itoa(int n)
{
	char	*str_output;
	int		nb_digit;
	int		neg;

	str_output = NULL;
	if (n < 0)
		neg = 1;
	else
		neg = 0;
	if (n == 0)
		return (ft_strdup("0"));
	nb_digit = ft_count_digit(n);
	str_output = malloc_str(str_output, nb_digit);
	if (str_output == NULL)
		return (NULL);
	str_output = output_cpy(n, nb_digit, str_output, neg);
	return (str_output);
}

/*int main(void)
{
	char *str = ft_itoa(-9);
	printf("%s\n", str);
	return (0);
}*/