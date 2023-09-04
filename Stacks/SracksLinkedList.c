#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} NODE;

typedef struct llist
{
    NODE *head;
} LList;

void init(LList *ptr)
{
    ptr->head = NULL;
}

NODE *creatnode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    if (temp != NULL)
    {
        temp->data = ele;
        temp->link = NULL;
    }
    return temp;
}

void push(LList *ptr, int ele)
{
    NODE *temp;
    temp = creatnode(ele);
    temp->link = ptr->head;
    ptr->head = temp;
}

int pop(LList *ptr)
{
    if (ptr->head == NULL)
        return -1;
    NODE *first = ptr->head;
    ptr->head = first->link;
    int x = first->data;
    free(first);
    return x;
}

int peep(LList *ptr)
{
    return (ptr->head->data);
}

void display(LList *ptr)
{
    if (ptr->head == NULL)
        printf("Underflow");
    else
    {
        NODE *cur = ptr->head;
        while (cur != NULL)
        {
            printf("%d ", cur->data);
            cur = cur->link;
        }
    }
    printf("\n");
}

int main()
{
    int choice, ele, x, pos;
    LList mylist;
    init(&mylist);
    do
    {
        printf("1.Push\n2.Pop\n3.Peep\n4.Display\n");
        printf("Enter choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            printf("Enter the element: \n");
            scanf("%d", &ele);
            push(&mylist, ele);
            break;
        case 2:
            x = pop(&mylist);
            if (x == -1)
                printf("Underflow\n");
            else
                printf("Popped element: %d\n", x);
            break;
        case 3:
            x = peep(&mylist);
            if (x == -1)
                printf("Underflow\n");
            else
                printf("Peeped element: %d\n", x);
            break;
        case 4:
            display(&mylist);
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 0);
}