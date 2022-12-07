/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blackmagic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:12:41 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/07 00:24:46 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_blackmagicselec(char **txt, va_list ap)
{
	int	cont;
	int	i;

	i = ft_findendchar(*txt);
	cont = 1;
	if (*(*txt + i) == 's')
		cont = ft_blackmagic_string(txt, va_arg(ap, char *));
	else if (*(*txt + i) == 'd' || *(*txt + i) == 'i')
		cont = ft_blackmagic_signed(txt, va_arg(ap, int));
	else if (*(*txt + i) == 'c')
		cont = ft_blackmagic_char(txt, va_arg(ap, unsigned int));
	else if (*(*txt + i) == 'u')
		cont = ft_blackmagic_unsigned(txt, va_arg(ap, unsigned int));
	else if (*(*txt + i) == 'p')
		cont = ft_blackmagic_pointer(txt, va_arg(ap, unsigned long int));
	else if (*(*txt + i) == 'x')
		cont = ft_blackmagic_hexa(txt, va_arg(ap, unsigned int));
	else if (*(*txt + i) == 'X')
		cont = ft_blackmagic_hexa(txt, va_arg(ap, unsigned int));
	else if (*(*txt + i) == '%')
	{
		ft_putchar_fd('%', 1);
		*txt = *txt + i + 1;
	}
	return (cont);
}

int	ft_blackmagic_string(char **txt, char *arg)
{
	int		i;
	char	*ins;

	i = ft_findendchar(*txt);
	ins = ft_substr(*txt, 0, i);								printf("\nINS:%s",ins);
	ins = ft_makestr(ft_fill(ins), ft_precision(ins), ft_alignment(ins), arg);

	*txt = *txt + i + 1;
	if (arg == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(ins, 1);
	i = ft_strlen(ins);
	free(ins);
	return (i);
}

int	ft_blackmagic_signed(char **txt, int arg)
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

int	ft_blackmagic_unsigned(char **txt, unsigned long arg)
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

int	ft_blackmagic_pointer(char **txt, unsigned long arg)
{
	int		i;

	i = ft_findendchar(*txt);
	*txt = *txt + i + 1;
	write(1, "0x", 2);
	i = ft_putnbrbase(arg, "0123456789abcdef");
	return (i + 2);
}
