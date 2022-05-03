/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:38:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/03 18:55:53 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_three(t_info *stacks, t_stack **head);
static int	pb_or_rra(t_info *stacks, int size);
void		small_sort(t_info *stacks);

void	small_sort(t_info *stacks)
{
	int	size;
	int	i;

	size = stacks->all;
	if (stacks->size_a == size && check_last_move(stacks))
		return ;
	if (stacks->size_a > 3)
	{
		if (pb_or_rra(stacks, size) == 0)
			ra(stacks);
	}
	if (stacks->size_a == 3)
	{
		sort_three(stacks, &(stacks->head_a));
		i = -1;
		while (++i < size - 3)
			pa(stacks);
	}
	small_sort(stacks);
}

void	sort_three(t_info *stacks, t_stack **head)
{
	static int	size;

	size = stacks->all - 1;
	if (check_sorted_asc(*head))
		return ;
	else if ((*head)->index == size)
		ra(stacks);
	else if ((*head)->next->index == size - 2 || (*head)->index == size - 2)
		sa(stacks);
	else if (t_stack_last(*head)->index == size - 2)
		rra(stacks);
	sort_three(stacks, head);
}

static int	pb_or_rra(t_info *stacks, int size)
{
	int	i;
	int	check;

	check = 0;
	i = -1;
	while (++i < size - 3)
	{
		if (t_stack_last(stacks->head_a)->index == i)
			check = rra(stacks);
		if (stacks->head_a->index == i)
			check = pb(stacks);
	}
	if (check)
		return (1);
	return (0);
}
