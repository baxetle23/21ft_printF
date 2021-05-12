#include "../libft/libft.h"
#include "../includes/printf.h"

int	display_percent(t_flags *flags)
{
	int	i;

	i = 0;
	if (!flags->width)
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (flags->minus)
	{
		ft_putchar_fd('%', 1);
		while (flags->width - i++ > 1)
			ft_putchar_fd(flags->space, 1);
		return (flags->width);
	}
	while (flags->width - i++ > 1)
		ft_putchar_fd(flags->space, 1);
	ft_putchar_fd('%', 1);
	return (flags->width);
}

int	display_char(t_flags *flags, va_list arg)
{
	int	i;

	i = 0;
	if (flags->width > 1)
	{
		if (flags->minus)
		{
			ft_putchar_fd(va_arg(arg, int), 1);
			while (flags->width - i++ != 1)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (flags->width - i++ != 1)
				ft_putchar_fd(' ', 1);
			ft_putchar_fd(va_arg(arg, int), 1);
		}
		return (flags->width);
	}	
	else
		ft_putchar_fd(va_arg(arg, int), 1);
	return (1);
}

int	display(t_flags *flags, va_list arg)
{
	if (**(flags->pointer) == 'c')
		return (display_char(flags, arg));
	if (**(flags->pointer) == 'd' || **(flags->pointer) == 'i')
		return (display_decimal(flags, arg));
	if (**(flags->pointer) == 's')
		return (display_string(flags, arg));
	if (**(flags->pointer) == 'u')
		return (display_udecimal(flags, arg));
	if (**(flags->pointer) == 'x')
		return (display_hexa(flags, arg, 'x'));
	if (**(flags->pointer) == 'X')
		return (display_hexa(flags, arg, 'X'));
	if (**(flags->pointer) == 'p')
		return (display_pointer(flags, arg));
	if (**(flags->pointer) == '%')
		return (display_percent(flags));
	return (0);
}
