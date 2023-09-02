/* Sort the given 2 list in assinding order and display it as one list */

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

void insertrear(LList *ptr, int ele)
{

    NODE *temp;
    temp = creatnode(ele);
    if (ptr->head == NULL)
        ptr->head = temp;
    NODE *cur = ptr->head;
    while (cur->link != NULL)
        cur = cur->link;
    cur->link = temp;
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

void sortAssending(LList *ptr, int ele)
{
    NODE *temp = creatnode(ele);
    if (ptr->head == NULL || ele < ptr->head->data)
    {
        temp->link = ptr->head;
        ptr->head = temp;
    }
    else
    {
        NODE *cur = ptr->head;
        NODE *pre = NULL;
        while (cur != NULL && ele >= cur->data)
        {
            pre = cur;
            cur = cur->link;
        }
        temp->link = pre->link;
        pre->link = temp;
    }
}

void sort2lists(LList *ptr1, LList *ptr2)
{
    LList ordlist;
    init(&ordlist);
    NODE *cur = ptr1->head, *prev = NULL;
    while (cur != NULL)
    {
        sortAssending(&ordlist, cur->data);
        cur = cur->link;
    }
    cur = ptr2->head;
    while (cur != NULL)
    {
        sortAssending(&ordlist, cur->data);
        cur = cur->link;
    }
    cur = ordlist.head;
    while (cur->link != NULL)
    {
        if (cur->data == cur->link->data)
        {
            NODE *temp = cur->link;
            cur->link = cur->link->link;
            free(temp);
            continue;
        }
        prev = cur;
        cur = cur->link;
    }
    display(&ordlist);
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

    sort2lists(&list1, &list2);
}