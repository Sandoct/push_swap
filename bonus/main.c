/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:21:24 by gpouzet           #+#    #+#             */
/*   Updated: 2023/02/06 14:39:24 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"
#include "../libft/libft.h"

void	checker(t_stack *stacka);

static int	parser(char **arg)
{
	int	conv;
	int	i;
	int	j;

	i = 0;
	while (arg[++i])
	{
		if (!ft_isnumber(arg[i]))
			return (1);
		j = i;
		while (arg[++j])
			if (!ft_strncmp(arg[i], arg[j], 10))
				return (1);
		conv = ft_atoi(arg[i]);
		if (conv < -2147483648 || conv > 2147483647)
			return (1);
	}
	return (0);
}

static char	*append(char *file, char *reading)
{
	char	*tmp;
	char	*tmp1;

	if (!file)
		return (ft_substr(reading, 0, ft_strlen(reading)));
	tmp = ft_strjoin(file, reading);
	tmp1 = ft_strjoin(tmp, " ");
	free(file);
	free(tmp);
	return (tmp1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	char	**args;
	char	*str;
	int		size;

	str = ft_calloc(1, 1);
	if (argc < 2)
		return (ft_putstr_fd("Error\n", 1) - 4);
	while (*++argv)
		str = append(str, *argv);
	args = ft_split(str, ' ');
	size = split_size(str, ' ');
	if (parser(args))
		return (ft_putstr_fd("Error\n", 1) - 4);
	stacka = construct_stack(size);
	while (size--)
		stack_push(stacka, ft_atoi(args[size]));
	checker(stacka);
	size = split_size(str, ' ');
	free(str);
	while (size)
		free(args[--size]);
	free(args);
	return (0);
}
