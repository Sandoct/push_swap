/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:08:43 by gpouzet           #+#    #+#             */
/*   Updated: 2023/02/06 14:32:18 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf/ft_printf.h"
#include "../libft/GNL/get_next_line.h"
#include "../push_swap.h"

static int	instruction(t_stack *stacka, t_stack *stackb, char *com)
{
	if (!ft_strncmp(com, "sa", 2) || !ft_strncmp(com, "ss", 2))
		stack_swap(stacka);
	else if (!ft_strncmp(com, "sb", 2) || !ft_strncmp(com, "ss", 2))
		stack_swap(stackb);
	else if (!ft_strncmp(com, "pa", 2))
		stack_push(stacka, stack_pop(stackb));
	else if (!ft_strncmp(com, "pb", 2))
		stack_push(stackb, stack_pop(stacka));
	else if (!ft_strncmp(com, "ra", 2) || !ft_strncmp(com, "rr", 2))
		stack_rotate(stacka);
	else if (!ft_strncmp(com, "rb", 2) || !ft_strncmp(com, "rr", 2))
		stack_rotate(stackb);
	else if (!ft_strncmp(com, "rra", 2) || !ft_strncmp(com, "rrr", 2))
		stack_rev_rota(stacka);
	else if (!ft_strncmp(com, "rrb", 2) || !ft_strncmp(com, "rrr", 2))
		stack_rev_rota(stackb);
	else
		return (1);
	return (0);
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

void	checker(t_stack *stacka)
{
	t_stack	*stackb;
	char	*com;
	int		nbcom;

	nbcom = 0;
	stackb = construct_stack(stacka->capacity);
	com = get_next_line(1);
	while (com)
	{
		if (!instruction(stacka, stackb, com))
			nbcom++;
		else if (ft_printf("Error, command not know."))
			return ;
		com = get_next_line(1);
	}
	if (!sorted(stacka))
		ft_printf("OK\nEn %d, coup.", nbcom);
	else
		ft_putstr_fd("KO", 1);
}
