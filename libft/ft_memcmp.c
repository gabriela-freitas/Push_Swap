/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:19:13 by gafreita          #+#    #+#             */
/*   Updated: 2022/02/22 16:25:35 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i)
		&& i < (int)n - 1)
		i ++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
