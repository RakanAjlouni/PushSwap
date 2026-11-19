/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaamneh <lnaamneh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 13:24:54 by lnaamneh          #+#    #+#             */
/*   Updated: 2026/10/31 13:40:55 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

float	ft_compute_disorder(t_stack *stack)
{
	size_t	mistakes;
	size_t	total_pairs;
	t_node	*origin;
	t_node	*traverse;

	if (!stack || stack->size < 2)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	origin = stack->head;
	while (origin != stack->tail)
	{
		traverse = origin->next;
		while (traverse != stack->head)
		{
			total_pairs++;
			if (origin->value > traverse->value)
				mistakes++;
			traverse = traverse->next;
		}
		origin = origin->next;
	}
	return ((float)mistakes / (float)total_pairs);
}

int	ft_is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	if (!stack_a || (stack_b && stack_b->size > 0))
		return (0);
	if (stack_a->size < 2)
		return (1);
	current = stack_a->head;
	while (current != stack_a->tail)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_shortest_path(t_stack *stack_a, int target_index)
{
	int		regular_rotate;
	int		reverse_rotate;
	t_node	*traverse;

	if (!stack_a || stack_a->size < 2)
		return (0);
	regular_rotate = 0;
	reverse_rotate = 0;
	traverse = stack_a->head;
	while (traverse != stack_a->tail)
	{
		if (traverse->index == target_index)
			break ;
		traverse = traverse->next;
		regular_rotate++;
	}
	traverse = stack_a->head;
	while (traverse != stack_a->head->next)
	{
		if (traverse->index == target_index)
			break ;
		traverse = traverse->prev;
		reverse_rotate++;
	}
	return (2 * (regular_rotate <= reverse_rotate) - 1);
}
