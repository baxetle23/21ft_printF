#include "../libft/libft.h"
#include "../includes/printf.h"

int	display_decimal_nop_nom(t_flags *flags, int len, long long number)
{
	if (flags->space == '0')
	{
		ft_putchar_fd('-', 1);
		number *= -1;
	}
	decimal_print_nom(flags->width, len, flags->space, number);
	return (flags->width);
}

int	display_decimal_nop(t_flags *flags, long long number, int len)
{
	if (flags->width && flags->width > len)
	{
		if (number >= 0)
		{
			if (!flags->minus)
				decimal_print_nom(flags->width, len, flags->space, number);
			else
				decimal_print_m(flags->width, len, flags->space, number);
			return (flags->width);
		}
		if (!flags->minus)
			return (display_decimal_nop_nom(flags, len, number));
		decimal_print_m(flags->width, len, flags->space, number);
		return (flags->width);
	}
	ft_putnbr_fd(number, 1);
	return (len);
}

int	display_decimal(t_flags *flags, va_list va)
{
	long long	number;

	number = va_arg(va, int);
	if (flags->precision >= 0)
		return (display_decimal_p(flags, number, get_size_decimal(number)));
	if (flags->precision == -1)
		return (display_decimal_nop(flags, number, get_size_decimal(number)));
	return (-1);
}

int	display_udecimal(t_flags *flags, va_list va)
{
	unsigned int	nbr;
	long long		number;

	nbr = va_arg(va, unsigned int);
	number = nbr;
	if (flags->precision >= 0)
		return (display_decimal_p(flags, number, get_size_decimal(number)));
	if (flags->precision == -1)
		return (display_decimal_nop(flags, number, get_size_decimal(number)));
	return (-1);
}
