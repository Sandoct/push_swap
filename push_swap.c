/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:17:00 by gpouzet           #+#    #+#             */
/*   Updated: 2022/12/19 17:01:55 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

void	push_swap(int argc,int **argv)
{
	int	**separator;
	int	**stacka;
	int	**stackb;
	int	i;

	// prelude au programme
	
	if (!parser(argv[1]))
		ft_printf("Error\n");
	separator = ft_split(argv[1], " ");
	stacka = ft_calloc(sizeof(int), ft_strlen(separator));
	stackb = ft_calloc(sizeof(int), ft_strlen(separator));
	i = 0;
	while (separator[i])
		stacka[i] = ft_atoi(separator[ft_strlen(separator) - i++]);			// affectation en reverse 
	free(separator);														//free l'entiereté si necesaire
	
	//trie de la stack

}
