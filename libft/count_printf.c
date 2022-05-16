/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:00:53 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/09 18:45:55 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_count(long long int n, int len)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count ++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= len;
		count ++;
	}
	return (count);
}

int	unsigned_count(unsigned long n, int len)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= len;
		count ++;
	}
	return (count);
}

static int	add_count(uintptr_t n, int len)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= len;
		count ++;
	}
	return (count);
}

int	ft_u_add(uintptr_t n, char *base)
{
	if (n >= (uintptr_t)ft_strlen(base))
	{
		ft_u_add(n / ft_strlen(base), base);
		ft_u_add(n % ft_strlen(base), base);
	}
	else
		write(1, &base[n], 1);
	return (add_count(n, ft_strlen(base)));
}
