#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

#include "ft_printf.h"

char *ft_makestr(int fill, int preciosion, int aling, char *str);

int	ft_fill(char *txt);
int	ft_precision(char *txt);
int	ft_alignment(char *txt);



int	ft_blackmagicselec(char **txt, va_list ap);
int	ft_blackmagic_string(char **txt, char *arg);
int	ft_blackmagic_signed(char **txt, int arg);
int	ft_blackmagic_unsigned(char **txt, unsigned long arg);
int	ft_blackmagic_pointer(char **txt, unsigned long arg);


#endif