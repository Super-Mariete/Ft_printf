#include <stdio.h> 
#include "ft_printf.h"
#include <limits.h>    // Para acceder a los valores INT_MIN e INT_MAX

int main(void) 
{
    int len_printf, len_ft_printf;

    // Caso 1: Número positivo
    int num1 = 12345;
    printf("== Caso 1: Número positivo ==\n");
    len_printf = printf("printf con %%d: %d\n", num1);
    len_ft_printf = ft_printf("ft_printf con %%d: %d\n", num1);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n", len_printf, len_ft_printf);

    len_printf = printf("printf con %%i: %i\n", num1);
    len_ft_printf = ft_printf("ft_printf con %%i: %i\n", num1);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 2: Número negativo
    int num2 = -54321;
    printf("== Caso 2: Número negativo ==\n");
    len_printf = printf("printf con %%d: %d\n", num2);
    len_ft_printf = ft_printf("ft_printf con %%d: %d\n", num2);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n", len_printf, len_ft_printf);

    len_printf = printf("printf con %%i: %i\n", num2);
    len_ft_printf = ft_printf("ft_printf con %%i: %i\n", num2);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 3: Número cero
    int num3 = 0;
    printf("== Caso 3: Número cero ==\n");
    len_printf = printf("printf con %%d: %d\n", num3);
    len_ft_printf = ft_printf("ft_printf con %%d: %d\n", num3);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n", len_printf, len_ft_printf);

    len_printf = printf("printf con %%i: %i\n", num3);
    len_ft_printf = ft_printf("ft_printf con %%i: %i\n", num3);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 4: Número entero mínimo
    int num4 = INT_MIN;
    printf("== Caso 4: Número entero mínimo ==\n");
    len_printf = printf("printf con %%d: %d\n", num4);
    len_ft_printf = ft_printf("ft_printf con %%d: %d\n", num4);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n", len_printf, len_ft_printf);

    len_printf = printf("printf con %%i: %i\n", num4);
    len_ft_printf = ft_printf("ft_printf con %%i: %i\n", num4);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 5: Número entero máximo
    int num5 = INT_MAX;
    printf("== Caso 5: Número entero máximo ==\n");
    len_printf = printf("printf con %%d: %d\n", num5);
    len_ft_printf = ft_printf("ft_printf con %%d: %d\n", num5);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n", len_printf, len_ft_printf);

    len_printf = printf("printf con %%i: %i\n", num5);
    len_ft_printf = ft_printf("ft_printf con %%i: %i\n", num5);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    return (0);
}
