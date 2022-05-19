/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:23:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/19 21:44:22 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//FIXME: create error functions when a malloc fails half way there

static void	sort_small_b(void);
static void	re_index_b(void);
void		sort_three_b(t_stack **head);
static void	rb_or_rrb(int index);

//move to stack B one chunk at a time, and sorting o the way back
void	new_big_sort(void)
{
	int	begin;
	int	end;
	int	check;

	begin = stacks()->all - stacks()->chunk_size;
	end = stacks()->all;
	while (!(stacks()->size_a == stacks()->all && check_last_move()))
	{
		//ft_printf("begin = %d end = %d\n", begin, end);
		check = begin;
		while (check < end)
		{
			if (stacks()->head_a->index < end
				&& stacks()->head_a->index >= begin)
				check += pb();
			else
				ra_or_rra(begin, end);
		}
		re_index_b();
		sort_small_b();
		if ((end - stacks()->chunk_size) < 0)
			end = 0;
		else
			end -= stacks()->chunk_size;
		begin -= stacks()->chunk_size;
		if (begin < 0)
			break ;
		//print_infos();
	}
}

//re-index b using the aux variable instead of the index
static void	re_index_b(void)
{
	int		*arr;
	int		i;
	t_stack	*stack;
	int		size;

	size = t_stack_size(stacks()->head_b);
	arr = selection_sort_array(stack_to_array(stacks()->head_b), size);
	stack = stacks()->head_b;
	while (stack)
	{
		i = -1;
		while (++i < size)
		{
			if (arr[i] == stack->value)
				stack->aux = i;
		}
		stack = stack->next;
	}
	free(arr);
}

/*searching for the bigger numbers, going back to a and then sorting 3 numbers.
here, the stack b is re-indexed in the camp aux of the stack*/
static void	sort_small_b(void)
{
	int	i;

	i = stacks()->size_b - 1; //6
	while (stacks()->size_b > 3) //3
	{
		if (stacks()->head_b->aux == i)
		{
			pb();
			i --;
		}
		else
			rb_or_rrb(i);
	}
	sort_three_b(&(stacks()->head_b));
	while (stacks()->size_b)
		pa();
}

/*decide for rb or rrb
always searching for AUX*/
static void	rb_or_rrb(int index)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = stacks()->head_b;
	while (stack)
	{
		if ((stack->aux == index)
			|| i == (stacks()->size_b / 2))
			break ;
		stack = stack->next;
		i ++;
	}
	if (i < (stacks()->size_a / 2))
		rb();
	else
		rrb();
}



void	sort_three_b(t_stack **head)
{
	if (check_sorted_desc(*head))
		return ;
	else if ((*head)->aux == 0)
		rb();
	else if ((*head)->next->aux == 2 || (*head)->aux == 2)
		sb();
	else if (t_stack_last(*head)->aux == 2)
		rrb();
	sort_three_b(head);
}
