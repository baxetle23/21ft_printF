#include "../libft/libft.h"
#include "../includes/printf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	initzilization(t_flags *flags)
{
	flags->minus = 0;
	flags->precision = -1;
	flags->space = ' ';
	flags->width = 0;
	flags->number = 0;
	flags->type = 0;
	flags->pointer = NULL;
}

int	isspecificator(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	check_negative_precision(t_flags *flags)
{
	if (flags->precision < 0)
		flags->precision = -1;
	else if (flags->space == '0')
		(flags->space = ' ');
}
