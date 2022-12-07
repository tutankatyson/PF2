/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:39:34 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/07 15:48:38 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

char	*ft_makestr(size_t fill, size_t precision, int aling, char *str)
{
	char	*txt;

	if (!precision && !fill)
	{
		txt = ft_strdup(str);
		return (txt);
	}
	if (precision && precision < ft_strlen(str))
	{
		txt = ft_substr(str, 0, precision);
	}
	else
		txt = ft_strdup(str);

	if (fill > ft_strlen(txt))
	{
		if (aling)
		{
			txt = ft_fill_right(txt, ' ', fill);
		}
		else
			txt = ft_fill_left(txt, ' ', fill);
	}
	return (txt);
}

char	*ft_fill_left(char *txt, char fill, size_t leng)
{
	char		*temp;
	size_t		i;
	int			j;

	if (!(ft_strlen(txt) < leng))
	{
		return (txt);
	}
	temp = ft_calloc(leng + 1, sizeof(char));
	i = leng;
	j = ft_strlen(txt);
	while (i > 0)
	{
		while (j > 0)
		{
			i--;
			j--;
			temp[i] = txt[j];
		}
		i--;
		temp[i] = fill;
	}
	temp[i] = fill;
	free(txt);
	return (temp);
}

char	*ft_fill_right(char *txt, char fill, size_t leng)
{
	char	*temp;
	size_t	i;

	if (!(ft_strlen(txt) < leng))
		return (txt);
	temp = ft_calloc(leng + 1, sizeof(char));
	i = 0;
	while (i < leng)
	{
		while (i < ft_strlen(txt))
		{
			temp[i] = txt[i];
			i++;
		}
		temp[i] = fill;
		i++;
	}
	free(txt);
	return (temp);
}
