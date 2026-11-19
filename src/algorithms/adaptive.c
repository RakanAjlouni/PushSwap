/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:47:42 by rajlouni          #+#    #+#             */
/*   Updated: 2026/11/01 13:19:21 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_adaptive_sort(t_program *program, t_stack *stack_a, t_stack *stack_b)
{
	float	current_disorder;

	if (!program || !stack_a || !stack_b
		|| (ft_is_sorted(stack_a, stack_b) == 1))
		return ;
	current_disorder = ft_compute_disorder(stack_a);
	if (program->bench && program->benchmark)
		program->benchmark->disorder = current_disorder;
	if (stack_a->size <= 5)
		ft_selection_sort(program, stack_a, stack_b);
	else if (current_disorder < 0.20)
		ft_selection_sort(program, stack_a, stack_b);
	else if (current_disorder < 0.50)
		ft_chunk_sort(program, stack_a, stack_b);
	else
		ft_radix_sort(program, stack_a, stack_b);
}
