#include "../libft/libft.h"
#include "../includes/printf.h"

int	kostil(t_flags *flags, long long number, int len)
{
	int		i;
	char	buffer[64];

	i = 0;
	write(1, "0x", 2);
	while (flags->precision - i++ > len - 2)
		ft_putchar_fd('0', 1);
	i = 0;
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
	return (flags->precision + 2);
}

int	zero_pointer(t_flags *flags)
{
	int	i;

	i = 0;
	if (!flags->precision)
	{
		write(1, "0x", 2);
		return (2);
	}
	write(1, "0x0", 3);
	while (flags->precision - i++ > 1)
		ft_putchar_fd('0', 1);
	return (flags->precision + 2);
}

int	pointer_precision_large_len(int	len, long long number, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->minus)
	{
		pointer_print_nominus(flags, len, number, '0');
		while (flags->width - i++ > flags->precision)
			ft_putchar_fd(flags->space, 1);
		return (flags->width);
	}
	while (flags->width - i++ > flags->precision)
		ft_putchar_fd(flags->space, 1);
	pointer_print_nominus(flags, len, number, '0');
	return (flags->width);
}

int	pointer_precision_width(int	len, long long number, t_flags *flags)
{
	if (flags->width > flags->precision)
	{
		if (flags->precision > len)
			return (pointer_precision_large_len(number, len, flags));
		if (!flags->minus)
		{
			pointer_print_nominus(flags, len, number, ' ');
			return (flags->width);
		}
		pointer_print_minus(flags, len, number, ' ');
		return (flags->width);
	}
	if (flags->width < len && flags->precision > len)
		return (kostil(flags, number, len));
	pointer_print_nominus(flags, len, number, '0');
	return (flags->precision);
}

int	pointer_precision(int	len, long long number, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->width)
	{
		if (!number && flags->precision <= 0)
		{
			while (flags->width - i++ > 2)
				ft_putchar_fd(' ', 1);
			write(1, "0x", 2);
			return (flags->width);
		}
		return (pointer_precision_width(len, number, flags));
	}
	if (!number)
		return (zero_pointer(flags));
	pointer_print_nominus(flags, len, number, '0');
	if (flags->precision > len)
		return (flags->precision);
	return (len);
}
