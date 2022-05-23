/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:47:25 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/23 21:31:46 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rb_or_rrb(int begin, int end);
static void	push_to_b(void);
static void	get_back(void);

void	big_sort(void)
{
	push_to_b();
	get_back();
}

static void	push_to_b(void)
{
	int	begin;
	int	end;
	int	check;

	begin = 0;
	end = stacks()->chunk_size;
	while (begin < stacks()->all)
	{
		check = begin;
		while (check < end)
		{
			if (stacks()->head_a->index < end
				&& stacks()->head_a->index >= begin)
				check += pb();
			else
				ra_or_rra(begin, end);
		}
		end += stacks()->chunk_size;
		begin += stacks()->chunk_size;
		if (end > stacks()->all)
			end = stacks()->all;
	}
}

static void	get_back(void)
{
	int	range[2];
	int	check;

	stacks()->chunk_size = 2;
	range[0] = stacks()->all - stacks()->chunk_size;
	range[1] = stacks()->all;
	while (range[1] >= 0)
	{
		check = range[0];
		while (check < range[1])
		{
			if (stacks()->head_b->index < range[1]
				&& stacks()->head_b->index >= range[0])
				check += pa();
			else
				rb_or_rrb(range[0], range[1]);
			if (stacks()->size_a > 1
				&& stacks()->head_a->index > stacks()->head_a->next->index)
				sa();
		}
		range[1] -= stacks()->chunk_size;
		range[0] -= stacks()->chunk_size;
		if (range[0] < 0)
			range[0] = 0;
	}
}

static void	rb_or_rrb(int begin, int end)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = stacks()->head_b;
	while (aux)
	{
		if (aux->index >= begin && aux->index < end)
			break ;
		aux = aux->next;
		i ++;
	}
	if (i < (stacks()->size_b / 2))
		rb();
	else
		rrb();
}
