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
    NODE *temp;
    temp = malloc(sizeof(NODE));
    if (temp != NULL)
    {
        temp->data = ele;
        temp->link = NULL;
    }
    return temp;
}

void insertfront(LList *ptr, int ele)
{
    NODE *temp;
    temp = creatnode(ele);
    temp->link = ptr->head;
    ptr->head = temp;
}

void concadinate(LList *ptr1, LList *ptr2)
{
    // condition where ptr 1 is empty
    if (ptr1->head == NULL)
    {
        ptr1->head = ptr2->head;
        return;
    }
    NODE *cur = ptr1->head;
    while (cur->link != NULL)
        cur = cur->link;
    cur->link = ptr2->head;
}

void intersection(LList *ptr1, int n1, LList *ptr2, int n2)
{
    NODE *cur1 = ptr1->head;
    for (int i = 0; i < n1; i++)
    {
        NODE *cur2 = ptr2->head;
        for (int j = 0; j < n2; j++)
        {
            if (cur1->data == cur2->data)
                printf("%d ", cur1->data);
            cur2 = cur2->link;
        }
        cur1 = cur1->link;
    }
    printf("\n");
}

void display(LList *ptr)
{
    if (ptr->head == NULL)
        printf("Empty list");
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
    int choice, ele, n1, n2;
    LList list1, list2;
    init(&list1);
    init(&list2);

    printf("Enter the number of elements for node 1:\n");
    scanf("%d", &n1);
    printf("Elements for node 1:\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &ele);
        insertfront(&list1, ele);
    }

    printf("Enter the number of elements for node 2:\n");
    scanf("%d", &n2);
    printf("Elements for node 2:\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &ele);
        insertfront(&list2, ele);
    }

    for (;;)
    {
        printf("1.Concadinate\n2.Intersection\n0.Exit\n");
        printf("Enter the choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            concadinate(&list1, &list2);
            display(&list1);
            break;
        case 2:
            intersection(&list1, n1, &list2, n2);
            break;
        default:
            break;
        }
    }
}