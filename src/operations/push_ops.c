/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:00:56 by rajlouni          #+#    #+#             */
/*   Updated: 2026/10/31 14:17:28 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	pa(t_program *program, t_stack *a, t_stack *b)
{
	if (!b || b->size == 0)
		return ;
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
	if (program->benchmark)
	{
		program->benchmark->pa++;
		program->benchmark->total_ops++;
	}
}

void	pb(t_program *program, t_stack *a, t_stack *b)
{
	if (!a || a->size == 0)
		return ;
	ft_push(a, b);
	ft_putstr_fd("pb\n", 1);
	if (program->benchmark)
	{
		program->benchmark->pb++;
		program->benchmark->total_ops++;
	}
}
