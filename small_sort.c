/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:38:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/26 21:36:48 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_info *stacks);
static int	check_last_move(t_info *stacks);
static void	sort_five(t_info *stacks);
static void	sort_four(t_info *stacks);

void	small_sort(t_info *stacks)
{
	if (stacks->size_a == 2)
		sa(stacks);
	if (stacks->size_a == 3)
		sort_three(stacks);
	if (stacks->size_a == 4)
		sort_four(stacks);
	if (stacks->size_a == 5)
		sort_five(stacks);
}

static void	sort_three(t_info *stacks)
{
	static int	size;

	size = stacks->all - 1;
	if (check_sorted_asc(stacks->head_a))
		return ;
	else if (stacks->head_a->index == size)
		ra(stacks);
	else if (stacks->head_a->next->index == size - 2
		|| stacks->head_a->index == size - 2)
		sa(stacks);
	else if (t_stack_last(stacks->head_a)->index == size - 2)
		rra(stacks);
	sort_three(stacks);
}

//function to check if its one movement away from ordering
static int	check_last_move(t_info *stacks)
{
	t_stack	*head;
	int		size;

	head = stacks->head_a;
	size = stacks->size_a;
	if (head->index == size - 1 && check_sorted_asc(head->next))
		ra(stacks);
	if (head->index == 1 && head->next->index == 0
		&& check_sorted_asc(head->next->next))
		sa(stacks);
	if (t_stack_last(head)->index == 0)
	{
		reverse_rotate(&head);
		if (!check_sorted_asc(head))
		{
			rotate(&head);
			return (0);
		}
	}
	if (!check_sorted_asc(head))
		return (0);
	return (1);
}

static void	sort_five(t_info *stacks)
{
	if (stacks->size_a >= 4)
	{
		if (stacks->head_a->index == 0 || stacks->head_a->index == 1)
			pb(stacks);
		else
			ra(stacks);
	}
	if (stacks->size_a == 3)
	{
		sort_three(stacks);
		pa(stacks);
		pa(stacks);
	}
	if (stacks->size_a == 5 && check_last_move(stacks))
		return ;
	sort_five(stacks);
}

static void	sort_four(t_info *stacks)
{
	if (stacks->size_a == 4 && check_last_move(stacks))
		return ;
	if (stacks->size_a == 4)
	{
		if (stacks->head_a->index == 0)
			pb(stacks);
		else
			ra(stacks);
	}
	if (stacks->size_a == 3)
	{
		sort_three(stacks);
		pa(stacks);
	}
	sort_four(stacks);
}
