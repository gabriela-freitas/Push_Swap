/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:51:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/23 21:54:31 by gafreita         ###   ########.fr       */
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
	int				aux;
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

typedef struct s_chunk
{
	int	index;
	int	n_moves;
	int	type_move;
}	t_chunk;

enum e_moves
{
	RA = 2,
	RB,
	RRA,
	RRB
};

//big_sort.c
void		big_sort(void);
//small_sort.c
void		small_sort(void);
//new_lists.c
t_stack		*t_stack_last(t_stack *lst);
t_stack		*t_stack_new(int value);
int			t_stack_size(t_stack *lst);
void		t_stack_add_back(t_stack *lst, t_stack *new);
void		t_stack_add_front(t_stack **lst, t_stack *new);

// utils_lists.c
t_info		*stacks(void);
int			*selection_sort_array(int *array, int size);
int			check_duplicates(t_stack *lst);
void		free_stack(t_stack *head);
void		free_split(char **split);

//push.c
int			pa(void);
int			pb(void);
//swap.c
void		swap(t_stack **head, t_stack **next);
int			sb(void);
int			ss(void);
int			sa(void);
//rotate.c
void		rotate(t_stack **head);
int			ra(void);
int			rb(void);
int			rr(void);
//reverse_rotate.c
void		reverse_rotate(t_stack **head);
int			rra(void);
int			rrb(void);
int			rrr(void);

//print_stuff.c
void		print_infos(void);
void		print_stack(t_stack *stack);

//utils_sort.c
int			check_last_move(void);
int			check_sorted_asc(t_stack *stack);
int			*stack_to_array(t_stack *head);
void		ra_or_rra(int begin, int end);

#endif
