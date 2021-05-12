#include "../libft/libft.h"
#include "../includes/printf.h"

int	string_print_noprec(t_flags *flags, char *string, int len_str, char null)
{
	int	i;

	i = 0;
	if (flags->width > len_str)
	{
		if (flags->minus)
		{
			ft_putstr_fd(string, 1);
			while (flags->width - i++ > len_str)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (flags->width - i++ > len_str)
				ft_putchar_fd(flags->space, 1);
			ft_putstr_fd(string, 1);
		}
		if (null)
			free(string);
		return (flags->width);
	}
	ft_putstr_fd(string, 1);
	if (null)
		free(string);
	return (len_str);
}

int	string_print_prec(t_flags *flags, char *string, char null)
{
	int	i;

	i = 0;
	if (flags->width && flags->width > flags->precision)
	{
		if (flags->minus)
		{
			write(1, string, flags->precision);
			while (flags->width - i++ > flags->precision)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (flags->width - i++ > flags->precision)
				ft_putchar_fd(' ', 1);
			write(1, string, flags->precision);
		}
		if (null)
			free(string);
		return (flags->width);
	}
	write(1, string, flags->precision);
	if (null)
		free(string);
	return (flags->precision);
}

int	display_string( t_flags *flags, va_list arg)
{
	char	*string;
	char	null;
	int		len_str;

	null = 0;
	string = va_arg(arg, char *);
	if (!string)
	{
		null = 1;
		string = ft_strdup("(null)");
		if (!string)
			return (-1);
	}
	len_str = ft_strlen(string);
	if (flags->precision == -1)
		return (string_print_noprec(flags, string, len_str, null));
	if (flags->precision > -1 && flags->precision > len_str)
		flags->precision = len_str;
	if (flags->precision > -1)
		return (string_print_prec(flags, string, null));
	return (-1);
}
