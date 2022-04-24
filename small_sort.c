/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:38:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/24 22:21:18 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *stacks)
{
	if (check_sorted_asc(stacks->head_a))
		return ;
	else if (stacks->head_a->index == (stacks->size_a - 1))
		ra(stacks);
	else if (stacks->head_a->next->index == 0)
		sa(stacks);
	else if (t_stack_last(stacks->head_a)->index == 0)
		rra(stacks);
	else if (stacks->head_a->index == 0)
		ra(stacks);
	sort_three(stacks);
}
