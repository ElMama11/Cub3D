/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:19:24 by mverger           #+#    #+#             */
/*   Updated: 2022/02/23 16:02:50 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convert_low_hexa(unsigned int n)
{
	unsigned int	nb;
	int				i;
	int				counter;
	char			output[8];

	i = 0;
	nb = n;
	counter = 0;
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
	counter = counter + i;
	while (i > 0)
		write(1, &output[--i], 1);
	return (counter);
}

int	ft_convert_upper_hexa(unsigned int n)
{
	unsigned int	nb;
	int				i;
	int				counter;
	char			output[8];

	counter = 0;
	i = 0;
	nb = n;
	if (n == 0)
		counter = write(1, "0", 1);
	while (n != 0)
	{
		nb = n % 16;
		if (nb < 10)
			output[i++] = nb + '0';
		else
			output[i++] = nb + 55;
		n = n / 16;
	}
	counter = counter + i;
	while (i > 0)
		write(1, &output[--i], 1);
	return (counter);
}

int	check_type(char c, int counter, va_list args)
{
	if (c == 'd' || c == 'i')
		counter = counter + ft_putnbrr(va_arg(args, int));
	else if (c == 'c')
		counter = counter + ft_putcharr(va_arg(args, int));
	else if (c == 's')
		counter = counter + ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		counter = counter + ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		counter = counter + ft_convert_low_hexa(va_arg(args, unsigned int));
	else if (c == 'X')
		counter = counter + ft_convert_upper_hexa(va_arg(args, unsigned int));
	else if (c == 'p')
		counter = counter + ft_convert_ptr(va_arg(args, unsigned long));
	else if (c == '%' || c == '\0')
		counter = counter + write(1, "%", 1);
	else
		counter = counter + write(1, &c, 1);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	va_start(args, format);
	if (format[i] == '%' && format[i + 1] == '\0')
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter = check_type(format[i + 1], counter, args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			counter++;
		}
		i++;
	}
	return (counter);
}
