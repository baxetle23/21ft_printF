#include "../libft/libft.h"
#include "../includes/printf.h"

void	check_precision(t_flags *flags, va_list arg)
{
	(*flags->pointer)++;
	if (**flags->pointer == '*')
	{
		flags->precision = va_arg(arg, int);
		check_negative_precision(flags);
		while (**flags->pointer == '*')
			(*flags->pointer)++;
	}
	else
	{
		flags->precision = ft_atoi(*(flags->pointer));
		check_negative_precision(flags);
		while (ft_isdigit(**flags->pointer))
			(*flags->pointer)++;
	}
}

void	check_width(t_flags *flags, va_list arg)
{
	if (**flags->pointer == '*')
	{
		flags->width = va_arg(arg, int);
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->minus = '-';
			flags->space = ' ';
		}
		while (**flags->pointer == '*')
			(*flags->pointer)++;
	}
	else
	{
		flags->width = ft_atoi(*(flags->pointer));
		if (flags->width < 0)
			flags->width = 0;
		while (ft_isdigit(**flags->pointer))
			(*flags->pointer)++;
	}
}

void	check_second_flag(t_flags *flags)
{
	flags->minus = '-';
	while (**flags->pointer == '-' || **flags->pointer == '0' )
		(*flags->pointer)++;
}

void	check_first_flag(t_flags *flags)
{
	if (**flags->pointer == '-')
	{
		flags->minus = '-';
		while (**flags->pointer == '-')
			(*flags->pointer)++;
	}
	else
	{
		flags->space = '0';
		while (**flags->pointer == '0')
			(*flags->pointer)++;
	}
}

int	parcer(va_list arg, const char **c)
{
	t_flags	flags;

	(*c)++;
	initzilization(&flags);
	flags.pointer = (char **)c;
	if (**c == '\0')
		return (0);
	if (**c == '-' || **c == '0')
		check_first_flag(&flags);
	if (**c == '-' || **c == '0')
		check_second_flag(&flags);
	if (**c == '*' || ft_isdigit(**c))
		check_width(&flags, arg);
	if (**c == '.')
		check_precision(&flags, arg);
	while (!isspecificator(**c))
		(*c)++;
	return (display(&flags, arg));
}
