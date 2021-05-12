#include "../libft/libft.h"
#include "../includes/printf.h"

void	decimal_print_m(int first, int second, char c, long long number)
{
	ft_putnbr_fd(number, 1);
	while (first-- > second)
		ft_putchar_fd(c, 1);
}

void	decimal_print_nom(int first, int second, char c, long long number)
{
	while (first-- > second)
		ft_putchar_fd(c, 1);
	ft_putnbr_fd(number, 1);
}

int	display_decimal_p_now(long long number, int prec, int len)
{
	if (number == 0 && prec == 0)
		return (0);
	decimal_print_nom(prec, len, '0', number);
	if (prec > len)
		return (prec);
	return (len);
}

int	display_decimal_p(t_flags *flags, long long number, int len)
{
	int	i;

	i = 0;
	if (flags->width)
	{
		if (number == 0 && flags->precision <= 0)
		{
			while (flags->width - i++ > 0)
				ft_putchar_fd(' ', 1);
			return (flags->width);
		}
		return (display_decimal_p_w(flags, number, len));
	}
	if (number >= 0)
		return (display_decimal_p_now(number, flags->precision, len));
	ft_putchar_fd('-', 1);
	decimal_print_nom(flags->precision + 1, len, '0', -number);
	return (max(flags->precision + 1, len));
}
