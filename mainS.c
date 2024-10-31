#include <stdio.h>      // Para printf
#include "ft_printf.h"  
int main(void) {

    int len_printf, len_ft_printf;

    // Caso 1: Cadena normal
    char *str1 = "Hola, mundo!";
    printf("== Caso 1: Cadena normal ==\n");
    len_printf = printf("printf: %s\n", str1);
    len_ft_printf = ft_printf("ft_printf: %s\n", str1);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 2: Cadena vacía
    char *str2 = "";
    printf("== Caso 2: Cadena vacía ==\n");
    len_printf = printf("printf: \"%s\"\n", str2);
    len_ft_printf = ft_printf("ft_printf: \"%s\"\n", str2);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 3: Cadena con espacios
    char *str3 = "  Con espacios  ";
    printf("== Caso 3: Cadena con espacios ==\n");
    len_printf = printf("printf: \"%s\"\n", str3);
    len_ft_printf = ft_printf("ft_printf: \"%s\"\n", str3);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 4: Cadena larga
    char *str4 = "Esta es una cadena de prueba larga para comprobar el comportamiento.";
    printf("== Caso 4: Cadena larga ==\n");
    len_printf = printf("printf: %s\n", str4);
    len_ft_printf = ft_printf("ft_printf: %s\n", str4);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    // Caso 5: Puntero NULL
    char *str5 = NULL;
    printf("== Caso 5: Puntero NULL ==\n");
    len_printf = printf("printf: %s\n", str5);  // Normalmente printf muestra "(null)" cuando recibe NULL
    len_ft_printf = ft_printf("ft_printf: %s\n", str5);
    printf("Longitud con printf: %d, Longitud con ft_printf: %d\n\n", len_printf, len_ft_printf);

    return (0);
}
