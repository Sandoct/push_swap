/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:17:00 by gpouzet           #+#    #+#             */
/*   Updated: 2023/01/05 16:35:15 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft/libft.h"
#include "libft/ft-printf/ft_printf.h"
#include "push_swap.h"

static int	parser(char **arg)
{
	int	conv;
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		if (!ft_isnumber(arg[i]))
			return (1);
		j = i;
		while (arg[++j])
			if (ft_strncmp(arg[i], arg[j], ft_strlen(arg[i])))
				return (1);
		conv = ft_atoi(arg[i]);
		if (conv < -10 || conv > 10)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*stacka;
	int	*stackb;
	int	i;

	// prelude au programme
	
	if (!parser(argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	stacka = ft_calloc(sizeof(int), tablen((void **)argv));
	stackb = ft_calloc(sizeof(int), tablen((void **)argv));
	i = 0;
	while (argv[i + 1])
	{
		stacka[i] = ft_atoi(argv[i]);
	}

	//actual sorting
	i = 0;
	while (stacka[i])
	{
		ft_printf("stacka %d :%d\n", i, stacka[i]);
		i++;
	}
	return (0);
}

