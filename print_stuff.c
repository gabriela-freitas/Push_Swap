/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:42:33 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/26 20:21:21 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_infos(t_info *info)
{
	t_stack	*aux;

	ft_printf("\n\tStack A size: %d\n", info->size_a);
	aux = info->head_a;
	if (!aux)
		ft_printf("\tThere's no stack A!\n");
	while (aux)
	{
		ft_printf("\tvalue: %d >>> index: %d\n", aux->value, aux->index);
		aux = aux->next;
	}
	ft_printf("\n\tStack B size: %d\n", info->size_b);
	aux = info->head_b;
	if (!aux)
		ft_printf("\tThere's no stack B!\n\n");
	while (aux)
	{
		ft_printf("\tvalue: %d >>> index: %d\n", aux->value, aux->index);
		aux = aux->next;
	}
}

void	print_node(t_stack *node)
{
	t_stack	*aux;

	aux = node;
	if (!aux)
		ft_printf("There's no stack!\n");
	else
		ft_printf("value: %d >>> index: %d\n", aux->value, aux->index);
}
