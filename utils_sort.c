/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:41:22 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/28 22:42:27 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if a stack is sorted >> ascending order
int	check_sorted_asc(t_stack *stack)
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
