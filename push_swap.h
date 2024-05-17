#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_list
{
    int data;
    struct s_list *prev;
    struct s_list *next;
} t_list;

#endif