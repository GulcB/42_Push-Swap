/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:38:22 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/28 11:06:31 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_elements_to_b(t_stack **stack_a, t_stack **stack_b,
	int stack_size, int *pushed)
{
	int	i;

	i = 0;
	while (stack_size > 3 && i < stack_size && *pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b, 1);
			(*pushed)++;
		}
		else
			do_ra(stack_a, 1);
		i++;
	}
}

static void	push_remaining_to_b(t_stack **stack_a, t_stack **stack_b,
	int stack_size, int *pushed)
{
	while (stack_size - *pushed > 3)
	{
		do_pb(stack_a, stack_b, 1);
		(*pushed)++;
	}
}

static void	sort_from_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	get_position(stack_a);
	set_min_on_top(stack_a);
}

void	turkish_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	push_elements_to_b(stack_a, stack_b, stack_size, &pushed);
	push_remaining_to_b(stack_a, stack_b, stack_size, &pushed);
	sort_three(stack_a);
	sort_from_b_to_a(stack_a, stack_b);
}
