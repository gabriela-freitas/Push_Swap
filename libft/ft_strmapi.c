/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:12:16 by gafreita          #+#    #+#             */
/*   Updated: 2022/02/25 16:23:50 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*new;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	i = -1;
	new = (char *)malloc(len * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (++i < len - 1)
		new[i] = (*f)(i, s[i]);
	new[i] = '\0';
	return (new);
}
