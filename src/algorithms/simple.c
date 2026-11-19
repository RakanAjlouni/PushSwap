/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaamneh <lnaamneh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:49:40 by lnaamneh          #+#    #+#             */
/*   Updated: 2026/11/01 15:03:31 by rajlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static t_node	*ft_find_min(t_stack *stack)
{
	t_node	*min;
	t_node	*traverse;

	min = stack->head;
	traverse = stack->head->next;
	while (traverse != stack->head)
	{
		if (traverse->value < min->value)
		{
			min = traverse;
		}
		traverse = traverse->next;
	}
	return (min);
}

void	ft_selection_sort(t_program *program,
				t_stack *stack_a, t_stack *stack_b)
{
	int		path;
	t_node	*min;

	if (!program || !stack_a || !stack_b || ft_is_sorted(stack_a, stack_b))
		return ;
	while (stack_a->size > 1)
	{
		min = ft_find_min(stack_a);
		path = ft_shortest_path(stack_a, min->index);
		while (stack_a->head != min)
		{
			if (path == 1)
				ra(program, stack_a);
			else
				rra(program, stack_a);
		}
		if (ft_is_sorted(stack_a, stack_b))
			return ;
		pb(program, stack_a, stack_b);
	}
	while (stack_b->size)
		pa(program, stack_a, stack_b);
}
