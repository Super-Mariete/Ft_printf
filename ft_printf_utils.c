/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:50:17 by made-ped          #+#    #+#             */
/*   Updated: 2024/11/12 02:31:14 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *string)
{
	int	i;

	if (!string)
	{
		write (1, "(nil)", 5);
		return (6);
	}	
	i = 0;
	while (string[i])
	{
		ft_write(string[i]);
		i++;
	}
	return (i);
}

int	ft_print_p(unsigned int ptr)
{
	int		len;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 2;
	ft_write ('0');
	ft_write ('x');
	len += ft_print_hex(ptr);
	return (len);
}

void	ft_write(char c)
{
	write (1, &c, 1);
}
