#include <stdio.h>
#define MAX 5
typedef struct stack
{
    int top;
    int a[MAX];
} STACK;

void push(STACK *ptr, int ele)
{
    if (ptr->top == MAX - 1)
        printf("Overflow\n");
    else
    {
        ptr->top++;
        ptr->a[ptr->top] = ele;
    }
}

int pop(STACK *ptr)
{
    if (ptr->top == -1)
        return -9999;
    else
    {
        int x = ptr->a[ptr->top];
        ptr->top--;
        return x;
    }
}

int peep(STACK *ptr)
{
    if (ptr->top == -1)
        return -1;
    else
        return ptr->a[ptr->top];
}

void display(STACK *ptr)
{
    if (ptr->top == -1)
        printf("Underflow\n");
    else
    {
        for (int i = ptr->top; i >= 0; i--)
            printf("%d ", ptr->a[i]);
    }
    printf("\n");
}

int main()
{
    STACK s;
    STACK *ptr = &s;
    ptr->top = -1;
    int ch, x;
    do
    {
        printf("1.Push\n2.Pop\n3.Peep\n4.Display\n");
        printf("Enter choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            return 0;
        case 1:
            printf("Enter the element: \n");
            scanf("%d", &x);
            push(ptr, x);
            break;
        case 2:
            x = pop(ptr);
            if (x == -9999)
                printf("Underflow\n");
            else
                printf("The deleted element is %d\n", x);
            break;
        case 3:
            x = peep(ptr);
            if (x == -1)
                printf("Underflow\n");
            else
                printf("The top element is %d\n", x);
            break;  
        case 4:
            display(ptr);
            break;
        }

    } while (ch <= 4);
}