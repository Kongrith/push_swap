#include "ft_printf.h"
#include "libft.h"
#include <string.h>

int main()
{
    int a[] = {0, 1, 0, 0, 1};
    int b[] = {0, 1, 0, 0, 1, 1};
    int logic;

    logic = memcmp(a, b, sizeof(b)) == 0;
    ft_printf("logic: %d \n", logic);
}