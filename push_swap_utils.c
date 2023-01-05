/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <gpouzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:48:42 by gpouzet           #+#    #+#             */
/*   Updated: 2023/01/05 16:18:06 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft/libft.h"
#include "libft/ft-printf/ft_printf.h"

size_t	tablen(void **tab)
{
	size_t	size;

	size = 0;
	while (*tab++)
		size++;
	return (size);
}
/*
void	swap(int *stacka, int *stackb, char c)
{
	int	tmp;

	if (c == 'a' || c == 's')
	{
		tmp = stacka[0];
		stacka[0] = stacka[1];
		stacka[1] = tmp;
	}
	if (c == 'b' || c == 's')
	{
		tmp = stackb[0];
		stackb[0] = stackb[1];
		stackb[1] = tmp;
	}
	if (c == 's')
		ft_printf("ss");
	else if (c == 'a')
		ft_printf("sa");
	else if (c == 'b')
		ft_printf("sb");
}

void	push(int *stacka, int *stackb, char c)
{
	int	i;

	if (c == 'a')
	{
		i = tablen(stacka) - 1;
		if (stacka[i] != NULL && stackb[0] == NULL)
			break ;
		while (i)
			stacka[i] = stacka[--i];
		stacka[0] = stackb[0];
		while (stackb[i])
			stackb[i] = stackb[++i];
		ft_printf("pa");
	}
	else if (c == 'b')
	{
		i = tablen(stackb) - 1;
		if (stackb[i] != NULL && stacka[0] == NULL)
			break ;
		while (i)
			stackb[i] = stackb[--i];
		stackb[0] = stacka[0];
		while (stacka[i])
			stacka[i] = stacka[++i];
		stacka[i] = NULL;
		ft_printf("pb");
	}
}

void	rotate(int *stacka, int *stackb, char c)
{
	int	tmp;
	int	i;

	if (c == 'a' || c == 'r')
	{
		i = 0;
		tmp = stacka[0];
		while (stacka[i])
			stacka[i] = stacka[++i];
		stacka[i] = tmp;
	}
	if (c == 'b' || c == 'r')
	{
		i = 0;
		tmp = stackb[0];
		while (stackb[i])
			stackb[i] = stackb[++i];
		stackb[i] = tmp;
	}
	if (c == 'r')
		ft_printf("rr");
	else if (c == 'a')
		ft_printf("ra");
	else if (c == 'b')
		ft_printf("rb");
}

void	revers_rotate(int *stacka, int *stackb, char c)
{
	int	tmp;
	int	i;

	if (c == 'a' || c == 'r')
	{
		i = tablen(stacka);
		tmp = stacka[i];
		while (i)
			stacka[i] = stacka[--i];
		stacka[0] = tmp;
	}
	if (c == 'b' || c == 'r')
	{
		i = tablen(stackb);
		tmp = stackb[i];
		while (i)
			stackb[i] = stackb[--i];
		stackb[0] = tmp;
	}
	if (c == 'r')
		ft_printf("rrr");
	else if (c == 'a')
		ft_printf("rra");
	else if (c == 'b')
		ft_printf("rrb");
}*/
