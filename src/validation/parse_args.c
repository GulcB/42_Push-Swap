/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:56:51 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/28 13:08:40 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	copy_first_array(int *result, int *old_array, int old_count)
{
	int	i;

	i = 0;
	while (i < old_count)
	{
		result[i] = old_array[i];
		i++;
	}
}

static void	copy_second_array(int *result, int *new_array,
	int old_count, int new_elements)
{
	int	i;

	i = 0;
	while (i < new_elements)
	{
		result[old_count + i] = new_array[i];
		i++;
	}
}

static int	*extend_array(int *old_array, int old_count, int *new_array,
	int new_elements)
{
	int	*result;

	result = malloc(sizeof(int) * (old_count + new_elements));
	if (!result)
	{
		if (old_array)
			free(old_array);
		free(new_array);
		return (NULL);
	}
	copy_first_array(result, old_array, old_count);
	copy_second_array(result, new_array, old_count, new_elements);
	if (old_array)
		free(old_array);
	free(new_array);
	return (result);
}

static int	*process_arg(int *numbers, char *arg, int *count, int *old_count)
{
	int	*temp;
	int	new_elements;

	*old_count = *count;
	temp = parse_string(arg, count);
	if (!temp)
	{
		if (numbers)
			free (numbers);
		return (NULL);
	}	
	new_elements = *count - *old_count;
	if (numbers)
	{
		numbers = extend_array(numbers, *old_count, temp, new_elements);
		if (!numbers)
			return (NULL);
	}
	else
		numbers = temp;
	return (numbers);
}

int	*parse_arguments(int argc, char **argv, int *size)
{
	int	*numbers;
	int	i;
	int	count;
	int	old_count;

	count = 0;
	numbers = NULL;
	i = 1;
	while (i < argc)
	{
		numbers = process_arg(numbers, argv[i], &count, &old_count);
		if (!numbers)
			error_exit();
		i++;
	}
	*size = count;
	return (numbers);
}
