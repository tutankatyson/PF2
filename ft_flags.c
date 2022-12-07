/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:16:20 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/07 00:45:30 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_fill(char *txt)		//Return the nunmber behind point or 0 if doesnt exist
{
	int i = 1;

	while (!ft_isdigit(txt[i]) || txt[i] == ' ' || txt[i] == '+'
			|| txt[i] == '-' || txt[i] == '#')
	{
		if (txt[i] == '\0' || txt[i] == '.')
			return (0);
		i++;
	}

	i = ft_atoi(txt + i);

	return (i);
}

int ft_precision(char *txt)	//Return the number after point or 0 if doesnt exist
{
	int i = 1;

	while (txt[i] != '.')
	{
		if (txt[i] == '\0')
			return (0);
		i++;
	}
	i = ft_atoi(txt + i + 1);
	return (i);
}

int	ft_alignment(char *txt)	//Return 1 if there is a '-' or 0 if isnt
{
	int i = 0;
	while (txt[i] == '-' || txt[i] == ' ' || txt[i] == '+')
	{
		if (txt[i] == '-')
			return (1);
		i++;
	}
	return (0);
}