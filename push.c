/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:11:08 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/28 22:27:02 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **donator, t_stack **receiver)
{
	t_stack	*aux;

	if (!donator)
		return ;
	aux = *donator;
	*donator = (*donator)->next;
	t_stack_add_front(receiver, aux);
}

int	pa(t_info *stacks)
{
	push(&stacks->head_b, &stacks->head_a);
	stacks->size_a = t_stack_size(stacks->head_a);
	stacks->size_b = t_stack_size(stacks->head_b);
	return (ft_printf("pa\n"));
}

int	pb(t_info *stacks)
{
	push(&stacks->head_a, &stacks->head_b);
	stacks->size_a = t_stack_size(stacks->head_a);
	stacks->size_b = t_stack_size(stacks->head_b);
	return (ft_printf("pb\n"));
}
