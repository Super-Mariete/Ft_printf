/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:08:36 by made-ped          #+#    #+#             */
/*   Updated: 2024/11/12 01:45:22 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_max(unsigned int num)
{
	int	length;

	length = 0;
	if (num >= 16)
		length += ft_print_hex_max(num / 16);
	ft_write ("0123456789ABCDEF"[num % 16]);
	length++;
	return (length);
}

int	ft_print_hex(unsigned int num)
{
	int	length;

	length = 0;
	if (num >= 16)
		length += ft_print_hex(num / 16);
	ft_write ("0123456789abcdef"[num % 16]);
	length++;
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

int	ft_unsigned_number(unsigned int n)
{
	int	length;

	length = 0;
	if (n > 9)
		length += ft_unsigned_number (n / 10);
	ft_write ("0123456789"[n % 10]);
	length++;
	return (length);
}
