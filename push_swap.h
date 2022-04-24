/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:51:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/24 21:43:37 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	t_stack	*head_a;
	int		size_a;
	t_stack	*head_b;
	int		size_b;
}	t_info;

//functions_lists.c
t_stack		*t_stack_last(t_stack *lst);
t_stack		*t_stack_new(int value);
int			t_stack_size(t_stack *lst);
void		t_stack_add_back(t_stack *lst, t_stack *new);
void		t_stack_add_front(t_stack **lst, t_stack *new);
//utils.c
int			check_sorted_asc(t_stack *stack);
	//int			check_sorted_descending(t_stack *lst);
void		selection_sort_array(int *array, int size);
int			check_duplicates(t_stack *lst);
void		free_stack(t_stack *head);
void		free_info(t_info *info);
//push.c
void		pa(t_info *stacks);
void		pb(t_info *stacks);
//swap.c
void		sb(t_info *stacks);
void		ss(t_info *stacks);
void		sa(t_info *stacks);
//rotate.c
void		ra(t_info *stacks);
void		rb(t_info *stacks);
void		rr(t_info *stacks);
//reverse_rotate.c
void		rra(t_info *stacks);
void		rrb(t_info *stacks);
void		rrr(t_info *stacks);
//print_stuff.c
void		print_infos(t_info *info);
void		print_node(t_stack *node);
//small_sort.c
void		sort_three(t_info *stacks);

#endif
