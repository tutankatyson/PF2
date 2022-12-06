/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:18:48 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/05 16:26:28 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
#define FT_PRINTF_H

/** * * * * * * * * *    I N C L U D E S    * * * * * * * * * **/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
 

/** * * * * * * * * *    p r i n t f . c   * * * * * * * * * **/

int		ft_printf(char const *txt, ...);

/** * * * * * * * * *    m a g i c . c    * * * * * * * * * **/

int 	ft_magicselec(char **txt, va_list ap);
int		ft_magic_string(char **txt, char *arg);
int		ft_magic_signed(char **txt, int arg);
int		ft_magic_unsigned(char **txt, unsigned long arg);
char	*ft_get_str(char *arg, int fill, int precision, int alignment);

/** * * * * * * * * *    f l a g s . c    * * * * * * * * * **/

int		ft_precision(char *txt);
int		ft_arg_type(char txt);
int		ft_fill(char *txt);
int		ft_alignment(char *txt);

/** * * * * * *     p r i n t t o o l s . c    * * * * * * * **/

int	ft_spellcounter(char *txt);
int	ft_checkendchar(char c);
int ft_findendchar(char *txt);
int	ft_go_writing(char **txt);

# endif