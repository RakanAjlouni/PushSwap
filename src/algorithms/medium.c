/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaamneh <lnaamneh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 22:56:03 by lnaamneh          #+#    #+#             */
/*   Updated: 2026/11/01 15:03:39 by rajlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	ft_chunk_sqrt(int n)
{
	int	x;
	int	x_n;

	if (n < 0)
		return (0);
	if (n < 2)
		return (n);
	x = n / 2;
	x_n = (x + n / x) / 2;
	while (x_n < x)
	{
		x = x_n;
		x_n = (x + n / x) / 2;
	}
	return (x);
}

static void	ft_collect_chunk(t_program *program,
				t_stack *stack_a, t_stack *stack_b, int upper)
{
	int	remaining;

	remaining = stack_a->size;
	while (remaining > 0)
	{
		if (stack_a->head->index < upper)
			pb(program, stack_a, stack_b);
		else
			ra(program, stack_a);
		remaining--;
	}
}

static int	ft_chunk_distance(t_stack *stack_b, int target)
{
	t_node	*forward;
	t_node	*backward;
	int		distance;

	forward = stack_b->head;
	backward = stack_b->head;
	distance = 0;
	while (distance <= stack_b->size / 2)
	{
		if (forward->index == target)
			return (distance);
		if (backward->index == target)
			return (-distance);
		forward = forward->next;
		backward = backward->prev;
		distance++;
	}
	return (0);
}

static void	ft_return_chunks(t_program *program,
				t_stack *stack_a, t_stack *stack_b, int target)
{
	int	distance;

	while (stack_b->size > 0)
	{
		distance = ft_chunk_distance(stack_b, target);
		while (distance > 0)
		{
			rb(program, stack_b);
			distance--;
		}
		while (distance < 0)
		{
			rrb(program, stack_b);
			distance++;
		}
		pa(program, stack_a, stack_b);
		target--;
	}
}

void	ft_chunk_sort(t_program *program, t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	width;
	int	upper;

	if (!program || !stack_a || !stack_b || ft_is_sorted(stack_a, stack_b))
		return ;
	if (ft_is_sorted(stack_a, stack_b))
		return ;
	size = stack_a->size;
	width = ft_chunk_sqrt(size);
	upper = width;
	while (stack_a->size > 0)
	{
		ft_collect_chunk(program, stack_a, stack_b, upper);
		if (size - upper < width)
			upper = size;
		else
			upper += width;
	}
	ft_return_chunks(program, stack_a, stack_b, size - 1);
}
