/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur < gbodur@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:50:40 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/27 21:44:26 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = get_stack_bottom(*stack);
	temp->next = NULL;
	last->next = temp;
}

void	do_ra(t_stack **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	do_rb(t_stack **stack_b, int print)
{
	rotate(stack_b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
