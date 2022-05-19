/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:07:32 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/18 22:30:49 by gafreita         ###   ########.fr       */
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

int	sa(void)
{
	swap(&(stacks()->head_a), &(stacks()->head_a->next));
	return (ft_printf("sa\n"));
}

int	sb(void)
{
	swap(&(stacks()->head_b), &(stacks()->head_b->next));
	return (ft_printf("sb\n"));
}

int	ss(void)
{
	swap(&(stacks()->head_a), &(stacks()->head_a->next));
	swap(&(stacks()->head_b), &(stacks()->head_b->next));
	return (ft_printf("ss\n"));
}

int	sx(char id)
{
	if (id == 'a')
		return (sa());
	else
		return (sb());
}
