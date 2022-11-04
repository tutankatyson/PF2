/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:12:41 by jorsanch          #+#    #+#             */
/*   Updated: 2022/11/03 23:13:41 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_magic_string(char **txt, char *arg)
{
	int i = 0;

	i = ft_findendchar(*txt);
	*txt = *txt + i + 1;
	if (arg == NULL)
	{
		ft_putstr_fd("(null)",1);
		return (6);
	}
	ft_putstr_fd(arg, 1);	
	i = ft_strlen(arg);

	return (i);
}

int ft_magic_signed(char **txt, int arg)
{

	char *str;
	int i = 0;

	i = ft_findendchar(*txt);
	*txt = *txt + i + 1;

	str = ft_itoa(arg);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int ft_magic_unsigned(char **txt, unsigned long arg)
{

	char *str = NULL;
	int i = 0;

	i = ft_findendchar(*txt);
	*txt = *txt + i;
	if (ft_arg_type(**txt) == 4) 				//char
	{
		ft_putchar_fd(arg,1);
		*txt = *txt + 1;
		return (1);
	}
	if (ft_arg_type(**txt) == 5) 				//unsigned
	{
		str = ft_uitoa(arg);
		ft_putstr_fd(str, 1);	
		i = ft_strlen(str);	
		*txt = *txt + i;	
		free(str);		
		return (i);
	}
	if (ft_arg_type(**txt) == 6) 				//Pointer
	{
		write(1,"0x10",4);
		i = ft_putnbrbase(arg,"0123456789abcdef");
		*txt = *txt + 1;					
		return (i+4);
	}
	if (ft_arg_type(**txt) == 7) 				//hexa
	{
		i = ft_putnbrbase(arg,"0123456789abcdef");
		*txt = *txt + 1;					
		return (i);
	}
	if (ft_arg_type(**txt) == 8) 				//HEXA
	{
		i = ft_putnbrbase(arg,"0123456789ABCDEF");
		*txt = *txt + 1;					
		return (i);
	}
	return 0;
}

int ft_magicselec(char **txt, va_list ap)
{
	int cont = 0;
	char ch;

	ch = *txt[ft_findendchar(*txt)];

	if (ch == 's')
		cont = ft_magic_string(txt, va_arg(ap, char *));
	if (ch == 'd' || ch == 'i')
		cont = ft_magic_signed(txt, va_arg(ap, int));
	if (ch == 'c')												
		cont = ft_magic_char(txt, va_arg(ap, unsigned int));



	if (ch == '%')												//42: %
		return (42);
	if (ch == 'u')												//5: u
		return (5);
	if (ch == 'p')												//6: p
		return (6);
	if (ch == 'x')												//7: x
		return (7);
	if (ch == 'X')												//8: X
		
	return (cont);

}