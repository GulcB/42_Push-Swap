/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:09:21 by gbodur            #+#    #+#             */
/*   Updated: 2025/03/28 14:04:26 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

void				get_cost(t_stack **stack_a, t_stack **stack_b);

void				do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

void				get_position(t_stack **stack);
void				get_target_position(t_stack **stack_a, t_stack **stack_b);

void				sort_three(t_stack **stack);
void				sort_small(t_stack **stack_a, t_stack **stack_b);
void				sort(t_stack **stack_a, t_stack **stack_b);

void				turkish_algorithm(t_stack **stack_a, t_stack **stack_b);

int					absolute(int num);
int					find_highest_index(t_stack *stack);
int					find_lowest_index(t_stack *stack);
void				set_min_on_top(t_stack **stack);

void				do_pa(t_stack **stack_a, t_stack **stack_b, int print);
void				do_pb(t_stack **stack_a, t_stack **stack_b, int print);

void				do_rra(t_stack **stack_a, int print);
void				do_rrb(t_stack **stack_b, int print);
void				do_rrr(t_stack **stack_a, t_stack **stack_b, int print);

void				do_ra(t_stack **stack_a, int print);
void				do_rb(t_stack **stack_b, int print);
void				do_rr(t_stack **stack_a, t_stack **stack_b, int print);

void				do_sa(t_stack **stack_a, int print);
void				do_sb(t_stack **stack_b, int print);
void				do_ss(t_stack **stack_a, t_stack **stack_b, int print);

void				free_stack(t_stack **stack);
t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_before_bottom(t_stack *stack);
int					get_stack_size(t_stack *stack);

void				index_stack(t_stack **stack, int *numbers, int size);

t_stack				*create_stack(int *numbers, int size);
int					is_sorted(t_stack *stack);

long				ft_atol(const char *str);
int					is_integer(char *arg);
int					is_in_int_range(char *arg);
int					is_valid_input(int argc, char **argv);
int					is_duplicate(int *array, int size);

int					*parse_arguments(int argc, char **argv, int *size);

void				ft_free_split(char **split);
int					*parse_string(char *str, int *count);

void				error_exit(void);

#endif
