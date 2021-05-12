#include "../includes/printf.h"
#include "../libft/libft.h"

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		result;

	result = 0;
	va_start(arg, string);
	while (*string)
	{
		if (*string != '%')
		{
			ft_putchar_fd(*string, 1);
			result++;
		}
		else
		{
			result += parcer(arg, &string);
			if (result == -1)
				return (-1);
		}		
		if (*string)
			string++;
	}
	va_end(arg);
	return (result);
}
