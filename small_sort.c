/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:38:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/18 23:15:47 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **head);
void	small_sort(t_stack **head);

//FIXME: SOMETHING IS OFF
// o que entra aqui tem index 0 1 2 3 4
void	small_sort(t_stack **head)
{
	int		size;

	size = t_stack_size(*head);
	if ((size == stacks()->all || size == stacks()->chunk_size)
		&& check_last_move(stacks()->head_a))
		return ;
	if (size > 3)
	{
		if ((*head)->index > 2 || (*head)->index <= stacks()->all - 1)
			px(head_a_or_b(*head));
		else
			rx_or_rrx_range(*head, 3, stacks()->all - 1);
	}
	if (size == 3)
	{
		sort_three(head);
		//FIXME: this is weird
		while (stacks()->size_b)
			pa(); //going back
		//sa(stacks());
	}
	small_sort(head);
}

void	sort_three(t_stack **head)
{
	static int	size;

	size = stacks()->all - 1;
	if (check_sorted_asc(*head))
		return ;
	else if ((*head)->index == size)
		rx(head_a_or_b(*head));
	else if ((*head)->next->index == size - 2 || (*head)->index == size - 2)
		sx(head_a_or_b(*head));
	else if (t_stack_last(*head)->index == size - 2)
		rrx(head_a_or_b(*head));
	sort_three(head);
}

