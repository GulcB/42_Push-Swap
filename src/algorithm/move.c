/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:28:18 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/28 11:05:31 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	do_same_rotation(t_stack **stack_a, t_stack **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		do_rr(stack_a, stack_b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		do_rrr(stack_a, stack_b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	do_rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a != 0)
	{
		if (*cost_a > 0)
		{
			do_ra(stack_a, 1);
			(*cost_a)--;
		}
		else
		{
			do_rra(stack_a, 1);
			(*cost_a)++;
		}
	}
}

static void	do_rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b != 0)
	{
		if (*cost_b > 0)
		{
			do_rb(stack_b, 1);
			(*cost_b)--;
		}
		else
		{
			do_rrb(stack_b, 1);
			(*cost_b)++;
		}
	}
}

static void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a,
	int cost_b)
{
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	do_pa(stack_a, stack_b, 1);
	do_same_rotation(stack_a, stack_b, &cost_a, &cost_b);
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;
	int		cost;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		cost = absolute(temp->cost_a) + absolute(temp->cost_b);
		if (cost < cheapest)
		{
			cheapest = cost;
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
