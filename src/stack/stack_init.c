/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:44:31 by rajlouni          #+#    #+#             */
/*   Updated: 2026/10/31 18:56:23 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_init_program(t_program *program)
{
	if (!program)
		return ;
	program->flag = 4;
	program->bench = 0;
	program->benchmark = malloc(sizeof(t_bench));
	if (!program->benchmark)
		return ;
	*program->benchmark = (t_bench){0};
}

void	ft_init_stack(t_stack *stack)
{
	if (!stack)
		return ;
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

t_node	*ft_create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_stack_addback(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->prev = stack->tail;
		new_node->next = stack->head;
		stack->tail->next = new_node;
		stack->head->prev = new_node;
		stack->tail = new_node;
	}
	stack->size++;
}

void	ft_stack_addfront(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->prev = stack->tail;
		new_node->next = stack->head;
		stack->tail->next = new_node;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size++;
}
