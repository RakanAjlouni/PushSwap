/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajlouni <rajlouni@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:27:31 by rajlouni          #+#    #+#             */
/*   Updated: 2026/10/31 19:14:32 by lnaamneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total_ops;
	float	disorder;
}	t_bench;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_porgram
{
	int		flag;
	int		bench;
	t_bench	*benchmark;
}	t_program;

void	ft_init_program(t_program *program);
void	ft_init_stack(t_stack *stack);
t_node	*ft_create_node(int value);
void	ft_stack_addback(t_stack *stack, t_node *new_node);
void	ft_stack_addfront(t_stack *stack, t_node *new_node);
t_node	*ft_stack_pop(t_stack *stack);
void	ft_stack_free(t_stack *stack);
void	ft_program_free(t_program *program);
void	ft_assign_indices(t_stack *stack);
void	ft_parser(t_program *program, t_stack *stack_a, int argc, char **argv);
int		ft_check_flag(char *arg);
int		ft_is_sorted(t_stack *a, t_stack *b);
int		ft_shortest_path(t_stack *stack_a, int target_index);
void	ft_add_number(t_program *program,
			t_stack *stack_a, char *arg, char **to_free);
void	ft_push(t_stack *giver, t_stack *taker);
void	ft_swap(t_stack *swapper);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);
float	ft_compute_disorder(t_stack *stack);
void	ft_selection_sort(t_program *program,
			t_stack *stack_a, t_stack *stack_b);
void	ft_chunk_sort(t_program *program,
			t_stack *stack_a, t_stack *stack_b);
void	ft_radix_sort(t_program *program,
			t_stack *stack_a, t_stack *stack_b);
void	ft_adaptive_sort(t_program *program,
			t_stack *stack_a, t_stack *stack_b);
void	ft_print_bench(t_program *program);
void	ft_free_split(char **args);
void	ft_error_exit(t_program *program, t_stack *stack_a, char **args);
void	pa(t_program *program, t_stack *a, t_stack *b);
void	pb(t_program *program, t_stack *a, t_stack *b);
void	sa(t_program *program, t_stack *a);
void	sb(t_program *program, t_stack *b);
void	ss(t_program *program, t_stack *a, t_stack *b);
void	ra(t_program *program, t_stack *a);
void	rb(t_program *program, t_stack *b);
void	rr(t_program *program, t_stack *a, t_stack *b);
void	rra(t_program *program, t_stack *a);
void	rrb(t_program *program, t_stack *b);
void	rrr(t_program *program, t_stack *a, t_stack *b);

#endif
