#include "libft/libft.h"
#include "lib.h"

void	printch(int quant, char ch)
{
	int		i;

	i = 0;
	while (i < quant)
	{
		write(1, &ch, 1);
		i++;
	}	
}
