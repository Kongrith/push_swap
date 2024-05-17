/*
ref: https://www.youtube.com/watch?v=wRvipSG4Mmk&t=441s

Pseudo Code:
Declare pointers to two data stucturer/linked lists, on for stack 'a' and another for stack 'b'
    Set both pointers to NULL to avoid undefined behaviour and indicate we 're starting with empty stacks
Handle unput count errors. Argument count must be 2 or more, and the second input must not be empty
    If errors, return error
Handle both cases of input, whether a variable number of cmd, or as a string
    If the input of numbers is a string, call 'split()' to split the substring
Initialize stack 'a'


ref: https://stackoverflow.com/questions/7631282/pointer-to-pointer-with-argv

argv
+----+          +----+
| .  |   --->   | .  |  ---> "./pointer\0"
+----+          +----+
                | .  |  ---> "one\0"
                +----+
                | .  |  ---> "two\0"

*/

#include "push_swap.h"

/* print from the topmost to the lowest
 */
void display(t_list **head)
{
    t_list *tmp;

    // แก้ปัญหา head เลื่อน ทำให้เวลาแอด จะแสดงว่า 2 linked lists สุดท้ายเท่านั้น
    tmp = *head;
    while (tmp != NULL)
    {
        ft_printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}
void insertLast(t_list **head, int new_data)
{
    t_list *newNode;
    t_list *tmp;

    newNode = malloc(sizeof(t_list));

    // assign values
    newNode->data = new_data;
    newNode->next = NULL;

    // แก้ปัญหา head เลื่อน ทำให้เวลาแอด จะแสดงว่า 2 linked lists สุดท้ายเท่านั้น
    tmp = *head;
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next; // ได้ address ของ node ถัดไป (เลื่อนไปยัง linked list ถัดไป)
        tmp->next = newNode;
        newNode->prev = tmp;
    }
}

/* push เท่ากับ insertFront
 */
void push(t_list **head, int new_data)
{
    t_list *newNode;
    t_list *tmp;

    // แก้ปัญหา head เลื่อน ทำให้เวลาแอด จะแสดงว่า 2 linked lists สุดท้ายเท่านั้น
    tmp = *head;
    newNode = malloc(sizeof(t_list));
    newNode->data = new_data;
    if (*head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        tmp->prev = newNode;
        newNode->next = *head; // address of structure pointer
        newNode->prev = NULL;
        *head = newNode;
    }
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    int i;

    stack_a = NULL;
    stack_b = NULL;
    (void)stack_b;
    i = 0;
    if (argc == 1)
        return (0);
    else
    {
        while (argv[++i])
        {
            insertLast(&stack_a, ft_atoi(argv[i]));
        }
        display(&stack_a);
    }
    return (0);
}