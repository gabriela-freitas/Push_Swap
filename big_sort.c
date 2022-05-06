/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:47:25 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/28 22:04:23 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b_pb_or_rra(t_info *stacks, int *index);

void	big_sort(t_info *stacks)
{
	static int	index = 0;

	if (stacks->size_a == stacks->all && check_last_move(stacks))
		return ;
	if (stacks->size_a > 5)
	{
		b_pb_or_rra(stacks, &index);
	}
	if (stacks->size_a == 5)
	{
		small_sort(stacks);
		while (stacks->size_a < stacks->all)
			pa(stacks);
	}
	// print_infos(stacks);
	// ft_printf("index = %d\n", index);
	big_sort(stacks);
}

static void	b_pb_or_rra(t_info *stacks, int *index)
{
	if (stacks->head_a->index == *index)
	{
		pb(stacks);
		(*index) = (*index) + 1;
		return ;
	}
	else if (t_stack_last(stacks->head_a)->index == *index)
		rra(stacks);
	else
		ra(stacks);
	b_pb_or_rra(stacks, index);
}
