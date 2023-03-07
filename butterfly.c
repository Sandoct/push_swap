/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:27:32 by gpouzet           #+#    #+#             */
/*   Updated: 2023/03/03 18:00:12 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"

void	spread(t_stack *stacka, t_stack *stackb, int grp, int cap)
{
	int	i;
	int	j;

	i = stacka->top;
	j = 0;
	while (stacka->array[i] > cap * grp || stacka->array[i] < cap * (grp - 1))
		i--;
	while (stacka->array[j] > cap * grp || stacka->array[j] < cap * (grp - 1))
		j++;
	if (stacka->top - i > ++j)
		while (j--)
			pw_revers_rotate(stacka, stackb, 'a');
	else
		while (i++ < stacka->top)
			pw_rotate(stacka, stackb, 'a');
	if (stack_peek(stacka) < cap / 2 + cap * (grp - 1))
		pw_push(stacka, stackb, 'b');
	else
	{
		pw_push(stacka, stackb, 'b');
		pw_rotate(stacka, stackb, 'b');
	}
}

int	opti(t_stack *stacka, t_stack *stackb, int bo, int top)
{
	if (stack_peek(stackb) == top - 1)
	{
		pw_push(stacka, stackb, 'a');
		return (1);
	}
	if (bo && stack_peek(stackb) == top - 2)
	{
		pw_push(stacka, stackb, 'a');
		pw_rotate(stacka, stackb, 'a');
	}
	return (0);
}

void	swing(t_stack *stacka, t_stack *stackb, int top, int tab[3])
{
	tab[2] = 0;
	tab[1] = 0;
	tab[0] = stackb->top;
	while (stackb->array[tab[0]] != stackb->top)
		tab[0]--;
	while (stackb->array[tab[1]] != stackb->top)
		tab[1]++;
	if (stackb->top - tab[0] > ++tab[1])
	{
		while (tab[1]--)
		{
			tab[2] += opti(stacka, stackb, tab[2], top);
			pw_revers_rotate(stacka, stackb, 'b');
		}
	}
	else
	{
		while (tab[0]++ < stackb->top)
		{
			tab[2] += opti(stacka, stackb, tab[2], top);
			if (stackb->array[stackb->top] != top)
				pw_rotate(stacka, stackb, 'b');
		}
	}
}

void	butterfly(t_stack *stacka, t_stack *stackb, int nb_grp)
{
	int	tab[3];
	int	grp;
	int	grp_size;
	int	i;

	grp = 0;
	grp_size = stacka->capacity / nb_grp;
	while (stacka->top + 1)
	{
		i = 0;
		grp++;
		while (i++ < grp_size && stacka->top >= 0)
			spread(stacka, stackb, grp, stacka->capacity / nb_grp);
	}
	while (stackb->top + 1)
	{
		swing(stacka, stackb, stackb->top, tab);
		pw_push(stacka, stackb, 'a');
		if (stacka->top > 0)
			if (stack_peek(stacka) > stacka->array[stacka->top - 1])
				pw_swap(stacka, stackb, 'a');
		while (stack_peek(stacka) > stacka->array[0])
			pw_revers_rotate(stacka, stackb, 'a');
	}
}
