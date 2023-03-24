/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:22:32 by gpouzet           #+#    #+#             */
/*   Updated: 2023/03/15 16:38:13 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft/libft.h"

static int	parser(char **arg)
{
	int		i;

	while (*arg)
	{
		if (!ft_isnumber(*arg))
			return (1);
		i = 0;
		while (arg[++i])
			if (ft_atoi(*arg) == ft_atoi(*(arg + i)))
				return (1);
		i = 0;
		if (**arg == '-' || **arg == '+')
			i++;
		while (*(*arg + i) == '0')
			i++;
		if (**arg == '-' && ft_strlen(*arg + i) >= 10)
			if (0 < ft_strncmp(*arg + i, "2147483648", 11))
				return (1);
		if (**arg != '-' && ft_strlen(*arg + i) >= 10)
				if (0 < ft_strncmp(*arg + i, "2147483647", 11))
					return (1);
		arg++;
	}
	return (0);
}

static int	fullspace(char *str)
{
	while (*str)
		if (*str++ != ' ')
			return (0);
	return (1);
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

static int	procesing(char **argv)
{
	t_stack	*stacka;
	char	**args;
	char	*str;
	int		size[2];

	size[1] = 1;
	str = ft_calloc(1, 1);
	while (*++argv)
		str = append(str, *argv);
	args = ft_split(str, ' ');
	size[0] = split_size(str, ' ');
	if (!parser(args))
	{
		stacka = construct_stack(size[0]);
		while (size[0]--)
			stack_push(stacka, ft_atoi(args[size[0]]));
		push_swap(stacka);
		size[1] = 0;
	}
	size[0] = 0;
	while (size[0] <= split_size(str, ' '))
		free(args[size[0]++]);
	free(args);
	free(str);
	return (size[1]);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (ft_putstr_fd("Error no arguments\n", 2) - 18);
	while (i++ < argc)
		if (argv[i])
			if (fullspace(argv[i]))
				return (ft_putstr_fd("Error\n", 2) - 4);
	if (procesing(argv))
		return (ft_putstr_fd("Error\n", 2) - 4);
	return (0);
}
