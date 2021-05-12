#include "../libft/libft.h"
#include "../includes/printf.h"

int	display_hexa_p_w_len(t_flags *flags, int len)
{
	int	i;

	i = 0;
	if (!flags->minus)
	{
		while (flags->width - i++ > flags->precision)
			ft_putchar_fd(flags->space, 1);
		hexa_print_nom(flags->precision, len, '0', flags);
		return (flags->width);
	}
	hexa_print_nom(flags->precision, len, '0', flags);
	while (flags->width - i++ > flags->precision)
		ft_putchar_fd(flags->space, 1);
	return (flags->width);
}

int	display_hexa_p_w(t_flags *flags, int len)
{
	if (flags->width > flags->precision)
	{				
		if (flags->precision >= len)
			return (display_hexa_p_w_len(flags, len));
		if (!flags->minus)
			hexa_print_nom(flags->width, len, ' ', flags);
		else
			hexa_print_m(flags->width, len, ' ', flags);
		return (max(flags->width, len));
	}
	hexa_print_nom(flags->precision, len, '0', flags);
	return (max(flags->precision, len));
}

int	display_hexa_p(t_flags *flags, int len)
{
	int	i;

	i = 0;
	if (flags->width)
	{
		if (!flags->number && flags->precision <= 0)
		{
			while (flags->width - i++ > 0)
				ft_putchar_fd(' ', 1);
			return (flags->width);
		}
		return (display_hexa_p_w(flags, len));
	}
	if (!flags->number && !flags->precision)
		return (0);
	hexa_print_nom(flags->precision, len, '0', flags);
	if (flags->precision > len)
		return (flags->precision);
	return (len);
}
