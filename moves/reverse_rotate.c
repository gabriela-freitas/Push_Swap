/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:54:33 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/23 21:28:21 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//The last element becomes the first one.
void	reverse_rotate(t_stack **head)
{
	t_stack	*aux;

	if (!head || t_stack_size(*head) == 1)
		return ;
	if (t_stack_size(*head) <= 2)
	{
		swap(head, &((*head)->next));
		return ;
	}
	aux = *head;
	while ((aux->next)->next)
		aux = aux->next;
	t_stack_add_front(head, t_stack_last(*head));
	aux->next = NULL;
}

int	rra(void)
{
	if (stacks()->size_a)
	{
		reverse_rotate(&(stacks()->head_a));
		return (ft_printf("rra\n"));
	}
	else
		return (0);
}

int	rrb(void)
{
	if (stacks()->size_b)
	{
		reverse_rotate(&(stacks()->head_b));
		return (ft_printf("rrb\n"));
	}
	else
		return (0);
}

int	rrr(void)
{
	if (stacks()->size_a)
		reverse_rotate(&(stacks()->head_a));
	if (stacks()->size_a)
		reverse_rotate(&(stacks()->head_b));
	return (ft_printf("rrr\n"));
}
