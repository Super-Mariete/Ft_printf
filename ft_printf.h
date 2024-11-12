/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:07:28 by made-ped          #+#    #+#             */
/*   Updated: 2024/11/12 02:32:12 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_print_hex_max(unsigned int num);
int		ft_print_hex(unsigned int num);
int		ft_comprobar(char c, va_list *argumentos);
int		ft_string(char *string);
int		ft_unsigned_number(unsigned int n);
int		ft_number(int n);
int		ft_printf(const char *sring, ...);
int		ft_print_p(unsigned int ptr);

void	ft_write(char c);

#endif
