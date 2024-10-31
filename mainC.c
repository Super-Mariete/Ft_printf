#include <stdio.h>      
#include "ft_printf.h"

int main(void)
 {
    int len_printf, len_ft_printf;

    // Caso 1: Letra mayúscula
    char char1 = 'A';
    printf("== Caso 1: Letra mayúscula ==\n");
    len_printf = printf("printf: %c\n", char1);
    len_ft_printf = ft_printf("ft_printf: %c\n", char1);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 2: Letra minúscula
    char char2 = 'z';
    printf("== Caso 2: Letra minúscula ==\n");
    len_printf = printf("printf: %c\n", char2);
    len_ft_printf = ft_printf("ft_printf: %c\n", char2);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 3: Número como carácter
    char char3 = '1';
    printf("== Caso 3: Número como carácter ==\n");
    len_printf = printf("printf: %c\n", char3);
    len_ft_printf = ft_printf("ft_printf: %c\n", char3);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 4: Símbolo
    char char4 = '!';
    printf("== Caso 4: Símbolo ==\n");
    len_printf = printf("printf: %c\n", char4);
    len_ft_printf = ft_printf("ft_printf: %c\n", char4);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 5: Carácter nulo (ASCII 0)
    char char5 = '\0';
    printf("== Caso 5: Carácter nulo ==\n");
    len_printf = printf("printf: %c (fin de línea)\n", char5);  // No será visible
    len_ft_printf = ft_printf("ft_printf: %c (fin de línea)\n", char5);  // No será visible
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 6: Carácter de escape de nueva línea
    char char6 = '\n';
    printf("== Caso 6: Carácter de nueva línea ==\n");
    len_printf = printf("printf: %c (nueva línea)\n", char6);
    len_ft_printf = ft_printf("ft_printf: %c (nueva línea)\n", char6);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 7: Carácter de tabulación
    char char7 = '\t';
    printf("== Caso 7: Carácter de tabulación ==\n");
    len_printf = printf("printf: %c (tab)\n", char7);
    len_ft_printf = ft_printf("ft_printf: %c (tab)\n", char7);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    return (0);
}
