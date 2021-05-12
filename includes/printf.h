#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int			minus;
	int			width;
	int			precision;
	int			space;
	long long	number;
	char		type;
	char		**pointer;
}	t_flags;

int				ft_printf(const char *c, ...);
int				parcer(va_list va, const char **c);
int				display(t_flags *flags, va_list va);

int				display_string(t_flags *flags, va_list va);

int				get_size_decimal(long long a);
int				display_decimal(t_flags *flags, va_list va);
void			decimal_print_nom(int first, int second, char c, long long nu);
void			decimal_print_m(int first, int second, char c, long long nu);
int				display_decimal_p_w(t_flags *flags, long long number, int len);
int				display_decimal_p(t_flags *flags, long long number, int len);

int				display_udecimal(t_flags *flags, va_list va);

int				display_hexa(t_flags *flags, va_list va, char size);
int				display_hexa_p(t_flags *flags, int len);
void			hexa_print_m(int first, int second, char c, t_flags *flags);
void			hexa_print_nom(int first, int second, char c, t_flags *flags);
void			ft_puthex_fd(long long number, int fd, char size);
int				get_size_hexa(long long number);

int				display_pointer(t_flags *flags, va_list va);
void			pointer_print_minus(t_flags *f, int l, long long n, char sp);
void			pointer_print_nominus(t_flags *f, int l, long long n, char sp);
int				pointer_precision(int	len, long long number, t_flags *flags);
int				get_size_pointer(long long number);

void			check_negative_precision(t_flags *flags);
int				isspecificator(int c);
void			initzilization(t_flags *flags);
int				max(int a, int b);
#endif
