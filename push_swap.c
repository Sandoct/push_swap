/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:17:00 by gpouzet           #+#    #+#             */
/*   Updated: 2023/03/03 16:17:47 by gpouzet          ###   ########.fr       */
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

int	condition(size_t cap, int run, int comp, int grp)
{
	int grp_size;

	grp_size = cap/grp;
	if (comp < ((grp_size / 2) + (grp - run - 1) * grp_size))
		return (0);
	return (1);
}

void	spread(t_stack *stack, int max, int min)
{
	int	i;
	int	j;

	i = stack->top;
	j = 0;
	while (stack->array[i] > max || stack->array[i] < min)
		i--;
	while (stack->array[j] > max || stack->array[j] < min)
		j++;
	if (stack->top - i > ++j)
		while (j--)
			pw_revers_rotate(stack, stack, 'a');
	else
		while (i++ < stack->top)
			pw_rotate(stack, stack, 'a');
}

void	swing(t_stack *stacka, t_stack *stackb, int top)
{
	int	i;
	int	j;
	int	bo;

	bo = 0;
	i = stackb->top;
	j = 0;
	while (stackb->array[i] != stackb->top)
		i--;
	while (stackb->array[j] != stackb->top)
		j++;
	if (stackb->top - i > ++j)
		while (j--)
		{
			if (stack_peek(stackb) == stackb->top - 1)
				pw_push(stacka, stackb, 'a');
/*			if (stack_peek(stackb) == top - 1)
			{
				bo = 1;
				pw_push(stacka, stackb, 'a');
			}
			if (bo && stack_peek(stackb) == top - 2)
			{
				pw_push(stacka, stackb, 'a');
				pw_rotate(stacka, stackb, 'a');
			}
*/			pw_revers_rotate(stacka, stackb, 'b');
		}
	else
		while (i++ < stackb->top)
		{
			if (stack_peek(stackb) == stackb->top - 1)
				pw_push(stacka, stackb, 'a');
/*			if (stack_peek(stackb) == top - 1)
			{
				bo = 1;
				pw_push(stacka, stackb, 'a');
			}
			if (bo && stack_peek(stackb) == top - 2)
			{
				pw_push(stacka, stackb, 'a');
				pw_rotate(stacka, stackb, 'a');
			}
*/			if (stackb->array[stackb->top] != top)
				pw_rotate(stacka, stackb, 'b');
		}
}

void	butterfly(t_stack *stacka, t_stack *stackb, int nb_grp)
{
	int	grp;
	int	grp_size;
	int	i;

	grp = nb_grp;
	grp_size = stacka->capacity / grp;
	while (stacka->top + 1)
	{
		i = 0;
		grp--;
		while (i++ < grp_size && stacka->top >= 0)
		{
			spread(stacka, grp_size * (nb_grp - grp) - 1, grp_size * (nb_grp - 1 - grp));
			if (condition(stacka->capacity, grp, stack_peek(stacka), nb_grp))
			{
				pw_push(stacka, stackb, 'b');
			}
			else
			{
				pw_push(stacka, stackb, 'b');
				pw_rotate(stacka, stackb, 'b');
			}
		}
	}
/*	ft_printf("\n B :\n");
	show_stack(stackb);
	ft_printf("\n A :\n");
	show_stack(stacka);
*/	while (stackb->top + 1)
	{
		swing(stacka, stackb, stackb->top);
		while (!stack_empty(stacka) && stack_peek(stacka) < stack_peek(stackb))
		{
			pw_push(stacka, stackb, 'b');
			pw_swap(stacka, stackb, 'b');
		}
		pw_push(stacka, stackb, 'a');
/*		if (stacka->top > 0 && stack_peek(stacka) > stacka->array[stacka->top - 1])
			pw_swap(stacka, stackb, 'a');
		while (stack_peek(stacka) > stacka->array[0])
			pw_revers_rotate(stacka, stackb, 'a');
*/	}
/*	ft_printf("\n B :\n");
	show_stack(stackb);
	ft_printf("\n A :\n");
	show_stack(stacka);
*/
}

void	push_swap(t_stack *stacka)
{
	t_stack	*stackb;

	stackb = construct_stack(stacka->capacity);
	stacka = reducind(stacka);
	if (sorted(stacka))
	{
		if (stacka->capacity < 5)
			butterfly(stacka, stackb, 1);
		else if (stacka->capacity < 500)
			butterfly(stacka, stackb, 4);
		else
			butterfly(stacka, stackb, 9);
	}
	//	sorting_algo(stacka, stackb);
	free(stacka->array);
	free(stacka);
	free(stackb->array);
	free(stackb);
}
