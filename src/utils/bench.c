/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:20:29 by rajlouni          #+#    #+#             */
/*   Updated: 2026/10/31 13:51:18 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_print_topops(t_program *program)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(program->benchmark->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(program->benchmark->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(program->benchmark->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(program->benchmark->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(program->benchmark->pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	ft_print_botops(t_program *program)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(program->benchmark->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(program->benchmark->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(program->benchmark->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(program->benchmark->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(program->benchmark->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(program->benchmark->rrr, 2);
	ft_putchar_fd('\n', 2);
}

static void	ft_print_disorder(t_program *program)
{
	int	scaled;
	int	whole;
	int	decimal;

	scaled = (int)(program->benchmark->disorder * 10000);
	whole = scaled / 100;
	decimal = scaled % 100;
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putchar_fd('%', 2);
}

static void	ft_print_strategy(t_program *program)
{
	if (program->benchmark->total_ops == 0)
	{
		ft_putstr_fd(" None", 2);
		return ;
	}
	if (program->flag == 1)
		ft_putstr_fd(" Simple / O(n^2)", 2);
	else if (program->flag == 2)
		ft_putstr_fd(" Medium / O(n sqrt(n))", 2);
	else if (program->flag == 3)
		ft_putstr_fd(" Complex / O(n log n)", 2);
	else if (program->flag == 4)
	{
		if (program->benchmark->disorder < 0.2f)
			ft_putstr_fd(" Adaptive / O(n^2)", 2);
		else if (program->benchmark->disorder < 0.5f)
			ft_putstr_fd(" Adaptive / O(n sqrt(n))", 2);
		else
			ft_putstr_fd(" Adaptive / O(n log n)", 2);
	}
}

void	ft_print_bench(t_program *program)
{
	if (!program || !program->benchmark || !program->bench)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_print_disorder(program);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_print_strategy(program);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(program->benchmark->total_ops, 2);
	ft_putchar_fd('\n', 2);
	ft_print_topops(program);
	ft_print_botops(program);
}
