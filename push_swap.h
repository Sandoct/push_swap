/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:17:06 by gpouzet           #+#    #+#             */
/*   Updated: 2023/01/05 15:23:55 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	tablen(void **tab);
void	swap(int *stacka, int *stackb, char c);
void	push(int *stacka, int *stackb, char c);
void	rotate(int *stacka, int *stackb, char c);
void	revers_rotate(int *stacka, int *stackb, char c);
void	push_swap(int argc, char **argv);
