/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:05:53 by made-ped          #+#    #+#             */
/*   Updated: 2024/11/12 02:29:14 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		return (ft_string(va_arg(*argumentos, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_number(va_arg(*argumentos, int)));
	else if (c == 'p')
		return (ft_print_p(va_arg(*argumentos, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(*argumentos,unsigned int)));
	else if (c == 'X')
		return (ft_print_hex_max(va_arg(*argumentos,unsigned int)));
	else if (c == 'u')
		return (ft_unsigned_number(va_arg(*argumentos, unsigned int)));
	return (0);
}
