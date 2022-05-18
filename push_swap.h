/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:51:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/18 20:05:49 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
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
	int		all;
	int		chunk_size;
}	t_info;

//new_lists.c
t_stack		*t_stack_last(t_stack *lst);
t_stack		*t_stack_new(int value);
int			t_stack_size(t_stack *lst);
void		t_stack_add_back(t_stack *lst, t_stack *new);
void		t_stack_add_front(t_stack **lst, t_stack *new);
// utils_lists.c
	//int			check_sorted_descending(t_stack *lst);
void		selection_sort_array(int *array, int size);
int			check_duplicates(t_stack *lst);
//FIXME: simplify those functions and check for leaks on valgrind
void		free_stack(t_stack *head);
void		free_info(t_info *info);
void		free_split(char **split);
//push.c
int			pa(t_info *stacks);
int			pb(t_info *stacks);
//swap.c
int			sb(t_info *stacks);
int			ss(t_info *stacks);
int			sa(t_info *stacks);
//rotate.c
void		rotate(t_stack **head);
int			ra(t_info *stacks);
int			rb(t_info *stacks);
int			rr(t_info *stacks);
//reverse_rotate.c
void		reverse_rotate(t_stack **head);
int			rra(t_info *stacks);
int			rrb(t_info *stacks);
int			rrr(t_info *stacks);
//small_sort.c
void		small_sort(t_info *stacks);
void		sort_three(t_info *stacks, t_stack **head);
int			pb_or_rra_or_ra(t_info *stacks, int size);
//print_stuff.c
void		print_infos(t_info *info);
void		print_stack(t_stack *stack);
//utils_sort.c
int			check_last_move(t_info *stacks);
int			check_sorted_asc(t_stack *stack);
void		ra_or_rra(t_info *stacks, t_stack *head, int index);
//big_sort.c
void		big_sort(t_info *stacks);
#endif
