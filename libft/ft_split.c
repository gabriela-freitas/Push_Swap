/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:57:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/03 21:07:45 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
			words ++;
		while (*s != c && *s != '\0')
			s ++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	size_t	len;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		if (!ft_strchr(s, c))
			len = ft_strlen(s);
		else
			len = (size_t)ft_strchr(s, c) - (size_t)s;
		new[i++] = ft_substr(s, 0, len);
		s = s + len;
	}
	new[i] = NULL;
	return (new);
}
