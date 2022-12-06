/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:18:48 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/06 23:56:25 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/** * * * * * * * * *    I N C L U D E S    * * * * * * * * * **/

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

/** * * * * * * * * *    p r i n t f . c   * * * * * * * * * **/

int		ft_printf(char const *txt, ...);

/** * * * * * * * * *    m a g i c . c    * * * * * * * * * **/

int		ft_magicselec(char **txt, va_list ap);
int		ft_magic_string(char **txt, char *arg);
int		ft_magic_signed(char **txt, int arg);
int		ft_magic_unsigned(char **txt, unsigned long arg);
int		ft_magic_pointer(char **txt, unsigned long arg);
int		ft_magic_char(char **txt, unsigned long arg);
int		ft_magic_hexa(char **txt, unsigned long arg);

/** * * * * * * * * *    p r i n t t o o l s . c    * * * * * * * * * **/

int		ft_spellcounter(char *str);
int		ft_checkendchar(char c);
int		ft_findendchar(char *txt);
int		ft_go_writing(char **txt);

#endif