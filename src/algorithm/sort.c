/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur < gbodur@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:52:17 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/27 21:42:54 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack, 1);
	else if ((*stack)->next->index == highest)
		do_rra(stack, 1);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack, 1);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			do_sa(stack_a, 1);
		return ;
	}
	else if (size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	while (size > 3)
	{
		get_position(stack_a);
		set_min_on_top(stack_a);
		do_pb(stack_a, stack_b, 1);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		do_pa(stack_a, stack_b, 1);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	size = get_stack_size(*stack_a);
	if (size <= 5)
		sort_small(stack_a, stack_b);
	else
		turkish_algorithm(stack_a, stack_b);
}
