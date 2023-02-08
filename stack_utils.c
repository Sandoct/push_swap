/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:23:07 by gpouzet           #+#    #+#             */
/*   Updated: 2023/02/06 14:29:24 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"

void	stack_push(t_stack *stack, int item)
{
	if (stack_full(stack))
		return ;
	stack->array[++stack->top] = item;
}

void	stack_swap(t_stack *stack)
{
	int	tmp1;
	int	tmp2;

	tmp1 = stack_pop(stack);
	tmp2 = stack_pop(stack);
	stack_push(stack, tmp1);
	stack_push(stack, tmp2);
}

void	stack_rotate(t_stack *stack)
{
	int		tmp;
	t_stack	*stacktmp;

	stacktmp = construct_stack(stack->capacity);
	tmp = stack_pop(stack);
	while (stack->top > -1)
		stack_push(stacktmp, stack_pop(stack));
	stack_push(stack, tmp);
	while (!stack_empty(stacktmp))
		stack_push(stack, stack_pop(stacktmp));
	free(stacktmp->array);
	free(stacktmp);
}

void	stack_rev_rota(t_stack *stack)
{
	int		tmp;
	t_stack	*stacktmp;

	stacktmp = construct_stack(stack->capacity);
	while (stack->top > -1)
		stack_push(stacktmp, stack_pop(stack));
	tmp = stack_pop(stack);
	while (!stack_empty(stacktmp))
		stack_push(stack, stack_pop(stacktmp));
	stack_push(stack, tmp);
	free(stacktmp->array);
	free(stacktmp);
}
