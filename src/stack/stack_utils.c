/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaamneh <lnaamneh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:31:57 by lnaamneh          #+#    #+#             */
/*   Updated: 2026/10/31 18:56:06 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_node	*ft_stack_pop(t_stack *stack)
{
	t_node	*holder;

	if (!stack || !stack->head)
		return (NULL);
	if (stack->size == 1)
	{
		holder = stack->head;
		stack->head = NULL;
		stack->tail = NULL;
		stack->size = 0;
	}
	else
	{
		holder = stack->head;
		stack->tail->next = stack->head->next;
		stack->head->next->prev = stack->tail;
		stack->head = stack->head->next;
		stack->size--;
	}
	holder->prev = NULL;
	holder->next = NULL;
	return (holder);
}

void	ft_assign_indices(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		i;
	int		j;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	i = 0;
	while (i < stack->size)
	{
		current->index = 0;
		compare = stack->head;
		j = 0;
		while (j < stack->size)
		{
			if (compare->value < current->value)
				current->index++;
			compare = compare->next;
			j++;
		}
		current = current->next;
		i++;
	}
}

void	ft_stack_free(t_stack *stack)
{
	t_node	*traverse;

	if (!stack)
		return ;
	while (stack->size > 0)
	{
		traverse = stack->head;
		stack->head = stack->head->next;
		free(traverse);
		stack->size--;
	}
	free(stack);
	stack = NULL;
}

void	ft_program_free(t_program *program)
{
	if (!program)
		return ;
	if (program->benchmark)
		free(program->benchmark);
	free(program);
	program = NULL;
}
