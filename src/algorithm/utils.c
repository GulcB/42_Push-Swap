/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur < gbodur@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:00:05 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/27 21:43:35 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	absolute(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	find_highest_index(t_stack *stack)
{
	int	highest;

	if (!stack)
		return (0);
	highest = stack->index;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

int	find_lowest_index(t_stack *stack)
{
	int		lowest;
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = stack;
	lowest = temp->index;
	while (temp)
	{
		if (temp->index < lowest)
			lowest = temp->index;
		temp = temp->next;
	}
	return (lowest);
}

void	set_min_on_top(t_stack **stack)
{
	int	lowest;
	int	stack_size;
	int	position;

	if (!*stack || !(*stack)->next)
		return ;
	stack_size = get_stack_size(*stack);
	lowest = find_lowest_index(*stack);
	get_position(stack);
	position = 0;
	while ((*stack)->index != lowest)
	{
		position++;
		if (position > stack_size / 2)
			do_rra(stack, 1);
		else
			do_ra(stack, 1);
	}
}
