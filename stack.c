/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:15:58 by gpouzet           #+#    #+#             */
/*   Updated: 2023/02/06 14:24:11 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"

t_stack	*construct_stack(unsigned int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = ft_calloc(capacity, sizeof(int));
	return (stack);
}

int	stack_full(t_stack *stack)
{
	return (stack->top == (int)stack->capacity - 1);
}

int	stack_empty(t_stack *stack)
{
	return (stack->top == -1);
}

int	stack_peek(t_stack *stack)
{
	if (stack_empty(stack))
		return (-2147483648);
	return (stack->array[stack->top]);
}

int	stack_pop(t_stack *stack)
{
	if (stack_empty(stack))
		return (-2147483648);
	return (stack->array[stack->top--]);
}
