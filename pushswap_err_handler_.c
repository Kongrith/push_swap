#include "push_swap.h"

void show_err_msg(void)
{
    // ft_printf("Error\n");
    write(2, "Error\n", 6);
    exit(EXIT_SUCCESS);
}

bool chk_duplicate()
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

/*
0: ไม่เจอตัวอักษร
1: เจอตัวอักษร
*/
bool chk_alphabet(char *str)
{
    int i = 0;
    bool err_flag;

    err_flag = false;
    while (str[i])
    {
        if (ft_isalpha(str[i]) || str[i] == '.')
        {
            err_flag = true;
            return (err_flag);
        }
        i++;
    }
    return (err_flag);
}

// bool ft_atoi(const char *str, int *num);
void error_handler(char *str, int *num)
{
    bool err_flag;

    err_flag = false;
    err_flag = chk_alphabet(str);
    if (err_flag)
        show_err_msg();
    err_flag = ft_atoi(str, num);
    if (err_flag)
        show_err_msg();
}