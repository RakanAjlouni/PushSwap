/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaamneh <lnaamneh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:56:15 by lnaamneh          #+#    #+#             */
/*   Updated: 2026/11/01 12:55:34 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_process_args(t_program *program, t_stack *stack_a, char **args)
{
	int		i;
	int		id;

	i = 0;
	while (args[i])
	{
		id = ft_check_flag(args[i]);
		if (id == 5)
		{
			program->bench = 1;
			i++;
			continue ;
		}
		else if (id > 0 && id < 5)
		{
			program->flag = id;
			i++;
			continue ;
		}
		ft_add_number(program, stack_a, args[i], args);
		i++;
	}
}

void	ft_parser(t_program *program, t_stack *stack_a, int argc, char **argv)
{
	int		i;
	char	**args;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args || !args[0])
			ft_error_exit(program, stack_a, args);
		ft_process_args(program, stack_a, args);
		ft_free_split(args);
		i++;
	}
	ft_assign_indices(stack_a);
}
