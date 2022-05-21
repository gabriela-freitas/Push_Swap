/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:57:58 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/21 23:16:19 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*returns the struct info that will be used throughout the program*/
t_info	*stacks(void)
{
	static t_info	stacks;

	return (&stacks);
}

//function to free a stack's memory
void	free_stack(t_stack *head)
{
	t_stack	*aux;

	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

//FIXME:add to libft
/*free the memory allocated for ft_split*/
void	free_split(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
		free(split[i]);
}

/*ordenates the array using the selection sort algorithm and returns
the sorted array*/
int	*selection_sort_array(int *array, int size)
{
	int	aux;
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
	}
	return (array);
}

//function to check for duplicates
int	check_duplicates(t_stack *lst)
{
	t_stack	*aux;
	t_stack	*temp;

	temp = lst;
	while (temp)
	{
		aux = temp->next;
		while (aux)
		{
			if (aux->value == temp->value)
				return (0);
			aux = aux->next;
		}
		temp = temp->next;
	}
	return (1);
}
