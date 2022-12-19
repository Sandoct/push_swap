/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:41:21 by gpouzet           #+#    #+#             */
/*   Updated: 2022/11/07 18:47:51 by gpouzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cal;

	if (nmemb >= 0XFFFFFFFF || size >= 0XFFFFFFFF)
		return ((void *)0);
	if (nmemb * size > 0XFFFFFFFF)
		return ((void *)0);
	cal = malloc(nmemb * size);
	if (cal)
		ft_bzero(cal, nmemb * size);
	return (cal);
}
