/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:01:06 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/28 11:11:44 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	if (!*stack)
		return ;
	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

static int	get_target(t_stack **stack_a, int b_idx, int target_idx,
	int target_pos)
{
	t_stack	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index > b_idx && temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	int		target_pos;

	get_position(stack_a);
	get_position(stack_b);
	temp_b = *stack_b;
	target_pos = 0;
	while (temp_b)
	{
		temp_b->target_pos = get_target(stack_a, temp_b->index, INT_MAX,
				target_pos);
		temp_b = temp_b->next;
	}
}
