/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur < gbodur@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:50:55 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/27 21:44:03 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_stack_bottom(*stack);
	before_last = get_stack_before_bottom(*stack);
	last->next = *stack;
	*stack = last;
	before_last->next = NULL;
}

void	do_rra(t_stack **stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_stack **stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
