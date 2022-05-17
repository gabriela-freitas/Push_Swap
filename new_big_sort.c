/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:23:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/17 19:37:45 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//I'm gonna try moving to stack B the smaller half
//and sorting stack B everytime I put something there

static void	sort_b(t_info *stacks);

void	new_big_sort(t_info *stacks)
{
	if (stacks->size_a == stacks->all && check_last_move(stacks))
		return ;
	else
	{
		pass_to_b(stacks);
		sort_b(stacks);
	}
	new_big_sort(stacks);
}

static void	sort_b(t_info *stacks)
{

}
