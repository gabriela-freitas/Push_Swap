/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:38:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/28 22:10:15 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_info *stacks, t_stack *head);
static void	sort_small(t_info *stacks);
static int	pb_or_rra(t_info *stacks, int size);
void		small_sort(t_info *stacks);
int			check_last_move(t_info *stacks);

void	small_sort(t_info *stacks)
{
	if (stacks->size_a == 2)
		sa(stacks);
	else
		sort_small(stacks);
}

//function to check if its one movement away from ordering
int	check_last_move(t_info *stacks)
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
		reverse_rotate(&(stacks->head_a));
		if (!check_sorted_asc(stacks->head_a))
		{
			rotate(&(stacks->head_a));
			return (0);
		}
		ft_printf("rra\n");
	}
	if (!check_sorted_asc(stacks->head_a))
		return (0);
	return (1);
}

static void	sort_small(t_info *stacks)
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
		sort_three(stacks, stacks->head_a);
		i = -1;
		while (++i < size - 3)
			pa(stacks);
	}
	sort_small(stacks);
}

static void	sort_three(t_info *stacks, t_stack *head)
{
	static int	size;

	size = stacks->all - 1;
	if (check_sorted_asc(head))
		return ;
	else if (head->index == size)
		ra(stacks);
	else if (head->next->index == size - 2
		|| head->index == size - 2)
		sa(stacks);
	else if (t_stack_last(head)->index == size - 2)
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
		if (stacks->head_a->index == i)
		{
			pb(stacks);
			check ++;
			return (1);
		}
		else if (t_stack_last(stacks->head_a)->index == i)
		{
			rra(stacks);
			check ++;
			return (1);
		}
	}
	return (0);
}
