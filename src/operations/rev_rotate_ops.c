/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:36:26 by rajlouni          #+#    #+#             */
/*   Updated: 2026/10/31 17:22:32 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra(t_program *program, t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
	if (program->benchmark)
	{
		program->benchmark->rra++;
		program->benchmark->total_ops++;
	}
}

void	rrb(t_program *program, t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
	if (program->benchmark)
	{
		program->benchmark->rrb++;
		program->benchmark->total_ops++;
	}
}

void	rrr(t_program *program, t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
	if (program->benchmark)
	{
		program->benchmark->rrr++;
		program->benchmark->total_ops++;
	}
}
