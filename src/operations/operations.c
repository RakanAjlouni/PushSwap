/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaamneh <lnaamneh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 11:23:54 by lnaamneh          #+#    #+#             */
/*   Updated: 2026/10/25 13:37:37 by rajlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_push(t_stack *giver, t_stack *taker)
{
	if (!giver || !taker)
		return ;
	ft_stack_addfront(taker, ft_stack_pop(giver));
}

void	ft_swap(t_stack *swapper)
{
	t_node	*intermediate_1;
	t_node	*intermediate_2;

	if (!swapper || swapper->size < 2)
		return ;
	intermediate_1 = ft_stack_pop(swapper);
	intermediate_2 = ft_stack_pop(swapper);
	ft_stack_addfront(swapper, intermediate_1);
	ft_stack_addfront(swapper, intermediate_2);
}

void	ft_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	ft_reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}
