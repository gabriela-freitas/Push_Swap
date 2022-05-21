/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:41:22 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/21 23:23:10 by gafreita         ###   ########.fr       */
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

//FIXME: used only on new big sort
//check if a stack is sorted >> descending order
int	check_sorted_desc(t_stack *stack)
{
	t_stack		*temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->value < temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/*decides whether to do ra or rra based on the position*/
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

/*puts the content of the stack in a array
used for index*/
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

/*check if the stack is one movement away for being ordered
returns whether is ordened or*/
int	check_last_move(void)
{
	int		size;

	size = stacks()->size_a;
	if (stacks()->head_a->index == 1 && stacks()->head_a->next->index == 0
		&& check_sorted_asc(stacks()->head_a->next->next))
		sa();
	else if (stacks()->head_a->index == size - 1
		&& check_sorted_asc(stacks()->head_a->next))
		ra();
	else if (t_stack_last(stacks()->head_a)->index == 0)
	{
		reverse_rotate(&(stacks()->head_a));
		if (!check_sorted_asc(stacks()->head_a))
		{
			rotate(&(stacks()->head_a));
			return (0);
		}
		ft_printf("rra\n");
	}
	return (check_sorted_asc(stacks()->head_a));
}
