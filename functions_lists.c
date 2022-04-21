/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:25:25 by gafreita          #+#    #+#             */
/*   Updated: 2022/04/21 18:27:49 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO: function to free a stack's memory

//Returns the last node of the list.
t_stack	*t_stack_last(t_stack *lst)
{
	t_stack	*aux;

	aux = lst;
	if (!aux)
		return (NULL);
	while (aux->next && aux)
		aux = aux->next;
	return (aux);
}

//Allocates (with malloc(3)) and returns a new node.
//The member variable ’content’ is initialized
//with the value of the parameter ’content’.
//The variable’next’ is initialized to NULL.
t_stack	*t_stack_new(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

//return the size of the list
int	t_stack_size(t_stack *lst)
{
	int			size;
	t_stack		*add;

	size = 0;
	add = lst;
	while (add != NULL)
	{
		add = add->next;
		size ++;
	}
	return (size);
}

//Adds the node ’new’ at the end of the list.
void	t_stack_add_back(t_stack *lst, t_stack *new)
{
	if (!lst)
	{
		//ft_printf("list == NULL\n");
		// lst->value = new->value;
		// lst->next = NULL;
		lst = new;
		//free(new);
	}
	else
	{
		//ft_printf("lst not NULL\n");
		t_stack_last(lst)->next = new;
	}
}

//Adds the node ’new’ at the beginning of the list
void	t_stack_add_front(t_stack *lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = lst;
	lst = new;
}
