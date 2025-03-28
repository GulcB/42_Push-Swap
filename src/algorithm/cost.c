/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur < gbodur@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:01:25 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/27 21:42:13 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = get_stack_size(temp_a);
	size_b = get_stack_size(temp_b);
	while (temp_b)
	{
		if (temp_b->position <= size_b / 2)
			temp_b->cost_b = temp_b->position;
		else
			temp_b->cost_b = -(size_b - temp_b->position);
		if (temp_b->target_pos <= size_a / 2)
			temp_b->cost_a = temp_b->target_pos;
		else
			temp_b->cost_a = -(size_a - temp_b->target_pos);
		temp_b = temp_b->next;
	}
}
