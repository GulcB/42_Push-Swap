/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur < gbodur@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:51:46 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/27 21:49:49 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*create_new_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->position = -1;
	new_node->target_pos = -1;
	new_node->cost_a = -1;
	new_node->cost_b = -1;
	new_node->next = NULL;
	return (new_node);
}

static void	add_node_to_stack(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!*stack)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

t_stack	*create_stack(int *numbers, int size)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		new_node = create_new_node(numbers[i]);
		if (!new_node)
		{
			free_stack(&stack);
			error_exit();
		}
		add_node_to_stack(&stack, new_node);
		i++;
	}
	return (stack);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}
