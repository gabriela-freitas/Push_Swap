/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:06:24 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/24 18:59:04 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//The first element becomes the last one.

static void	rotate(t_stack **head)
{
	t_stack	*aux;

	aux = *head;
	*head = (*head)->next;
	t_stack_last(aux)->next = aux;
	aux->next = NULL;
}

void	ra(t_info *stacks)
{
	rotate(&(stacks->head_a));
	ft_printf("ra\n");
}

void	rb(t_info *stacks)
{
	rotate(&(stacks->head_b));
	ft_printf("rb\n");
}

void	rr(t_info *stacks)
{
	rotate(&(stacks->head_a));
	rotate(&(stacks->head_b));
	ft_printf("rr\n");
}
