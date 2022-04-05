/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:20:38 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/03 21:08:48 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (src_len && dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (i || !src_len || dstsize == 1)
		dest[i] = '\0';
	return (src_len);
}
