/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:49:56 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/28 12:33:25 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	process_stack(int *numbers, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = create_stack(numbers, size);
	index_stack(&stack_a, numbers, size);
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(numbers);
}

int	main(int argc, char **argv)
{
	int	*numbers;
	int	size;

	if (argc < 2)
		return (0);
	numbers = parse_arguments(argc, argv, &size);
	if (size == 0 || is_duplicate(numbers, size))
	{
		free(numbers);
		error_exit();
	}
	process_stack(numbers, size);
	return (0);
}
