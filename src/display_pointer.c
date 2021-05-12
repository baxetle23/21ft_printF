#include "../libft/libft.h"
#include "../includes/printf.h"

void	ft_printadress(long long number)
{
	int		i;
	char	buffer[64];

	i = 0;
	if (number == 0)
	{
		write (1, "0x0", 3);
		return ;
	}
	write(1, "0x", 2);
	while (number)
	{
		if (number % 16 < 10)
			buffer[i++] = 48 + number % 16;
		else
			buffer[i++] = 87 + number % 16;
		number /= 16;
	}
	while (i - 1 >= 0)
		write (1, &buffer[i-- - 1], 1);
}

void	pointer_print_nominus(t_flags *flags, int len, long long numb, char sp)
{
	int	i;

	i = 0;
	while (flags->width - i++ > len)
		ft_putchar_fd(sp, 1);
	ft_printadress(numb);
}

void	pointer_print_minus(t_flags *flags, int len, long long numb, char sp)
{
	int	i;

	i = 0;
	ft_printadress(numb);
	while (flags->width - i++ > len)
		ft_putchar_fd(sp, 1);
}

int	pointer_noprecision(int	len, long long number, t_flags *flags)
{
	if (flags->width > len)
	{
		if (!flags->minus)
			pointer_print_nominus(flags, len, number, flags->space);
		else
			pointer_print_minus(flags, len, number, flags->space);
		return (flags->width);
	}
	ft_printadress(number);
	return (len);
}

int	display_pointer(t_flags *flags, va_list arg)
{
	long long	n;

	n = va_arg(arg, long long);
	if (flags->precision > -1)
		return (pointer_precision(get_size_pointer(n), n, flags));
	if (flags->precision == -1)
		return (pointer_noprecision(get_size_pointer(n), n, flags));
	return (-1);
}
