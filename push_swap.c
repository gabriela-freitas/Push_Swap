/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:51:18 by gafreita          #+#    #+#             */
/*   Updated: 2022/05/22 13:13:35 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_input(char **av);
static int	deal_input(char **av);
static void	index_stack(t_stack *head);
static void	choose_chunk_size(void);

int	main(int ac, char **av)
{
	stacks()->head_a = NULL;
	stacks()->head_b = NULL;
	if (ac > 1)
	{
		if (!deal_input(av) || check_sorted_asc(stacks()->head_a))
			return (0);
	}
	else
		return (0);
	choose_chunk_size();
	if (stacks()->all <= 5)
		small_sort();
	else
		big_sort();
	free_stack(stacks()->head_a);
	free_stack(stacks()->head_b);
}

static void	choose_chunk_size(void)
{
	if (stacks()->all <= 5)
		stacks()->chunk_size = stacks()->all;
	else if (stacks()->all <= 50)
		stacks()->chunk_size = stacks()->all / 2;
	else if (stacks()->all <= 100)
		stacks()->chunk_size = stacks()->all / 5;
	else
		stacks()->chunk_size = stacks()->all / 15;
}

static int	deal_input(char **av)
{
	char	**split;
	int		i;

	stacks()->head_a = NULL;
	i = 0;
	while (av[++i])
	{
		split = ft_split(av[i], ' ');
		if (!check_input(split))
		{
			free_stack(stacks()->head_a);
			ft_printf("Error");
			free_split(split);
			return (0);
		}
		free_split(split);
	}
	stacks()->size_a = t_stack_size(stacks()->head_a);
	stacks()->all = stacks()->size_a;
	index_stack(stacks()->head_a);
	return (1);
}

static int	check_input(char **av)
{
	int		i;
	int		j;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				continue ;
			if (!ft_isdigit(av[i][j]))
				return (0);
		}
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (0);
		if (i == 0 && !(stacks()->head_a))
			stacks()->head_a = t_stack_new(ft_atoi(av[i]));
		else
			t_stack_add_back(stacks()->head_a, t_stack_new(ft_atoi(av[i])));
	}
	if (!check_duplicates(stacks()->head_a))
		return (0);
	return (1);
}

static void	index_stack(t_stack *head)
{
	int		*arr;
	int		i;
	t_stack	*aux;
	int		size;

	size = t_stack_size(head);
	arr = selection_sort_array(stack_to_array(head), size);
	aux = head;
	while (aux)
	{
		i = -1;
		while (++i < size)
		{
			if (arr[i] == aux->value)
				aux->index = i;
		}
		aux = aux->next;
	}
	free(arr);
}
