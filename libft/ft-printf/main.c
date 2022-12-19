/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:29:39 by gpouzet           #+#    #+#             */
/*   Updated: 2022/11/22 17:02:04 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...);

int main()
{
	int	a;
	int	b;

	ft_printf("test :\n");
	a = ft_printf("%xn\n", 42);
	b = printf("%.3dn\n", 42);
	printf("%d\n%d\n", a, b);
}

