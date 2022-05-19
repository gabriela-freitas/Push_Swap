/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:38:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/19 17:47:31 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_three(t_stack **head);
void		small_sort(void);

void	small_sort(void)
{
	int	size;

	size = stacks()->chunk_size;
	if ((stacks()->size_a == size) && check_last_move())
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
