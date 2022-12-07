

#include "ft_printf_bonus.h"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int main()
{
	int i, j;
	char *ptr = "holas";

	i	=	ft_printf("\n %30.3s", NULL);
	j	=      printf("\n %30.3s", NULL);

	ptr = 0;
	if(i != j)
		printf(RED"\nERROR DE DESAJUSTE EN EL RETURN (%i,%i)"RESET,i,j);
	else
		printf(GREEN"\n-- - - >  T E S T   O K  < - - --"RESET);
}
