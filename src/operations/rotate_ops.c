/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:28:55 by rajlouni          #+#    #+#             */
/*   Updated: 2026/10/31 17:22:22 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra(t_program *program, t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_rotate(a);
	ft_putstr_fd("ra\n", 1);
	if (program->benchmark)
	{
		program->benchmark->ra++;
		program->benchmark->total_ops++;
	}
}

void	rb(t_program *program, t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_rotate(b);
	ft_putstr_fd("rb\n", 1);
	if (program->benchmark)
	{
		program->benchmark->rb++;
		program->benchmark->total_ops++;
	}
}

void	rr(t_program *program, t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr_fd("rr\n", 1);
	if (program->benchmark)
	{
		program->benchmark->rr++;
		program->benchmark->total_ops++;
	}
}
