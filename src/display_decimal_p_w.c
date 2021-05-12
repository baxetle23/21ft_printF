#include "../libft/libft.h"
#include "../includes/printf.h"

int	version4(t_flags *flags, long long number, int len)
{
	if (!number && flags->precision == -1)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_putchar_fd('-', 1);
	decimal_print_nom(flags->precision + 1, len, '0', -number);
	return (max(flags->precision + 1, len));
}

int	version3(t_flags *flags, int len, long long number)
{
	int	i;

	i = 0;
	ft_putchar_fd('-', 1);
	decimal_print_nom(flags->precision + 1, len, '0', -number);
	while (flags->width - i++ > flags->precision + 1)
		ft_putchar_fd(flags->space, 1);
	return (flags->width);
}

int	version2(t_flags *flags, int len, long long number)
{
	int	i;

	i = 0;
	while (flags->width - i++ > flags->precision + 1)
		ft_putchar_fd(flags->space, 1);
	ft_putchar_fd('-', 1);
	decimal_print_nom(flags->precision + 1, len, '0', -number);
	return (flags->width);
}

int	version1(t_flags *flags, int len, long long number)
{
	int	i;

	i = 0;
	if (!flags->minus)
	{
		while (flags->width - i++ > flags->precision)
			ft_putchar_fd(flags->space, 1);
		decimal_print_nom(flags->precision, len, '0', number);
		return (flags->width);
	}
	decimal_print_nom(flags->precision, len, '0', number);
	while (flags->width - i++ > flags->precision)
		ft_putchar_fd(flags->space, 1);
	return (flags->width);
}

int	display_decimal_p_w(t_flags *flags, long long number, int len)
{
	if (flags->width > flags->precision)
	{				
		if (flags->precision >= len)
		{
			if (number >= 0)
				return (version1(flags, len, number));
			if (!flags->minus)
				return (version2(flags, len, number));
			return (version3(flags, len, number));
		}
		if (!flags->minus)
			decimal_print_nom(flags->width, len, ' ', number);
		else
			decimal_print_m(flags->width, len, ' ', number);
		return (max(flags->width, len));
	}
	if (number >= 0)
	{
		decimal_print_nom(flags->precision, len, '0', number);
		return (max(flags->precision, len));
	}
	return (version4(flags, number, len));
}
