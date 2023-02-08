/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:17:00 by gpouzet           #+#    #+#             */
/*   Updated: 2023/02/06 14:23:26 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"
#include "libft/printf/ft_printf.h"

void	show_stack(t_stack *stack)
{
	t_stack	*stacktmp;
	int		tmp;

	stacktmp = construct_stack(stack->capacity);
	while (!stack_empty(stack))
	{
		tmp = stack_pop(stack);
		ft_printf("%d\n", tmp);
		stack_push(stacktmp, tmp);
	}
	while (!stack_empty(stacktmp))
		stack_push(stack, stack_pop(stacktmp));
}

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

static int	sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i--)
		if (stack->array[i] < stack->array[i + 1])
			return (1);
	return (0);
}

static int	sorting_algo(t_stack *stacka, t_stack *stackb)
{
	int	bitsmax;
	int	size;
	int	i;
	int	action;

	action = 0;
	i = 2;
	bitsmax = 1;
	while (stacka->capacity > (unsigned int)i - 1)
	{
		i *= 2;
		bitsmax++;
	}
	i = -1;
	while (i++ < bitsmax)
	{
		size = stacka->capacity;
		while (size--)
		{
			if ((stack_peek(stacka) >> i & 1) == 0)
			{
				action++;
				pw_push(stacka, stackb, 'b');
			}
			else
			{
				action++;
				pw_rotate(stacka, stackb, 'a');
			}
		}
		while (!stack_empty(stackb))
		{
			action++;
			pw_push(stacka, stackb, 'a');
		}
		if (!sorted(stacka))
			return (action);
	}
	return (action);
}

void	push_swap(t_stack *stacka)
{
	t_stack	*stackb;
	int		i;

	i = 0;
	stackb = construct_stack(stacka->capacity);
	stacka = reducind(stacka);
	if (sorted(stacka))
		i = sorting_algo(stacka, stackb);
	ft_printf("nb etape : %d\n", i);
	free(stacka->array);
	free(stacka);
	free(stackb->array);
	free(stackb);
}
