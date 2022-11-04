/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:30:57 by jorsanch          #+#    #+#             */
/*   Updated: 2022/11/03 22:57:34 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void printbuff(char *str, char *name)
{
	size_t i = 0;
	char c = '\n';
	char *c3 = "$\\n$";
	char c2 = '|';

	write(1,&c,1);
	while (name[i] != '\0')
	{
		write(1,&name[i],1);
		i++;
	}
	write(1,":",1);

	write(1,&c2,1);
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == c)
		{
			write(1,c3,4);
		}
		else
			write(1,&str[i],1);
		write(1,&c2,1);
		i++;
	}
	write(1,"$\\0$|",5);
}

/*Cuenta la de veces que hay que llamar a magic*/

int	ft_spellcounter(char *str)
{
	int	i;
	int	count;
	int	last;

	last = 0;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && !last)
		{
			count++;
			last = 1;
		}
		else
			last = 0;
		i++;
	}
	return (count);
}

int	ft_checkendchar(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'p' || c == 'c' || c == 's'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int ft_findendchar(char *txt)
{
	int i = 0;
	if (txt[i] != 0)
	{
		i++;
		while (!ft_checkendchar(txt[i]))
		{
			i++;
		}
		return(i);
	}
	return 0;
}

int	ft_go_writing(char **txt)
{
	int i;

	i = 0;
	while (**txt != '%' && **txt != '\0')
	{
		write(1, *txt, 1);
		*txt = *txt + 1;
		i++;
	}
	return (i);								
}
