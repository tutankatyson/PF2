/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:39:34 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/07 01:17:54 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

char	*ft_makestr(int fill, int precision, int aling, char *str)
{
	char	*txt;


	if (precision && precision < ft_strlen(str))
		txt = ft_substr(str, 0, precision);


	



}