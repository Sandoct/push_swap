/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:17:06 by gpouzet           #+#    #+#             */
/*   Updated: 2023/02/06 14:30:20 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				top;
	unsigned int	capacity;
	int				*array;
}					t_stack;

t_stack		*construct_stack(unsigned int capacity);
int			stack_full(t_stack *stack);
int			stack_empty(t_stack *stack);
int			stack_peek(t_stack *stack);
int			stack_pop(t_stack *stack);
void		stack_push(t_stack *stack, int item);
void		stack_swap(t_stack *stack);
void		stack_rotate(t_stack *stack);
void		stack_rev_rota(t_stack *stack);
void		pw_swap(t_stack *stacka, t_stack *stackb, char c);
void		pw_push(t_stack *stacka, t_stack *stackb, char c);
void		pw_rotate(t_stack *stacka, t_stack *stackb, char c);
void		pw_revers_rotate(t_stack *stacka, t_stack *stackb, char c);
void		push_swap(t_stack *stacka);
#endif
