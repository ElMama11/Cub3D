/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:22:00 by mverger           #+#    #+#             */
/*   Updated: 2021/11/03 12:16:47 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}

/*int main (void)
{
    signed char c = 31;

    printf("ft  %d\n",ft_isprint(c));
    printf("vrai  %d",isprint(c));

    return (0); 
}*/