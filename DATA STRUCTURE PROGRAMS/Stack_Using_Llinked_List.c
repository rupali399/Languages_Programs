#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedlisttraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("element is %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

int isEmpty(struct Node * top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node * top)
{
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node * push(struct Node * top, int x)
{
    if(isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));  
        n -> data = x;
        n -> next = top;
        top = n;
        return top;
    }
}

int pop(struct Node * *top)
{
        if(isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = *top;
        *top = (*top) -> next;
        int x = n -> data;
        free(n);
        return x;
    }
}

int main()
{
    struct Node *top = NULL;

    top = push(top, 72);
    top = push(top, 45);
    top = push(top, 67);

    linkedlisttraversal(top);
    int element = pop(&top);

    printf("Popped element is %d\n", element);
    linkedlisttraversal(top);

    return 0;
}