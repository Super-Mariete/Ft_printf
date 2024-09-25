/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:05:53 by made-ped          #+#    #+#             */
/*   Updated: 2024/09/26 01:13:36 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_HEX(unsigned long num)
{
	int	length;

	length = 0;
	if (num >= 16)
		length += ft_print_hex(num / 16);
	ft_write ("0123456789ABCDEF"[num % 16]);
	length++;
	return (length);
}

int	ft_print_hex(unsigned long num)
{
	int	length;

	length = 0;
	if (num >= 16)
		length += ft_print_hex(num / 16);
	ft_write ("0123456789abcdef"[num % 16]);
	length++;
	return (length);
}

int	ft_print_p(void *ptr)
{
	int length;
	unsigned long direccion;

	length = 2;
	direccion = (unsigned long)ptr;
	ft_write ('0');
	ft_write ('x');
	length += ft_print_hex(direccion);
	return (length);
}

int	ft_number(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		ft_string("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_write('-');
		length++;
		n = -n;
	}
	if (n > 9)
		length += ft_number (n / 10);
	ft_write ("0123456789"[n % 10]);
	length++;
	return (length);
}

int	ft_string(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		ft_write(string[i]);
		i++;
	}
	return (i);
}

int	ft_printf(const char *string, ...)
{
	va_list	argumentos;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(argumentos, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			length += ft_comprobar(string[i], &argumentos);
			i++;
		}
		else
		{
			ft_write(string[i]);
			length++;
			i++;
		}
	}
	va_end (argumentos);
	return (length);
}

int	ft_comprobar(char c, va_list *argumentos)
{
	if (c == '%')
	{
		ft_write (c);
		return (1);
	}
	else if (c == 'c')
	{
		ft_write (va_arg(*argumentos, int));
		return (1);
	}
	else if (c == 's')
	{
		return (ft_string(va_arg(*argumentos, char *)));
	}
	else if (c == 'd' || c == 'i')
	{
		return (ft_number(va_arg(*argumentos, int)));
	}
	else if (c =='p')
	{
		return (ft_print_p(va_arg(*argumentos, void *)));
	}
	else if ( c == 'x')
	{
		return (ft_print_hex(va_arg(*argumentos, unsigned long)));
	}
	else if ( c == 'X')
	{
		return (ft_print_HEX(va_arg(*argumentos, unsigned long)));
	}
/*	else if (c == 'i')
	{
		return (ft_string("Me queda por terminar"));
	}*/
	return (0);
}

void	ft_write(char c)
{
	write (1, &c, 1);
}
