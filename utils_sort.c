/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:41:22 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/19 15:30:07 by gafreita         ###   ########.fr       */
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
int	check_last_move(t_stack *head)
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

void	ra_or_rra(int begin, int end)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = stacks()->head_a;
	while (aux)
	{
		if ((aux->index >= begin && aux->index < end)
			|| i == (stacks()->size_a / 2))
			break ;
		aux = aux->next;
		i ++;
	}
	if (i < (stacks()->size_a / 2))
		ra();
	else
		rra();
}

int	*stack_to_array(t_stack *head)
{
	int		*arr;
	int		i;
	t_stack	*aux;
	int		size;

	size = t_stack_size(head);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	size = t_stack_size(head);
	aux = head;
	i = -1;
	while (aux && ++i < size)
	{
		arr[i] = aux->value;
		aux = aux->next;
	}
	return (arr);
}
