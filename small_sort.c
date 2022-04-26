/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:38:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/26 18:50:04 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_five(t_info *stacks);

void	sort_three(t_info *stacks)
{
	static int	size;

	size = stacks->size_a;
	if (check_sorted_asc(stacks->head_a))
		return ;
	else if (stacks->head_a->index == (size - 1))
		ra(stacks);
	else if (stacks->head_a->next->index == 0
		|| stacks->head_a->index == size - 3)
		sa(stacks);
	else if (t_stack_last(stacks->head_a)->index == size - 3)
		rra(stacks);
	sort_three(stacks);
}

//function to check if its one movement away from ordering
static void	check_five(t_info *stacks)
{
	if (stacks)
		return ;
	else
		return ;
}

void	sort_five(t_info *stacks)
{
	if (check_sorted_asc(stacks->head_a))
		return ;
	if (stacks->size_a == 5)
		check_five(stacks);
	if (stacks->size_a >= 4)
	{
		if (stacks->head_a->index == 0 || stacks->head_a->index == 1)
			pa(stacks);
		else
			ra(stacks);
	}
	else if (stacks->size_a == 3)
		sort_three(stacks);
	sort_five(stacks);
}
