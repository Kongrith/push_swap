#include "push_swap.h"

void show_err_msg(void)
{
    write(2, "Error\n", 6);
    exit(EXIT_SUCCESS);
}

bool chk_duplicate(t_list **tmp)
{
    int *ptr;
    int len;
    int i;

    len = count_stack(tmp);
    ptr = malloc(sizeof(int) * len);
    linked_list_to_arr(tmp, ptr);
    ascending_sort(ptr, len);

    // ft_printf("num: %d\n", len);
    // ft_printf("len: %d\n", len);

    i = 0;
    while (i < len - 1)
    {
        if (ptr[i] == ptr[i + 1])
        {
            free(ptr);
            // freeList(*tmp);
            return (true);
        }
        i++;
    }

    // int count;
    // int array[5];
    // count = sizeof(array) / sizeof(array[0]);

    // for (int i = 0; i < count - 1; i++)
    // {
    //     for (int j = i + 1; j < count; j++)
    //     {
    //         if (array[i] == array[j])
    //             return (1)
    //     }
    // }

    free(ptr);
    return (false);
}

int ft_isalpha(int c)
{
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
    {
        return (1);
    }
    else
    {
        return (0);
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
        // if (str[i] < 43 || str[i] == 44 || (45 < str[i] && str[i] < 48) || 57 < str[i])
        // if ((45 < str[i] && str[i] < 48) || str[i] == '.')
        {
            err_flag = true;
            return (err_flag);
        }
        i++;
    }
    return (err_flag);
}

// bool ft_atoi(const char *str, int *num);
bool error_handler(char *str, long *num)
{
    bool err_flag;

    err_flag = false;
    err_flag = chk_alphabet(str);
    if (err_flag == true)
        return (true);
    err_flag = ft_atoi(str, num);
    if (err_flag == true)
        return (true);
    return (err_flag);
}