#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

#include "ft_printf.h"


# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"


char	*ft_makestr(size_t fill, size_t preciosion, int aling, char *str);
char	*ft_fill_right(char *txt, char fill, size_t leng);
char	*ft_fill_left(char *txt, char fill, size_t leng);

int		ft_fill(char *txt);
int		ft_precision(char *txt);
int		ft_alignment(char *txt);



int		ft_blackmagicselec(char **txt, va_list ap);
int		ft_blackmagic_string(char **txt, char *arg);
int		ft_blackmagic_signed(char **txt, int arg);
int		ft_blackmagic_unsigned(char **txt, unsigned long arg);
int		ft_blackmagic_pointer(char **txt, unsigned long arg);


#endif