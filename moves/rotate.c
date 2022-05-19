/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:06:24 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/18 22:30:38 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//The first element becomes the last one.

void	rotate(t_stack **head)
{
	t_stack	*aux;

	aux = *head;
	*head = (*head)->next;
	t_stack_last(aux)->next = aux;
	aux->next = NULL;
}

int	ra(void)
{
	rotate(&(stacks()->head_a));
	return (ft_printf("ra\n"));
}

int	rb(void)
{
	rotate(&(stacks()->head_b));
	return (ft_printf("rb\n"));
}

int	rr(void)
{
	rotate(&(stacks()->head_a));
	rotate(&(stacks()->head_b));
	return (ft_printf("rr\n"));
}

int	rx(char id)
{
	if (id == 'a')
		return (ra());
	else
		return (rb());
}
