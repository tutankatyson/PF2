/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:48:17 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/06 23:13:30 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *txt, ...)
{
	va_list			ap;
	int				spells;
	unsigned int	cont;
	char			*txt0;
	char			*txt1;

	txt0 = ft_strdup(txt);
	txt1 = txt0;
	if (!txt0)
		return (0);
	cont = 0;
	spells = ft_spellcounter(txt1);
	if (spells)
	{
		va_start(ap, txt);
		while (spells-- > 0)
		{
			cont = cont + ft_go_writing(&txt1);
			cont = cont + ft_magicselec(&txt1, ap);
		}
		va_end(ap);
	}
	cont = cont + ft_go_writing(&txt1);
	free(txt0);
	return (cont);
}
