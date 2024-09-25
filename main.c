/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:12:11 by made-ped          #+#    #+#             */
/*   Updated: 2024/09/26 00:48:33 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main (void)
{
	int i;
	int j;
	char letra;
	void	*ptr;
	int	numero;
	char	*str;

	letra = 'A';
	numero = 4234;
	str = "HOLA MUNDO";
	ptr = &numero;
	i = ft_printf("%c\n", letra);
	j = printf ("%c\n", letra);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("Hola\n");
	j = printf ("Hola\n");
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf("%%\n");
	j = printf("%%\n");
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%s\n", str);
	j = printf ("%s\n", str);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%d\n", numero);
	j = printf ("%d\n", numero);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%i\n", numero);
	j = printf ("%i\n", numero);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf("%% %c %s\n", letra, str);
	j = printf("%% %c %s\n", letra, str);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%p\n", ptr);
	j = printf ("%p\n", ptr);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);	
	i = ft_printf ("%x\n", numero);
	j = printf ("%x\n", numero);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%X\n", numero);
	j = printf ("%X\n", numero);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	return (0);
}
