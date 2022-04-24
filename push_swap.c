/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:51:18 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/24 19:05:17 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_input(t_info *stacks, char **av);
static int	deal_input(int ac, char **av, t_info *stacks);
static void	index_stack(t_info *stacks);

int	main(int ac, char **av)
{
	t_info	stacks;

	if (ac > 1)
	{
		if (!deal_input(ac, av, &stacks) || check_sorted_asc(stacks.head_a))
			return (0);
	}
	else
		return (0);
	//test moves
	pb(&stacks);
	pb(&stacks);
	pb(&stacks);
	rrr(&stacks);
	//ss(&stacks);
	//pa(&stacks);
	print_infos(&stacks);
	free_stack(stacks.head_a);
	free_stack(stacks.head_b);
}

//deals with ./push_swap "0 1 2" or ./push_swap 0 1 2
static int	deal_input(int ac, char **av, t_info *stacks)
{
	char	**split;

	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!check_input(stacks, split))
		{
			free_stack(stacks->head_a);
			ft_printf("Error");
			free(split);
			return (0);
		}
		free(split);
	}
	else if (!check_input(stacks, av))
	{
		free_stack(stacks->head_a);
		ft_printf("Error");
		return (0);
	}
	index_stack(stacks);
	print_infos(stacks);
	return (1);
}

static int	check_input(t_info *stacks, char **av)
{
	int		i;
	int		j;

	i = 0;
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
		if (i == 1)
			stacks->head_a = t_stack_new(ft_atoi(av[i]));
		else
			t_stack_add_back(stacks->head_a, t_stack_new(ft_atoi(av[i])));
	}
	if (!check_duplicates(stacks->head_a))
		return (0);
	stacks->size_a = t_stack_size(stacks->head_a);
	return (1);
}

static void	index_stack(t_info *stacks)
{
	int		*arr;
	int		i;
	t_stack	*aux;

	arr = malloc(sizeof(int) * stacks->size_a);
	aux = stacks->head_a;
	i = -1;
	while (aux && ++i < stacks->size_a)
	{
		arr[i] = aux->value;
		aux = aux->next;
	}
	selection_sort_array(arr, stacks->size_a);
	aux = stacks->head_a;
	while (aux)
	{
		i = -1;
		while (++i < stacks->size_a)
		{
			if (arr[i] == aux->value)
				aux->index = i;
		}
		aux = aux->next;
	}
	free(arr);
}
