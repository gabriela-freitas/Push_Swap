/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:57:58 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/21 17:41:49 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//FIXME: check if a stack is sorted >> ascending order
int	check_sorted_ascending(t_stack *stack)
{
	t_stack		*next;
	t_stack		*temp;

	temp = stack;
	while (temp && temp->next)
	{
		next = temp->next;
		if (temp->value > next->value)
			return (0);
		temp = next;
	}
	return (1);
}
//FIXME: check if a stack is sorted >> descending order

// int	check_sorted_descending(t_stack *lst)
// {
// 	t_stack		*next;
// 	t_stack		*temp;

// 	temp = lst;
// 	while (temp && temp->next)
// 	{
// 		next = temp->next;
// 		if (temp->value < next->value)
// 			return (0);
// 		temp = next;
// 	}
// 	return (1);
// }

//FIXME: Sort an array
void	selection_sort_array(int *array, int size)
{
	int	aux;
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
	}
}

//function to check for duplicates
int	check_duplicates(t_stack *lst)
{
	t_stack	*aux;
	t_stack	*temp;

	temp = lst;
	while (temp)
	{
		aux = temp->next;
		while (aux)
		{
			if (aux->value == temp->value)
				return (0);
			aux = aux->next;
		}
		temp = temp->next;
	}
	return (1);
}
