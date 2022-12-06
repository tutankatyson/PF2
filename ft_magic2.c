/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:55:10 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/07 00:02:18 by jorsanch         ###   ########.fr       */
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

int	ft_magicselec(char **txt, va_list ap)
{
	int	cont;
	int	i;

	i = ft_findendchar(*txt);
	cont = 1;
	if (*(*txt + i) == 's')
		cont = ft_magic_string(txt, va_arg(ap, char *));
	else if (*(*txt + i) == 'd' || *(*txt + i) == 'i')
		cont = ft_magic_signed(txt, va_arg(ap, int));
	else if (*(*txt + i) == 'c')
		cont = ft_magic_char(txt, va_arg(ap, unsigned int));
	else if (*(*txt + i) == 'u')
		cont = ft_magic_unsigned(txt, va_arg(ap, unsigned int));
	else if (*(*txt + i) == 'p')
		cont = ft_magic_pointer(txt, va_arg(ap, unsigned long int));
	else if (*(*txt + i) == 'x')
		cont = ft_magic_hexa(txt, va_arg(ap, unsigned int));
	else if (*(*txt + i) == 'X')
		cont = ft_magic_hexa(txt, va_arg(ap, unsigned int));
	else if (*(*txt + i) == '%')
	{
		ft_putchar_fd('%', 1);
		*txt = *txt + i + 1;
	}
	return (cont);
}
