/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:55:10 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/07 00:24:08 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_magic_char(char **txt, unsigned long arg)
{
	int		i;

	i = ft_findendchar(*txt);
	*txt = *txt + i;
	if (**txt == 'c')
	{
		ft_putchar_fd(arg, 1);
		*txt = *txt + 1;
		return (1);
	}
	return (0);
}

int	ft_magic_hexa(char **txt, unsigned long arg)
{
	int		i;

	i = ft_findendchar(*txt);
	*txt = *txt + i;
	if (**txt == 'x')
	{
		i = ft_putnbrbase(arg, "0123456789abcdef");
		*txt = *txt + 1;
		return (i);
	}
	if (**txt == 'X')
	{
		i = ft_putnbrbase(arg, "0123456789ABCDEF");
		*txt = *txt + 1;
		return (i);
	}
	return (0);
}
