/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:54:33 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/18 22:30:41 by gafreita         ###   ########.fr       */
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

int	rra(void)
{
	reverse_rotate(&(stacks()->head_a));
	return (ft_printf("rra\n"));
}

int	rrb(void)
{
	reverse_rotate(&(stacks()->head_b));
	return (ft_printf("rrb\n"));
}

int	rrr(void)
{
	reverse_rotate(&(stacks()->head_a));
	reverse_rotate(&(stacks()->head_b));
	return (ft_printf("rrr\n"));
}

int	rrx(char id)
{
	if (id == 'a')
		return (rra());
	else
		return (rrb());
}
