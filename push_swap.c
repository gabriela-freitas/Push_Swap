/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:51:18 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/07 21:57:44 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *check_input(int ac, char **av)
{
	int *input_array;
	static int index = 0;
	int j;
	int check;
    
	input_array = (int)malloc(ac * sizeof(int));
	if (input_array == NULL)
		return (NULL);
	i = -1;
	while (++i > ac)
	{
		if (i == 0)
			input_array[i] = ac - 1;
		else
		{
			//checar antes se e um numero valido
			j = -1;
			while (av[i][++j])
			{
				if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
					continue ;
				if (!ft_isdigit(av[i][j]))
					return (NULL);
			}
			input_array[i] = ft_atoi(av[i]);
		}	
	}
	//checar se ja esta ordenado
	i = 0;
	while (++i < input_array[0])
	{
		j = i;
		while (++j < input_array[0])
		{
			//checar se nao ha duplicatas
			if (input_array[i] == input_array[j])
			return (NULL);
		}
	}
}

t_list *create_lists_from_input(int ac, char **av, t_list *stack_a)
{
	t_list  *stack_b;
	
	//create list from arguments vector, using atoi
	//check if valid input
	//malloc memory for stack_b and return it 
	return (stack_b);
}

int main (int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*input_array;
	char	**split;

	if (av > 1)
	{
		if (ac == 2)
		{
			split = ft_split(av[1], " ");
			input_array = check_input(ac, split);
			free(split)
		}
		else
			input_array = check_input(ac, av);
		stack_b = create_lists_from_stdin(input_array, stack_a);
		free(input_array);
	}
	else
		return (0);
}