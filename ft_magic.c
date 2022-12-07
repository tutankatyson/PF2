/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:12:41 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/07 16:07:45 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_magic_string(char **txt, char *arg)
{
	int	i;

	i = ft_findendchar(*txt);
	*txt = *txt + i + 1;
	if (arg == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(arg, 1);
	i = ft_strlen(arg);
	return (i);
}

int	ft_magic_signed(char **txt, int arg)
{
	char	*str;
	int		i;

	i = ft_findendchar(*txt);
	*txt = *txt + i + 1;
	str = ft_itoa(arg);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	ft_magic_unsigned(char **txt, unsigned long arg)
{
	char	*str;
	int		i;

	i = ft_findendchar(*txt);
	*txt = *txt + i;
	if (**txt == 'u')
	{
		str = ft_uitoa(arg);
		ft_putstr_fd(str, 1);
		*txt = *txt + i;
		i = ft_strlen(str);
		free(str);
		return (i);
	}
	return (0);
}

int	ft_magic_pointer(char **txt, unsigned long arg)
{
	int		i;

	i = ft_findendchar(*txt);
	*txt = *txt + i + 1;
	write(1, "0x", 2);
	i = ft_putnbrbase(arg, "0123456789abcdef");
	return (i + 2);
}
