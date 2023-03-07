/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:08:43 by gpouzet           #+#    #+#             */
/*   Updated: 2023/03/07 14:21:55 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "../libft/printf/ft_printf.h"
#include "../libft/GNL/get_next_line.h"
#include "../push_swap.h"

static int	instruction(t_stack *stacka, t_stack *stackb, char *com)
{
	if (!ft_strncmp(com, "sa\n", 3) || !ft_strncmp(com, "ss\n", 3))
		stack_swap(stacka);
	else if (!ft_strncmp(com, "sb\n", 3) || !ft_strncmp(com, "ss\n", 3))
		stack_swap(stackb);
	else if (!ft_strncmp(com, "pa\n", 3))
		stack_push(stacka, stack_pop(stackb));
	else if (!ft_strncmp(com, "pb\n", 3))
		stack_push(stackb, stack_pop(stacka));
	else if (!ft_strncmp(com, "ra\n", 3) || !ft_strncmp(com, "rr\n", 3))
		stack_rotate(stacka);
	else if (!ft_strncmp(com, "rb\n", 3) || !ft_strncmp(com, "rr\n", 3))
		stack_rotate(stackb);
	else if (!ft_strncmp(com, "rra\n", 4) || !ft_strncmp(com, "rrr\n", 4))
		stack_rev_rota(stacka);
	else if (!ft_strncmp(com, "rrb\n", 4) || !ft_strncmp(com, "rrr\n", 4))
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
	com = get_next_line(0);
	while (com)
	{
		if (!instruction(stacka, stackb, com))
			nbcom++;
		else if (ft_printf("Error, command not know."))
			break ;
		free(com);
		com = get_next_line(0);
	}
	if (!sorted(stacka) && stack_empty(stackb))
		ft_printf("OK\nEn %d, coup.", nbcom);
	else
		ft_putstr_fd("KO", 1);
	free(com);
	free(stacka->array);
	free(stacka);
	free(stackb->array);
	free(stackb);
}
