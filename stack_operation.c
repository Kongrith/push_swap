/*
ref: https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/

Stack: เข้าหลังออกก่อน (LIFO)
Push:  Insert front ของ Linked List
Pop:   Delete Head Node ของ Linked List

Queue: เข้าก่อนออกก่อน (FIFO)
Enqueue: เหมือน Push
Dequeue: Delete Last Node ของ Linked List

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int data;
    struct s_list *prev;
    struct s_list *next;
} t_list;

void freeList(t_list *head)
{
    t_list *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
int count_stack(t_list **head)
{
    if (*head == NULL)
        return (0);

    t_list *tmp;
    int len;

    len = 0;
    tmp = *head;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        len++;
    }
    return (len);
}
void display(t_list **head)
{
    t_list *tmp;
    int len;

    len = count_stack(head);
    if (len == 0)
    {
        printf("-- Empty Stack --\n");
        return;
    }
    // แก้ปัญหา head เลื่อน ทำให้เวลาแอด จะแสดงว่า 2 linked lists สุดท้ายเท่านั้น
    tmp = *head;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}
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

int pop(t_list **head)
{
    t_list *tmp;
    int pop_data;
    int len;

    if (*head == NULL)
        return 0;
    len = count_stack(head);
    tmp = *head;
    if (len > 1)
    {
        *head = tmp->next;
        pop_data = tmp->data;
        free(tmp);
        (*head)->prev = NULL;
    }
    else
    {
        *head = NULL;
        pop_data = tmp->data;
        free(tmp);
    }
    return (pop_data);
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

int deleteLast(t_list **head)
{
    t_list *tmp;
    int dequeue_data;
    int len;

    if (*head == NULL)
        return 0;
    len = count_stack(head);
    tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next; // ได้ address ของ node ถัดไป (เลื่อนไปยัง linked list ถัดไป)
    dequeue_data = tmp->data;
    if (len > 1)
    {
        tmp = tmp->prev;
        free(tmp->next);
        tmp->next = NULL;
    }
    else
    {
        *head = NULL;
        free(tmp);
    }
    return (dequeue_data);
}
void swap_top(t_list **stack)
{
    int num1;
    int num2;

    num1 = pop(stack);
    num2 = pop(stack);
    push(stack, num1);
    push(stack, num2);
}

/*
pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
*/
void pa(t_list **a, t_list **b)
{
    int num1;
    int len;

    len = count_stack(b);
    if (len > 0)
    {
        num1 = pop(b);
        push(a, num1);
    }
}
void pb(t_list **a, t_list **b)
{
    int num1;
    int len;

    len = count_stack(a);
    if (len > 0)
    {
        num1 = pop(a);
        push(b, num1);
    }
}

/*
ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
*/
void ra(t_list **a)
{
    int num;
    int len;

    len = count_stack(a);
    if (len > 0)
    {
        num = pop(a);
        insertLast(a, num);
    }
}
void rb(t_list **b)
{
    int num;
    int len;

    len = count_stack(b);
    if (len > 0)
    {
        num = pop(b);
        insertLast(b, num);
    }
}
void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}

/*
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
void rra(t_list **a)
{
    int num;
    int len;

    len = count_stack(a);
    if (len > 0)
    {
        num = deleteLast(a);
        push(a, num);
    }
}
void rrb(t_list **b)
{
    int num;
    int len;

    len = count_stack(b);
    if (len > 0)
    {
        num = deleteLast(b);
        push(b, num);
    }
}
void rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}

/*
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
ss : sa and sb at the same time.
*/
void sa(t_list **a)
{
    int len;

    len = count_stack(a);
    if (len > 1)
        swap_top(a);
}
void sb(t_list **b)
{
    int len;

    len = count_stack(b);
    if (len > 1)
        swap_top(b);
}
void ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
}

int main()
{
    t_list *stack_a;
    t_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    push(&stack_a, 5);
    push(&stack_a, 4);
    // push(&stack_a, 3);
    // push(&stack_a, 2);
    // push(&stack_a, 1);

    push(&stack_b, 10);
    push(&stack_b, 9);
    // push(&stack_b, 8);
    // push(&stack_b, 7);
    // push(&stack_b, 6);

    // Unit Test for abnormal operation
    printf("## before operation ##\n");
    printf("STACK A:\n");
    display(&stack_a);
    printf("\nSTACK B:\n");
    display(&stack_b);

    printf("\n## after operation ##\n");
    rrr(&stack_a, &stack_b);
    printf("STACK A:\n");
    display(&stack_a);
    printf("\nSTACK B:\n");
    display(&stack_b);

    // Unit Test for count_stack
    // printf("len: %d\n", count_stack(&stack_a));

    // Unit Test for normal operation
    // printf("## before swap ##\n");
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n1) ## after: sa ##\n");
    // sa(&stack_a);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n2) ## after: sb ##\n");
    // sb(&stack_b);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n3) ## after: ss ##\n");
    // ss(&stack_a, &stack_b);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n4) ## after: pa ##\n");
    // pa(&stack_a, &stack_b);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n5) ## after: pb ##\n");
    // pb(&stack_a, &stack_b);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n6) ## after: ra ##\n");
    // ra(&stack_a);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n7) ## after: rb ##\n");
    // rb(&stack_b);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n8) ## after: rr ##\n");
    // rr(&stack_a, &stack_b);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n9) ## after: rra##\n");
    // rra(&stack_a);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n10) ## after: rrb ##\n");
    // rrb(&stack_b);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    // printf("\n8) ## after: rrr ##\n");
    // rrr(&stack_a, &stack_b);
    // printf("STACK A:\n");
    // display(&stack_a);
    // printf("\nSTACK B:\n");
    // display(&stack_b);

    freeList(stack_a);
    freeList(stack_b);
    return (0);
}
