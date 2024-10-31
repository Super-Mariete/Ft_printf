#include <stdio.h>      
#include "ft_printf.h"

int main(void) 
{
    void *ptr = (void *)-1;  // Puntero que apunta a la dirección de memoria -1
    int len_printf, len_ft_printf;

    // Comprobación con printf
    printf("== Prueba con printf ==\n");
    len_printf = printf("Puntero -1: %p\n", ptr);
    printf("Longitud impresa con printf: %d\n\n", len_printf);

    // Comprobación con ft_printf
    printf("== Prueba con ft_printf ==\n");
    len_ft_printf = ft_printf("Puntero -1: %p\n", ptr);
    printf("Longitud impresa con ft_printf: %d\n\n", len_ft_printf);

    return (0);
}
