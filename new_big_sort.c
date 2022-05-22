/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:23:03 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/22 18:54:17 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*I guess now what I should do is try to optimize the ra and rra
pass to b the more ordenated possible*/

t_list	**chunks(void)
{
	static t_list	*chunk;

	return (&chunk);
}

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

void decide_moves(void)
{
	t_list *aux;
	int menor_moves;
	int	maior_indice;

	aux = *(chunks());
	while (aux)
	{
		aux = aux->next;
	}
}
