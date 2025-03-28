/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:13:49 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/28 13:31:35 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_split_elements(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static int	*create_nums_from_split(char **split, int split_count, int *count)
{
	int	*nums;
	int	j;

	nums = malloc(sizeof(int) * split_count);
	if (!nums)
	{
		ft_free_split(split);
		return (NULL);
	}
	j = 0;
	while (j < split_count)
	{
		if (!is_integer(split[j]) || !is_in_int_range(split[j]))
		{
			free(nums);
			ft_free_split(split);
			return (NULL);
		}
		nums[j] = ft_atoi(split[j]);
		j++;
	}
	*count += split_count;
	return (nums);
}

int	*parse_string(char *str, int *count)
{
	char	**split;
	int		*nums;
	int		split_count;

	split = ft_split(str, ' ');
	if (!split || !*split)
	{
		ft_free_split(split);
		return (NULL);
	}
	split_count = count_split_elements(split);
	nums = create_nums_from_split(split, split_count, count);
	if (nums)
		ft_free_split(split);
	return (nums);
}
