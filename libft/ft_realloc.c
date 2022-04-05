/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:25:56 by gafreita          #+#    #+#             */
/*   Updated: 2022/02/23 22:57:10 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *old, size_t old_size, size_t new_size)
{
	char	*new;

	if (!old)
		return ((char *)malloc((new_size)));
	new = (char *)malloc((new_size));
	if (!new)
		return (NULL);
	ft_memcpy(new, old, old_size);
	free(old);
	return (new);
}
