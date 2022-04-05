/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:05:33 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/09 18:46:05 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_base(long long int n, char *base);
static int	check_identifier(const char c, va_list args);
static int	ft_putchar_str(va_list args, const char c);

int	ft_printf(const char *s, ...)
{
	char	*index;
	size_t	len;
	int		count;
	va_list	arguments;

	va_start(arguments, s);
	count = 0;
	while (s)
	{
		index = ft_strchr(s, '%');
		if (index == 0)
		{
			count += write(1, s, ft_strlen(s));
			break ;
		}
		len = (size_t)index - (size_t)s;
		index = ft_substr(s, 0, len + 1);
		count += write(1, index, len);
		s += len;
		count += check_identifier(*(++s), arguments);
		s++;
		free (index);
	}
	va_end(arguments);
	return (count);
}

static int	ft_putnbr_base(long long int n, char *base)
{
	int	temp;

	temp = n;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= (long long int)ft_strlen(base))
	{
		ft_putnbr_base(n / ft_strlen(base), base);
		ft_putnbr_base(n % ft_strlen(base), base);
	}
	else
		write(1, &base[n], 1);
	return (int_count(temp, ft_strlen(base)));
}

static int	ft_u_base(unsigned int n, char *base)
{
	unsigned int	temp;

	if (n < 0)
		ft_u_base(n, base);
	temp = n;
	if (n >= (unsigned long)ft_strlen(base))
	{
		ft_u_base(n / ft_strlen(base), base);
		ft_u_base(n % ft_strlen(base), base);
	}
	else
		write(1, &base[n], 1);
	return (unsigned_count(temp, ft_strlen(base)));
}

static int	ft_putchar_str(va_list args, const char c)
{
	int		count;
	char	aux;
	char	*str;

	if (c == 'c')
	{
		aux = va_arg(args, int);
		count = write (1, &aux, 1);
	}
	else
	{
		str = va_arg(args, char *);
		if (!str)
			return (write(1, "(null)", 6));
		count = write (1, str, ft_strlen(str));
	}
	return (count);
}

static int	check_identifier(const char c, va_list args)
{
	int		count;

	if (c == 'd' || c == 'i')
		count = ft_putnbr_base(va_arg(args, int), "0123456789");
	if (c == 'u')
		count = ft_u_base(va_arg(args, unsigned int), "0123456789");
	if (c == 'x')
		count = ft_u_base(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		count = ft_u_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		count = write(1, "%%", 1);
	if (c == 'p')
	{
		write (1, "0x", 2);
		count = ft_u_add(va_arg(args, uintptr_t), "0123456789abcdef") + 2;
	}
	if (c == 's' || c == 'c')
		count = ft_putchar_str(args, c);
	return (count);
}
