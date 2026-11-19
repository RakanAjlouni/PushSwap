/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:07:35 by rajlouni          #+#    #+#             */
/*   Updated: 2026/11/01 12:53:14 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_error_exit(t_program *program, t_stack *stack_a, char **args)
{
	ft_free_split(args);
	ft_stack_free(stack_a);
	ft_program_free(program);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
