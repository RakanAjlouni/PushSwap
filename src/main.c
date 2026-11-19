/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:13:41 by rajlouni          #+#    #+#             */
/*   Updated: 2026/11/01 14:24:47 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

static void	ft_sort_router(t_program *program,
			t_stack *stack_a, t_stack *stack_b)
{
	if (program->flag == 1)
		ft_selection_sort(program, stack_a, stack_b);
	else if (program->flag == 2)
		ft_chunk_sort(program, stack_a, stack_b);
	else if (program->flag == 3)
		ft_radix_sort(program, stack_a, stack_b);
	else if (program->flag == 4)
		ft_adaptive_sort(program, stack_a, stack_b);
}

static void	main_helper(t_program *program, t_stack *stack_a, t_stack *stack_b)
{
	if (program->bench)
		ft_print_bench(program);
	ft_stack_free(stack_a);
	ft_stack_free(stack_b);
	ft_program_free(program);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_program	*program;

	if (argc < 2)
		return (0);
	program = malloc(sizeof(t_program));
	if (!program)
		return (1);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (ft_program_free(program), 1);
	ft_init_program(program);
	ft_init_stack(stack_a);
	ft_parser(program, stack_a, argc, argv);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (ft_program_free(program), ft_stack_free(stack_a), 1);
	ft_init_stack(stack_b);
	if (program->bench && program->benchmark)
		program->benchmark->disorder = ft_compute_disorder(stack_a);
	ft_sort_router(program, stack_a, stack_b);
	main_helper(program, stack_a, stack_b);
	return (0);
}
