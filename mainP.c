#include <stdio.h>      // Para printf
#include "ft_printf.h"  // Asumo que aquí se encuentra la definición de ft_printf

int main(void) {
    int var = 42;
    void *ptr_null = NULL;
    void *ptr_var = &var;
    void *ptr_custom = (void *)0x12345678;
    int len_printf, len_ft_printf;

    // Caso 1: Puntero a NULL
    printf("== Caso 1: Puntero a NULL ==\n");
    len_printf = printf("printf: %p\n", ptr_null);
    len_ft_printf = ft_printf("ft_printf: %p\n", ptr_null);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 2: Puntero a una variable
    printf("== Caso 2: Puntero a una variable ==\n");
    len_printf = printf("printf: %p\n", ptr_var);
    len_ft_printf = ft_printf("ft_printf: %p\n", ptr_var);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 3: Puntero a una dirección específica (0x12345678)
    printf("== Caso 3: Puntero a una dirección específica ==\n");
    len_printf = printf("printf: %p\n", ptr_custom);
    len_ft_printf = ft_printf("ft_printf: %p\n", ptr_custom);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    return (0);
}
