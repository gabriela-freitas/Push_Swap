/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:23:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/23 18:40:55 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*I guess now what I should do is try to optimize the ra and rra
pass to b the more ordenated possible*/
static void	move(t_chunk *chunk);
static void	free_chunks(t_list **node);
void		decide_moves(void);
void		calculate_moves(int begin, int end);
t_list		**chunks(void);

/*return the struct containing the chunks*/
t_list	**chunks(void)
{
	static t_list	*chunk;

	return (&chunk);
}

/*frees the memory needed*/
static void	free_chunks(t_list **node)
{
	t_list	*aux;

	while (*node)
	{
		aux = (*node)->next;
		free((*node)->content);
		free(*node);
		*node = aux;
	}
}

/*calculates how many moves every item if the chunk takes*/
void	calculate_moves(int begin, int end)
{
	t_chunk	*chunk;
	t_stack	*aux;
	int		i;

	i = 0;
	aux = stacks()->head_a;
	while (aux)
	{
		if (aux->index >= begin && aux->index < end)
		{
			chunk = malloc(sizeof(t_chunk));
			chunk->index = aux->index;
			if (i < stacks()->all)
			{
				chunk->type_move = RA;
				chunk->n_moves = i;
			}
			else
			{
				chunk->type_move = RRA;
				chunk->n_moves = stacks()->all - i;
			}
			ft_lstadd_back(chunks(), ft_lstnew((void *)chunk));
		}
		aux = aux->next;
		i ++;
	}
}

/*decide wich number move*/
void	decide_moves(void)
{
	t_list	*aux;
	t_chunk	*less_moves;
	t_chunk	*bigger_number;
	t_chunk	*chunk;

	aux = *(chunks());
	bigger_number = 0;
	less_moves = aux->content;
	bigger_number = aux->content;
	while (aux)
	{
		chunk = aux->content;
		if (chunk->n_moves < less_moves->n_moves)
			less_moves = chunk;
		if (chunk->index > bigger_number->index)
			bigger_number = chunk;
		aux = aux->next;
	}
	// if (bigger_number->n_moves - less_moves->n_moves < 3)
	// 	move(bigger_number);
	// else
		move(less_moves);
	free_chunks(chunks());
}

/*move the number*/
static void	move(t_chunk *chunk)
{
	if (chunk->type_move == RA)
	{
		while (chunk->n_moves--)
			ra();
	}
	if (chunk->type_move == RRA)
	{
		while (chunk->n_moves--)
			rra();
	}
}
