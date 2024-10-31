#include <stdio.h>      
#include "ft_printf.h" 
#include <stdlib.h>     // Para malloc y free

int main(void) 
{

    char *input;
    int len_printf, len_ft_printf;

    // Reservar memoria para la cadena introducida por el usuario
    input = (char *)malloc(1024 * sizeof(char));  // Suponemos que no introducirá más de 1024 caracteres
    if (!input) {
        printf("Error reservando memoria.\n");
        return 1;
    }

    // Solicitar entrada del usuario
    printf("Introduce cualquier cosa que desees: ");
    fgets(input, 1024, stdin);  // Leer la entrada del usuario (hasta 1024 caracteres)

    // Comprobación con printf
    printf("== Salida con printf ==\n");
    len_printf = printf("%s", input);
    printf("Longitud impresa con printf: %d\n\n", len_printf);

    // Comprobación con ft_printf
    printf("== Salida con ft_printf ==\n");
    len_ft_printf = ft_printf("%s", input);
    printf("Longitud impresa con ft_printf: %d\n\n", len_ft_printf);

    // Liberar memoria reservada
    free(input);

    return (0);
}
