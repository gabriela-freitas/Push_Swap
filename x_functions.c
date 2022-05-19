/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:43:30 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/19 17:42:24 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	head_a_or_b(t_stack *head)
{
	char	id;

	if (head == stacks()->head_a)
		id = 'a';
	else
		id = 'b';
	return (id);
}

//function to check if its one movement away from ordering
int	check_last_move_x(t_stack *head)
{
	int		size;

	size = t_stack_size(head);
	if (head->index == 1 && head->next->index == 0
		&& check_sorted_asc(head->next->next))
		sx(head_a_or_b(head));
	else if (head->index == size - 1 && check_sorted_asc(head->next))
		rx(head_a_or_b(head));
	else if (t_stack_last(head)->index == 0)
	{
		reverse_rotate(&(head));
		if (!check_sorted_asc(head))
		{
			rotate(&(head));
			return (0);
		}
		ft_printf("rr%c\n", head_a_or_b(head));
	}
	return (check_sorted_asc(head));
}

//FIXME: something with id
void	rx_or_rrx_range(t_stack *head, int begin, int end)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = head;
	while (aux)
	{
		if (aux->index >= begin || aux->index < end || i >= stacks()->all / 2)
			break ;
		aux = aux->next;
		i ++;
	}
	if (i < stacks()->all / 2)
		rx(head_a_or_b(head));
	else
		rrx(head_a_or_b(head));
}
