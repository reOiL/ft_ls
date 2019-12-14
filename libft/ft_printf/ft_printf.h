/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:42:23 by jwebber           #+#    #+#             */
/*   Updated: 2019/12/12 17:59:52 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

# define FLAG_ZERO 0x2
# define FLAG_SHARP 0x4
# define FLAG_PLUS 0x8
# define FLAG_MINUS 0x10
# define FLAG_SPACE 0x20

# define MOD_L 0x2
# define MOD_LL 0x4
# define MOD_H 0x8
# define MOD_HH 0x10
# define MOD_LD 0x20

# define MIN_LONG -2147483648
# define MIN_LLONG 9223372036854775807

typedef union			u_integers
{
	long long			ll;
	unsigned long long	ull;
}						t_integers;

typedef struct			s_format
{
	unsigned int		flags;
	int					width;
	int					precision;
	int					modifier;
	char				type;
}						t_format;

int						print_percent(t_format format);
int						print_minus_string(t_format format, char *str,
											long long length);
int						ft_putchar_one(char c);
int						print_char(t_format format, va_list args);
int						print_string(t_format format, va_list args);
long long				ft_max(long long a, long long b);
char					*get_addr_precision(char *num, int precision);
int						ft_putstr_size(char *str, int precision);
int						print_address(t_format format, va_list args);
int						calc_len(long long val, int base);
char					cast_base(unsigned short val);
void					itoa_2(char **array, long long val, int base,
								long long index);
char					*ft_itoa_base(long long ll, int base);
int						calc_len_uns(unsigned long long val, int base);
void					itoa_2_uns(char **array, unsigned long long val,
									int base, long long index);
char					*ft_itoa_base_uns(unsigned long long ull, int base);
int						is_neg(long long val);
int						print_sign(t_integers *data, t_format *format);
int						count_digits(long long value, int base);
int						count_digits_uns(unsigned long long value, int base);
int						put_nbr_base(t_format format, t_integers val, int base,
										int uns_sign);
int						check_zero_number(t_format format, t_integers val);
int						get_intflag(t_format format, t_integers data);
int						get_intwidth(t_format format, t_integers data);
int						big_int_condition(t_format *format, t_integers *data);
int						get_unswidth(t_format format, t_integers data);
int						print_x(t_format format, t_integers data);
char					*ft_tolower_str(char *str);
int						print_reverse_uns(t_integers data, t_format format,
											int count, int base);
int						print_modified_uns(t_integers data, t_format format,
											int base);
int						print_int_unsigned(t_format format, va_list args);
int						print_reverse_int(t_integers data, t_format format,
											int count);
int						print_modified_int(t_integers data, t_format format);
int						print_int(t_format format, va_list args);
unsigned int			get_flags(const char *str, int *it);
int						get_width(const char *str, int *i, va_list args,
									t_format *format);
int						get_precision(const char *str, int *i, va_list args);
int						get_modifier(const char *str, int *i);
char					get_type(const char *str);
int						print_value(t_format format, va_list args);
int						get_format(va_list args, const char *str,
									int *printed_count);
int						ft_printf(const char *format, ...);
int						print_float(t_format format, va_list args);
size_t					putchar_count(char c, size_t count);
size_t					colored(const char *str);

#endif
