/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:40:44 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/01 13:02:54 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Allocates (with malloc(3))
and returns a numbering representing the integer received as an argument.
Negative numbers must be handled.*/

static int	check_negative(long int *nb)
{
	if (*nb < 0)
	{
		*nb *= -1;
		return (1);
	}
	else
		return (0);
}

static int	number_of_digits(long int nb)
{
	int			i;
	long int	d;

	d = 1;
	i = 0;
	while (nb >= d)
	{
		i ++;
		d *= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			digits;
	int			negative;
	char		*number;
	long int	nb;

	nb = (long int)n;
	if (nb == 0)
		return (ft_strdup("0"));
	negative = check_negative(&nb);
	digits = number_of_digits(nb) + 1;
	if (negative)
		digits++;
	number = (char *)malloc(digits * sizeof(char));
	if (!number)
		return (NULL);
	digits --;
	number[digits] = '\0';
	if (negative)
		number[0] = '-';
	while (--digits >= negative)
	{
		number[digits] = (nb % 10) + '0';
		nb /= 10;
	}
	return (number);
}
