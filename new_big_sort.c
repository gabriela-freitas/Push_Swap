/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:23:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/18 20:21:36 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//I'm gonna try moving to stack B the smaller half
//and sorting stack B everytime I put something there

static void	sort_b(t_info *stacks);
static void	pass_five_to_b(t_info *stacks);
static void	sort_small_b(t_info *stacks);

void	new_big_sort(t_info *stacks)
{
	static int	begin = 0;
	static int	end = stacks->chunk_size;

	if (stacks->size_a == stacks->all && check_last_move(stacks))
		return ;
	if (stacks->size_a > stacks->all / 2)
	{
		pass_five_to_b(stacks);
		sort_small_b(stacks);
	}
	if (end + stacks->chunk_size == stacks->all)
		end = stacks->all;
	else
		end += stacks->chunk_size;
	begin += stacks->chunk_size;
	new_big_sort(stacks);
}

//pass x numbers to b, test with different sizes of stacks
static void	pass_five_to_b(t_info *stacks, int begin, int end)
{
	static int	check = begin;

	if (check == end)
		return ;
	if (stacks->head_a->index < end || stacks->head_a->index >= begin)
		check += pb(stacks) / 3;
	ra_or_rra_range(stacks, stacks->head_a, begin, end);
	pass_to_b(stacks, begin, end);
}

//update the sort small to work with anykind of stacks,
//searching for the bigger numbers, going back to a and then sorting 3 numbers.
static void	sort_small_b(t_info *stacks)
{
	if (check_last_move(stacks))
		return ;

}

static void	re_index_B(t_info *stacks)
{
	static int	original[stacks->size_b];
	static int	check = 0;
	t_stack		aux;
	int 		i;
	int			*arr;

	if (!check)
	{
		aux = stacks->head_b;
		i = -1;
		while (aux && ++i >= 0)
		{
			original[i] = aux->index;
			aux = aux->next;
		}
		arr = malloc(sizeof(int) * stacks->size_b);
		aux = stacks->head_b;
		i = -1;
		while (aux && ++i >= 0)
		{
			aux->index = arr[i];
			aux = aux->next;
		}
	}
}
