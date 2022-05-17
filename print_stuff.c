/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:42:33 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/03 18:38:37 by gafreita         ###   ########.fr       */
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
		ft_printf("\tvalue: %d\tindex: %d\n", aux->value, aux->index);
		aux = aux->next;
	}
	ft_printf("\n\tStack B size: %d\n", info->size_b);
	aux = info->head_b;
	if (!aux)
		ft_printf("\tThere's no stack B!\n\n");
	while (aux)
	{
		ft_printf("\tvalue: %d\tindex: %d\n", aux->value, aux->index);
		aux = aux->next;
	}
}

void	print_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (!aux)
		ft_printf("\tThere's no stack!\n\n");
	while (aux)
	{
		ft_printf("\tvalue: %d\tindex: %d\n", aux->value, aux->index);
		aux = aux->next;
	}
}
