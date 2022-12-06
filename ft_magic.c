/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:12:41 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/06 20:52:46 by jorsanch         ###   ########.fr       */
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


	if (**txt == 'c') 				//char
	{
		ft_putchar_fd(arg,1);
		*txt = *txt + 1;			//			printf(GREEN "\ntxt:%s"RESET, *txt);	
		return (1);
	}



	if (**txt == 'u') 				//unsigned
	{
		str = ft_uitoa(arg);
		ft_putstr_fd(str, 1);	
		i = ft_strlen(str);	
		*txt = *txt + i;	
		free(str);		
		return (i);
	}
	if (**txt == 'p') 				//Pointer
	{
		write(1,"0x",2);
		i = ft_putnbrbase(arg,"0123456789abcdef");
									//			printf(YELLOW"putnbrbase return -> %i"RESET, i);
		*txt = *txt + 1;					
		return (i+2);
	}
	if (**txt == 'x') 				//hexa
	{
		i = ft_putnbrbase(arg,"0123456789abcdef");
									//		 	printf(YELLOW"putnbrbase return -> %i"RESET, i);
		*txt = *txt + 1;					
		return (i);
	}
	if (**txt == 'X') 				//HEXA
	{
		i = ft_putnbrbase(arg,"0123456789ABCDEF");
									//			printf(YELLOW"putnbrbase return -> %i"RESET, i);
		*txt = *txt + 1;					
		return (i);
	}
	return 0;
}

int ft_magicselec(char **txt, va_list ap)
{
	int cont = 0;
	int i = 0;
									//			printf(GREEN "\n------ MAGIC SELEC ------"RESET);
	i = ft_findendchar(*txt);		//			printf(GREEN "\nENDCHAR: %c"RESET, *(*txt + i));					

	if (*(*txt + i) == 's')
		cont = ft_magic_string(txt, va_arg(ap, char *));
	else
	if (*(*txt + i) == 'd' || *(*txt + i) == 'i')
		cont = ft_magic_signed(txt, va_arg(ap, int));
	else
	if (*(*txt + i) == 'c')												
		cont = ft_magic_unsigned(txt, va_arg(ap, unsigned int));
	else
	if (*(*txt + i) == 'u')												//5: u
		cont = ft_magic_unsigned(txt, va_arg(ap, unsigned int));
	else
	if (*(*txt + i) == 'p')												//6: p
		cont = ft_magic_unsigned(txt, va_arg(ap, unsigned int));
	else
	if (*(*txt + i) == 'x')												//7: x
		cont = ft_magic_unsigned(txt, va_arg(ap, unsigned int));
	else
	if (*(*txt + i) == 'X')												//8: X
		cont = ft_magic_unsigned(txt, va_arg(ap, unsigned int));
	else
	if (*(*txt + i) == '%')												//42: %
	{
										//		printf(GREEN "\n---------IF--------"RESET);
		ft_putchar_fd('%',1);
		cont++;
		*txt = *txt + i + 1;
	}



	return (cont);

}