/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:48:17 by jorsanch          #+#    #+#             */
/*   Updated: 2022/11/03 22:44:56 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *txt, ...)
{
	va_list			ap;
	int				spells;
	unsigned int	cont;
	char *txt0;
	char  *txt1;

	txt0 = ft_strdup(txt);
	txt1 = txt0;
	if (!txt0)
		return 0;
	cont = 0;
	spells = ft_spellcounter(txt1);
	if(spells)
	{
		va_start(ap, txt);
		while (spells > 0)
		{
			cont = cont + ft_go_writing(&txt1);
			cont = cont + ft_magicselec(&txt1, ap);
			spells--;
		}
		va_end(ap);
	}
	cont = cont + ft_go_writing(&txt1);
	free(txt0);
	return (cont);
}




/*
int main()
{
	int i, j;


	i	=	ft_printf("\n numero %s",NULL);
	j	=      printf("\n numero %s",NULL);

	if(i != j)
		printf("\nERROR DE DESAJUSTE EN EL RETURN");


}
  */