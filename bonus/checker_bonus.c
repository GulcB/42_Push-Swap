/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:53:34 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/28 11:09:25 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../gnl/get_next_line.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	execute_command(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		do_sa(stack_a, 0);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		do_sb(stack_b, 0);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		do_ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		do_pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		do_pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		do_ra(stack_a, 0);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		do_rb(stack_b, 0);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		do_rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		do_rra(stack_a, 0);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		do_rrb(stack_b, 0);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		do_rrr(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

static void	process_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		if (!execute_command(stack_a, stack_b, cmd))
		{
			free(cmd);
			free_stack(stack_a);
			free_stack(stack_b);
			error_exit();
		}
		free(cmd);
	}
}

static void	run_checker(t_stack *stack_a, t_stack *stack_b)
{
	process_commands(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*numbers;
	int		size;

	if (argc < 2)
		return (0);
	if (!is_valid_input(argc, argv))
		error_exit();
	numbers = parse_arguments(argc, argv, &size);
	if (is_duplicate(numbers, size))
	{
		free(numbers);
		error_exit();
	}
	stack_a = create_stack(numbers, size);
	stack_b = NULL;
	index_stack(&stack_a, numbers, size);
	free(numbers);
	run_checker(stack_a, stack_b);
	return (0);
}
