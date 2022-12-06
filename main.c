

#include "ft_printf.h"

int main()
{
	int i, j;
	char *ptr = "holas";

	i	=	ft_printf("\n 1%%%c",'X');
	j	=      printf("\n 1%%%c",'X');

	ptr = 0;
	if(i != j)
		printf(RED"\nERROR DE DESAJUSTE EN EL RETURN (%i,%i)"RESET,i,j);
	else
		printf(GREEN"\n-- - - >  T E S T   O K  < - - --"RESET);
}
