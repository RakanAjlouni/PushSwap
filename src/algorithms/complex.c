/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:29:26 by rajlouni          #+#    #+#             */
/*   Updated: 2026/11/01 14:58:08 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	ft_max_bits(t_stack *stack)
{
	int	max_index;
	int	max_bits;

	max_index = stack->size - 1;
	max_bits = 0;
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		max_bits++;
	}
	return (max_bits);
}

void	ft_radix_sort(t_program *program, t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	if (!program || !stack_a || !stack_b || ft_is_sorted(stack_a, stack_b))
		return ;
	max_bits = ft_max_bits(stack_a);
	size = stack_a->size;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (size > j)
		{
			if (((stack_a->head->index >> i) & 1) == 1)
				ra(program, stack_a);
			else
				pb(program, stack_a, stack_b);
			j++;
		}
		while (stack_b->size > 0)
			pa(program, stack_a, stack_b);
		i++;
	}
}
