/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:17:00 by gpouzet           #+#    #+#             */
/*   Updated: 2023/03/03 18:13:56 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"

static t_stack	*reducind(t_stack *stack)
{
	t_stack	*tmp;
	int		ranking;
	int		size;
	int		i;

	tmp = construct_stack(stack->capacity);
	size = -1;
	while (size++ < stack->top)
	{
		i = 0;
		ranking = stack->top;
		while (i <= stack->top)
			if (stack->array[size] < stack->array[i++])
				ranking--;
		stack_push(tmp, ranking);
	}
	free (stack->array);
	free (stack);
	return (tmp);
}

int	sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i--)
		if (stack->array[i] < stack->array[i + 1])
			return (1);
	return (0);
}

void	push_swap(t_stack *stacka)
{
	t_stack	*stackb;

	stackb = construct_stack(stacka->capacity);
	stacka = reducind(stacka);
	if (sorted(stacka))
	{
		if (stacka->capacity < 4)
			easyway(stacka, stackb);
		else if (stacka->capacity < 6)
			homemade(stacka, stackb);
		else if (stacka->capacity < 500)
			butterfly(stacka, stackb, 4);
		else
			butterfly(stacka, stackb, 9);
	}
	free(stacka->array);
	free(stacka);
	free(stackb->array);
	free(stackb);
}
