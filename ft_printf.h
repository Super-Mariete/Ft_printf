/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:07:28 by made-ped          #+#    #+#             */
/*   Updated: 2024/10/31 01:27:45 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_print_hex_max(unsigned long long num);
int		ft_print_hex(unsigned long long num);
int		ft_comprobar(char c, va_list *argumentos);
int		ft_string(char *string);
int		ft_unsigned_number(unsigned int n);
int		ft_number(int n);
int		ft_printf(const char *sring, ...);
int		ft_print_p(void *ptr);

void	ft_write(char c);

#endif
