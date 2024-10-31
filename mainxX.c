#include <stdio.h>  
#include "ft_printf.h"

int main() 
{
    printf("%d\n", printf(" %p %p a", NULL, NULL));
    // printf("%d\n", ft_printf(" %p %p a", NULL, NULL));
    return (0);
}
