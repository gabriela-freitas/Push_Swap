/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:07:32 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/22 19:32:39 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	*stack = (*stack)->next;
	(*stack) = aux;
}

void	sa(t_info *stacks)
{
	swap(&(stacks->head_a));
	ft_printf("sa\n");
}

void	sb(t_info *stacks)
{
	swap(&(stacks->head_b));
	ft_printf("sb\n");
}

void	ss(t_info *stacks)
{
	sa(stacks);
	sb(stacks);
	ft_printf("ss\n");
}
