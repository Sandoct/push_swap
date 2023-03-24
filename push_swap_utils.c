/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <gpouzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:48:42 by gpouzet           #+#    #+#             */
/*   Updated: 2023/01/13 18:19:12 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"

int	sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i--)
		if (stack->array[i] < stack->array[i + 1])
			return (1);
	return (0);
}

void	pw_swap(t_stack *stacka, t_stack *stackb, char c)
{
	if (c == 's')
	{
		stack_swap(stacka);
		stack_swap(stackb);
		ft_putstr_fd("ss\n", 1);
	}
	else if (c == 'a')
	{
		stack_swap(stacka);
		ft_putstr_fd("sa\n", 1);
	}
	else if (c == 'b')
	{
		stack_swap(stackb);
		ft_putstr_fd("sb\n", 1);
	}
}

void	pw_push(t_stack	*stacka, t_stack *stackb, char c)
{
	if (c == 'a')
	{
		if (stack_full(stacka) || stack_empty(stackb))
			return ;
		stack_push(stacka, stack_pop(stackb));
		ft_putstr_fd("pa\n", 1);
	}
	if (c == 'b')
	{
		if (stack_full(stackb) || stack_empty(stacka))
			return ;
		stack_push(stackb, stack_pop(stacka));
		ft_putstr_fd("pb\n", 1);
	}
}

void	pw_rotate(t_stack *stacka, t_stack *stackb, char c)
{
	if (c == 'r')
	{
		stack_rotate(stacka);
		stack_rotate(stackb);
		ft_putstr_fd("rr\n", 1);
	}
	else if (c == 'a')
	{
		stack_rotate(stacka);
		ft_putstr_fd("ra\n", 1);
	}
	else if (c == 'b')
	{
		stack_rotate(stackb);
		ft_putstr_fd("rb\n", 1);
	}
}

void	pw_revers_rotate(t_stack *stacka, t_stack *stackb, char c)
{
	if (c == 'r')
	{
		stack_rev_rota(stacka);
		stack_rev_rota(stackb);
		ft_putstr_fd("rrr\n", 1);
	}
	else if (c == 'a')
	{
		stack_rev_rota(stacka);
		ft_putstr_fd("rra\n", 1);
	}
	else if (c == 'b')
	{
		stack_rev_rota(stackb);
		ft_putstr_fd("rrb\n", 1);
	}
}
