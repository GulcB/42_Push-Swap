/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur < gbodur@student.42istanbul.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:51:59 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/27 21:46:12 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*copy_array(int *numbers, int size)
{
	int	*sorted;
	int	i;

	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = numbers[i];
		i++;
	}
	return (sorted);
}

static void	assign_indices(t_stack **stack, int *sorted, int size)
{
	t_stack	*current;
	int		i;

	current = *stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted[i])
				current->index = i;
			i++;
		}
		current = current->next;
	}
}

void	index_stack(t_stack **stack, int *numbers, int size)
{
	int	*sorted;

	sorted = copy_array(numbers, size);
	if (!sorted)
	{
		free_stack(stack);
		error_exit();
	}
	sort_array(sorted, size);
	assign_indices(stack, sorted, size);
	free(sorted);
}
