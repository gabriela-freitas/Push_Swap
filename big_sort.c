/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:47:25 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/23 21:03:28 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_or_rrb(int begin, int end);

static void	push_to_b(void)
{
	int	begin;
	int	end;
	int	check;

	begin = 0;
	end = stacks()->chunk_size;
	//print_infos();
	while (begin < stacks()->all)
	{
		check = begin;
		while (check < end)
		{
			if (stacks()->head_a->index < end
				&& stacks()->head_a->index >= begin)
			{
				check += pb();
				//ft_printf("hey\n");
			}
			else
			{
				calculate_moves(begin, end);
				decide_moves();
				//ra_or_rra(begin, end);
			}
		}
		//ft_printf("begin = %d end = %d\n", begin, end);
		end += stacks()->chunk_size;
		begin += stacks()->chunk_size;
		if (end > stacks()->all)
			end = stacks()->all;
	}
}

static void	get_back(void)
{
	int	begin;
	int	end;
	int	check;

	stacks()->chunk_size = 2;
	begin = stacks()->all - stacks()->chunk_size;
	end = stacks()->all;
	while (end >= 0)
	{
		check = begin;
		while (check < end)
		{
			if (stacks()->head_b->index < end
				&& stacks()->head_b->index >= begin)
			{
				check += pa();
				if (stacks()->size_a > 1)
				{
					if (stacks()->head_a->index > stacks()->head_a->next->index)
						sa();
				}
			}
			/*FIXME: n entendi pq da crash*/
			// if (stacks()->size_b > 1 && stacks()->size_b < 4)
			// {
				// if (stacks()->size_b > 1 && stacks()->head_b->next->index < end
				// 	&& stacks()->head_b->next->index >= begin)
				// 	sb();
			// }
			else
				rb_or_rrb(begin, end);
		}
		//ft_printf("begin = %d end = %d\n", begin, end);
		if ((end - stacks()->chunk_size) < 0)
			break ;
		end -= stacks()->chunk_size;
		begin -= stacks()->chunk_size;
		if (begin < 0)
			begin = 0;
	}
}

void	big_sort(void)
{
	push_to_b();
	get_back();
}

void	rb_or_rrb(int begin, int end)
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
