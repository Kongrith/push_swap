#include "push_swap.h"

int chk_num_duplicate()
{
    int count;
    int array[5];
    count = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (array[i] == array[j])
                show_err_msg();
        }
    }
}

void show_err_msg(void)
{
    // ft_printf("Error\n");
    write(2, "Error\n", 6);
    exit(EXIT_SUCCESS);
}