#include "../libft/libft.h"
#include "../includes/printf.h"

void	ft_puthex_fd(long long number, int fd, char size)
{
	int				j;
	char			buffer[16];

	j = 0;
	if (!number)
		ft_putchar_fd('0', 1);
	while (number)
	{
		if (number % 16 < 10)
			buffer[j++] = 48 + number % 16;
		else
			buffer[j++] = size - 33 + number % 16;
		number /= 16;
	}
	while (j - 1 >= 0)
		write(fd, &buffer[j-- - 1], 1);
}

void	hexa_print_m(int first, int second, char c, t_flags *flags)
{
	ft_puthex_fd(flags->number, 1, flags->type);
	while (first-- > second)
		ft_putchar_fd(c, 1);
}

void	hexa_print_nom(int first, int second, char c, t_flags *flags)
{
	while (first-- > second)
		ft_putchar_fd(c, 1);
	ft_puthex_fd(flags->number, 1, flags->type);
}

int	display_hexa_nop(t_flags *flags, int len)
{
	if (flags->width && flags->width > len)
	{
		if (!flags->minus)
			hexa_print_nom(flags->width, len, flags->space, flags);
		else
			hexa_print_m(flags->width, len, flags->space, flags);
		return (flags->width);
	}
	ft_puthex_fd(flags->number, 1, flags->type);
	return (len);
}

int	display_hexa(t_flags *flags, va_list va, char size)
{
	flags->number = va_arg(va, unsigned int);
	flags->type = size;
	if (flags->type == 'X')
	{
		if (flags->precision >= 0)
			return (display_hexa_p(flags, get_size_hexa(flags->number)));
		if (flags->precision == -1)
			return (display_hexa_nop(flags, get_size_hexa(flags->number)));
		return (-1);
	}
	if (flags->precision >= 0)
		return (display_hexa_p(flags, get_size_hexa(flags->number)));
	if (flags->precision == -1)
		return (display_hexa_nop(flags, get_size_hexa(flags->number)));
	return (-1);
}
