/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:07:32 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/24 18:44:21 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head, t_stack **next)
{
	t_stack	*aux;

	aux = *head;
	(*head) = *next;
	(aux)->next = (*next)->next;
	(*head)->next = aux;
}

void	sa(t_info *stacks)
{
	swap(&(stacks->head_a), &(stacks->head_a->next));
	ft_printf("sa\n");
}

void	sb(t_info *stacks)
{
	swap(&(stacks->head_b), &(stacks->head_b->next));
	ft_printf("sb\n");
}

void	ss(t_info *stacks)
{
	swap(&(stacks->head_a), &(stacks->head_a->next));
	swap(&(stacks->head_b), &(stacks->head_b->next));
	ft_printf("ss\n");
}
