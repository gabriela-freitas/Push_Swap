/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:51:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/18 23:12:58 by gafreita         ###   ########.fr       */
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
	t_stack	*head_b;
	int		size_a;
	int		size_b;
	int		all;
	int		chunk_size;
}	t_info;

t_info		*stacks(void);
//new_lists.c
t_stack		*t_stack_last(t_stack *lst);
t_stack		*t_stack_new(int value);
int			t_stack_size(t_stack *lst);
void		t_stack_add_back(t_stack *lst, t_stack *new);
void		t_stack_add_front(t_stack **lst, t_stack *new);
// utils_lists.c
int			*selection_sort_array(int *array, int size);
int			check_duplicates(t_stack *lst);
void		free_stack(t_stack *head);
void		free_stacks(void);
void		free_split(char **split);
//push.c
int			pa(void);
int			pb(void);
int			px(char id);
//swap.c
int			sb(void);
int			ss(void);
int			sa(void);
int			sx(char id);
//rotate.c
void		rotate(t_stack **head);
int			ra(void);
int			rb(void);
int			rr(void);
int			rx(char id);
//reverse_rotate.c
void		reverse_rotate(t_stack **head);
int			rra(void);
int			rrb(void);
int			rrr(void);
int			rrx(char id);
//small_sort.c
void		sort_three(t_stack **head);
void		small_sort(t_stack **head);
//print_stuff.c
void		print_infos(void);
void		print_stack(t_stack *stack);

//utils_sort.c
int			check_last_move(t_stack *head);
int			check_sorted_asc(t_stack *stack);
void		rx_or_rrx_range(t_stack *head, int begin, int end);
int			*stack_to_array(t_stack *head);
char		head_a_or_b(t_stack *head);

//big_sort.c
void		big_sort(t_info *stacks);
#endif
