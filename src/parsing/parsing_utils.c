/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:59:57 by rajlouni          #+#    #+#             */
/*   Updated: 2026/10/31 18:59:54 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	ft_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_duplicate(t_stack *stack_a, int num)
{
	int		i;
	t_node	*current;

	if (!stack_a || !stack_a->head)
		return (0);
	current = stack_a->head;
	i = 0;
	while (i < stack_a->size)
	{
		if (current->value == num)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

static long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			return (2147483648L);
		i++;
	}
	return (result * sign);
}

void	ft_add_number(t_program *program,
			t_stack *stack_a, char *arg, char **to_free)
{
	long	num;
	t_node	*node;

	if (!ft_valid_number(arg))
		ft_error_exit(program, stack_a, to_free);
	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN || ft_duplicate(stack_a, num))
		ft_error_exit(program, stack_a, to_free);
	node = ft_create_node(num);
	if (!node)
		ft_error_exit(program, stack_a, to_free);
	ft_stack_addback(stack_a, node);
}

int	ft_check_flag(char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (2);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (3);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (4);
	if (ft_strncmp(arg, "--bench", 8) == 0)
		return (5);
	return (0);
}
