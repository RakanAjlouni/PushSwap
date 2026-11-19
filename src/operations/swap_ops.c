/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:15:40 by rajlouni          #+#    #+#             */
/*   Updated: 2026/10/31 17:24:18 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa(t_program *program, t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
	if (program->benchmark)
	{
		program->benchmark->sa++;
		program->benchmark->total_ops++;
	}
}

void	sb(t_program *program, t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
	if (program->benchmark)
	{
		program->benchmark->sb++;
		program->benchmark->total_ops++;
	}
}

void	ss(t_program *program, t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
	if (program->benchmark)
	{
		program->benchmark->ss++;
		program->benchmark->total_ops++;
	}
}
