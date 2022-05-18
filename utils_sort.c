/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:41:22 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/18 20:08:31 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if a stack is sorted >> ascending order
int	check_sorted_asc(t_stack *stack)
{
	t_stack		*temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

//function to check if its one movement away from ordering
int	check_last_move(t_info *stacks)
{
	t_stack	*head;
	int		size;

	head = stacks->head_a;
	size = stacks->size_a;
	if (head->index == 1 && head->next->index == 0
		&& check_sorted_asc(head->next->next))
		sa(stacks);
	else if (head->index == size - 1 && check_sorted_asc(head->next))
		ra(stacks);
	else if (t_stack_last(head)->index == 0)
	{
		reverse_rotate(&(stacks->head_a));
		if (!check_sorted_asc(stacks->head_a))
		{
			rotate(&(stacks->head_a));
			return (0);
		}
		ft_printf("rra\n");
	}
	return (check_sorted_asc(stacks->head_a));
}

void	ra_or_rra(t_info *stacks, t_stack *head, int index)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = head;
	while (aux)
	{
		if (aux->index == index || i >= stacks->all / 2)
			break ;
		aux = aux->next;
		i ++;
	}
	if (i < stacks->all / 2)
		ra(stacks);
	else
		rra(stacks);
}

void	ra_or_rra_range(t_info *stacks, t_stack *head, int begin, int end)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = head;
	while (aux)
	{
		if (aux->index >= begin || aux->index < end || i >= stacks->all / 2)
			break ;
		aux = aux->next;
		i ++;
	}
	if (i < stacks->all / 2)
		ra(stacks);
	else
		rra(stacks);
}
