/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:38:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/19 15:35:12 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_three(t_stack **head);
//int			pb_or_rra_or_ra(int size);
void		small_sort(void);
static int	check_last_move_a(void);

void	small_sort(void)
{
	int	size;

	size = stacks()->chunk_size;
	if ((stacks()->size_a == size) && check_last_move_a())
		return ;
	if (stacks()->size_a > 3)
	{
		if (stacks()->head_a->index >= 0
			&& stacks()->head_a->index < stacks()->all - 3)
			pb();
		else
			ra_or_rra(0, stacks()->all - 3);
	}
	if (stacks()->size_a == 3)
	{
		sort_three(&(stacks()->head_a));
		while (stacks()->size_b)
			pa();
	}
	small_sort();
}

void	sort_three(t_stack **head)
{
	static int	size;

	size = stacks()->chunk_size - 1;
	if (check_sorted_asc(*head))
		return ;
	else if ((*head)->index == size)
		ra();
	else if ((*head)->next->index == size - 2 || (*head)->index == size - 2)
		sa();
	else if (t_stack_last(*head)->index == size - 2)
		rra();
	sort_three(head);
}

// int	pb_or_rra_or_ra(int size)
// {
// 	int	i;
// 	int	check;

// 	check = 0;
// 	i = -1; //to generalize
// 	while (++i < size - 3)
// 	{
// 		if (t_stack_last(stacks()->head_a)->index == i)
// 			check = rra();
// 		if (stacks()->head_a->index == i)
// 			check = pb();
// 	}
// 	if (!check)
// 		ra();
// 	return (0);
// }

static int	check_last_move_a(void)
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
