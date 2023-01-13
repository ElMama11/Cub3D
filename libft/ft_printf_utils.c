/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:15:46 by mverger           #+#    #+#             */
/*   Updated: 2022/02/23 16:03:32 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putcharr(int c)
{	
	int	i;

	i = 0;
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_putnbrr(int n)
{
	unsigned int	nb;
	int				counter;

	counter = 0;
	nb = n;
	if (n < 0)
	{
		ft_putcharr('-');
		nb = n * -1;
		counter++;
	}
	if (nb >= 10)
		counter += ft_putnbrr(nb / 10);
	ft_putcharr((nb % 10) + '0');
	counter++;
	return (counter);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	unsigned int	nb;
	static int		i;

	i = 0;
	nb = n;
	if (nb >= 10)
		ft_unsigned_putnbr(nb / 10);
	i++;
	ft_putcharr((nb % 10) + '0');
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_convert_ptr(unsigned long n)
{
	unsigned long	nb;
	int				i;
	int				counter;
	char			output[17];

	counter = 0;
	i = 0;
	nb = n;
	write(1, "0x", 2);
	if (n == 0)
		counter = write(1, "0", 1);
	while (n != 0)
	{
		nb = n % 16;
		if (nb < 10)
			output[i++] = nb + '0';
		else
			output[i++] = nb + 87;
		n = n / 16;
	}
	counter = counter + i + 2;
	while (i > 0)
		write(1, &output[--i], 1);
	return (counter);
}
