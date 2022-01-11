/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:09:57 by bokim             #+#    #+#             */
/*   Updated: 2021/07/08 02:08:19 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
# define FLAG "-0"
# define DIGIT "0123456789*"
# define TYPE "cspdiuxX%"
# define DEC 10
# define HEX 16
# define FD 1
# define U 0
# define SMALLX 1
# define BIGX 2

typedef struct s_opt
{
	int		index;
	int		left;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		type;
}				t_opt;

int		ft_printf(const char *input, ...);
int		ft_putchar(char s);
void	ft_putspace(int size);
void	ft_putzero(int size);
void	ft_put_int(int n);
void	ft_put_uint(unsigned int n, int base, int conversion);

/* parsing */
int		ft_parse_flag(char c, t_opt *option);
int		ft_parse_digit(char c, t_opt *option, va_list ap);
int		ft_parse_type(char c, t_opt *option);
int		ft_parse(char *input, t_opt *option, va_list ap);

/* conversion */
int		ft_conversion(int c, t_opt *option, va_list ap);
int		ft_get_numsize(int n, int base);
int		ft_get_lnumsize(unsigned int n, int base);
void	ft_putl_left(t_opt *option, unsigned int n, int num_size, int base);
void	ft_putl_right(t_opt *option, unsigned int n, int num_size, int base);
int		ft_convert_char(char c, t_opt *option);
int		ft_convert_str(char *str, t_opt *option);
int		ft_convert_int(int n, t_opt *option);
int		ft_convert_percent(t_opt *option);
int		ft_convert_unsigned(unsigned int n, t_opt *option);
int		ft_convert_hex(unsigned int n, t_opt *option, int conversion);
int		ft_convert_ptr(void *ptr, t_opt *option);

#endif
