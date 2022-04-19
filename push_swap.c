/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:51:18 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/19 23:22:30 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(t_info *stacks, char **av)
{
	int		i;
	int		j;

	i = -1;
	stacks->head_a.next = NULL;
	while (av[i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				continue ;
			if (!ft_isdigit(av[i][j]))
				return (0);
		}
		t_stack_add_back(&(stacks->head_a), t_stack_new(ft_atoi(av[i])));
	}
	if (check_sorted_ascending(&(stacks->head_a)) == -1)
		return (0);
	stacks->size_a = t_stack_size(&(stacks->head_a));
	return (1);
}

//deals with ./push_swap "0 1 2" or ./push_swap 0 1 2
int	main(int ac, char **av)
{
	t_info	stacks;
	char	**split;

	if (ac > 1)
	{
		if (ac == 2)
		{
			split = ft_split(av[1], ' ');
			if (!check_input(&stacks, split))
			{
				ft_printf("Error");
				return (0);
			}
			free(split);
		}
		else if (!check_input(&stacks, av))
		{
			ft_printf("Error");
			return (0);
		}
	}
	else
		return (0);
}
