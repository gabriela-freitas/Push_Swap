/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:54:33 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/28 22:27:26 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//The last element becomes the first one.
void	reverse_rotate(t_stack **head)
{
	t_stack	*aux;

	aux = *head;
	while ((aux->next)->next)
		aux = aux->next;
	t_stack_add_front(head, t_stack_last(*head));
	aux->next = NULL;
}

int	rra(t_info *stacks)
{
	reverse_rotate(&(stacks->head_a));
	return (ft_printf("rra\n"));
}

int	rrb(t_info *stacks)
{
	reverse_rotate(&(stacks->head_b));
	return (ft_printf("rrb\n"));
}

int	rrr(t_info *stacks)
{
	reverse_rotate(&(stacks->head_a));
	reverse_rotate(&(stacks->head_b));
	return (ft_printf("rrr\n"));
}
