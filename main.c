/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:12:11 by made-ped          #+#    #+#             */
/*   Updated: 2024/10/30 22:40:42 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main (void)
{
	int i;
	int j;
	char letra;
	void	*ptr;
	void	*ptr_null;
	int	numero;
	int	cero;
	unsigned int numero_alto;
	char	*str;
	char *cadena_vacia;

	letra = 'A';
	numero = 4234;
	cero = 0;
	numero_alto = 4294967295;
	str = "HOLA MUNDO";
	cadena_vacia = "";
	ptr = &numero;
	ptr_null = NULL;
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
	i = ft_printf ("%p\n", ptr_null);
	j = printf ("%p\n", ptr_null);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);	
	i = ft_printf ("%x\n", numero);
	j = printf ("%x\n", numero);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%u\n", numero_alto);
	j = printf ("%u\n", numero_alto);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%X\n", numero);
	j = printf ("%X\n", numero);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%c ,%s ,%d ,%% ,%p ,%u\n", letra, str, numero, ptr, numero_alto);
	j = printf ("%c ,%s ,%d ,%% ,%p ,%u\n", letra, str, numero, ptr, numero_alto);
 	printf ("ft_printf = %d\nprintf = %d\n", i, j);
//	i = ft_printf ("");
//	j = printf ("");
//	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%s", cadena_vacia);
	j = printf ("%s", cadena_vacia);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%x\n", cero);
	j = printf ("%x\n", cero);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	i = ft_printf ("%X%Xx%X\n", -3, 2, -3);
	j = printf ("%X%Xx%X\n", -3, 2, -3);
	printf ("ft_printf = %d\nprintf = %d\n", i, j);
	return (0);
}
