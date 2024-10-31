#include <stdio.h>      // Para printf
#include "ft_printf.h"  // Asumo que aquí se encuentra la definición de ft_printf
#include <limits.h>     // Para UINT_MAX

int main(void) {
    int len_printf, len_ft_printf;

    // Caso 1: Número pequeño
    unsigned int num1 = 42;
    printf("== Caso 1: Número pequeño ==\n");
    len_printf = printf("printf: %u\n", num1);
    len_ft_printf = ft_printf("ft_printf: %u\n", num1);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 2: Cero
    unsigned int num2 = 0;
    printf("== Caso 2: Cero ==\n");
    len_printf = printf("printf: %u\n", num2);
    len_ft_printf = ft_printf("ft_printf: %u\n", num2);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 3: Número grande
    unsigned int num3 = 4294967295;  // Valor máximo para unsigned int
    printf("== Caso 3: Número grande ==\n");
    len_printf = printf("printf: %u\n", num3);
    len_ft_printf = ft_printf("ft_printf: %u\n", num3);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 4: Número máximo (UINT_MAX)
    unsigned int num4 = UINT_MAX;
    printf("== Caso 4: Número máximo (UINT_MAX) ==\n");
    len_printf = printf("printf: %u\n", num4);
    len_ft_printf = ft_printf("ft_printf: %u\n", num4);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 5: Número intermedio
    unsigned int num5 = 2147483647;  // Mitad de UINT_MAX
    printf("== Caso 5: Número intermedio ==\n");
    len_printf = printf("printf: %u\n", num5);
    len_ft_printf = ft_printf("ft_printf: %u\n", num5);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    return (0);
}
