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

int nodeCount(LList *ptr)
{
    int count = 0;
    if (ptr->head == NULL)
        return count;
    NODE *cur = ptr->head;
    while (cur != NULL)
    {
        cur = cur->link;
        count++;
    }
    return count;
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

void insertPos(LList *ptr, int ele, int pos)
{
    int size = nodeCount(ptr) - 1;
    if (pos < 0 || pos > size)
    {
        printf("Invalid\n");
        return;
    }
    NODE *temp = creatnode(ele);
    if (pos == 0)
    {
        temp->link = ptr->head;
        ptr->head = temp;
    }
    else
    {
        NODE *cur = ptr->head;
        while (--pos)
            cur = cur->link;
        temp->link = cur->link;
        cur->link = temp;
    }
}

int deletefront(LList *ptr)
{
    if (ptr->head == NULL)
        return -1;
    NODE *first = ptr->head;
    ptr->head = first->link;
    int x = first->data;
    free(first);
    return x;
}

int deleterear(LList *ptr)
{
    NODE *first = ptr->head;
    int x;
    if (ptr->head == NULL)
        return -1;
    if (first->link == NULL)
    {
        x = first->data;
        free(first);
        ptr->head = NULL;
        return (x);
    }
    else
    {
        NODE *cur = ptr->head;
        NODE *pre = NULL;
        while (cur->link != NULL)
        {
            pre = cur;
            cur = cur->link;
        }
        x = cur->data;
        free(cur);
        pre->link = NULL;
        return (x);
    }
}

int deletePos(LList *ptr, int pos)
{

    int size = nodeCount(ptr) - 1, x = -1;
    if (pos < 0 || pos > size)
        return x;
    if (pos == 0)
    {
        NODE *cur = ptr->head;
        ptr->head = cur->link;
        x = cur->data;
        free(cur);
        return x;
    }
    else
    {
        NODE *cur = ptr->head;
        NODE *pre = NULL;
        while (pos--)
        {
            pre = cur;
            cur = cur->link;
        }
        pre->link = cur->link;
        x = cur->data;
        free(cur);
        return x;
    }
}

int search(LList *ptr, int ele)
{
    if (ptr->head == NULL)
        return -1;
    NODE *cur = ptr->head;
    while (cur != NULL && cur->data != ele)
        cur = cur->link;
    if (cur == NULL)
        return -1;
    else
        return 1;
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

int sum(LList *ptr)
{
    NODE *cur = ptr->head;
    int sum = 0;
    while (cur != NULL)
    {
        sum += cur->data;
        cur = cur->link;
    }
    return sum;
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
    int choice, ele, x, pos;
    LList mylist;
    init(&mylist);
    do
    {
        printf("1. Insert at front\n2. Insert at rear\n3. Delete at front\n4. Delete at rear\n5. Search\n");
        printf("6. Number of nodes\n7. Insert at Position\n8. Delete at position\n9. Sort elements in assending while inserting\n");
        printf("10. Sum of elements\n11. Display\n0. Exit\n");
        printf("Enter choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            printf("Enter the element: \n");
            scanf("%d", &ele);
            insertfront(&mylist, ele);
            break;
        case 2:
            printf("Enter the element: \n");
            scanf("%d", &ele);
            insertrear(&mylist, ele);
            break;
        case 3:
            x = deletefront(&mylist);
            if (x == -1)
                printf("Empty list\n");
            else
                printf("The deleted element is %d\n", x);
            break;
        case 4:
            x = deleterear(&mylist);
            if (x == -1)
                printf("Empty list\n");
            else
                printf("The deleted element is %d\n", x);
            break;
        case 5:
            printf("Enter the element to be search: \n");
            scanf("%d", &ele);
            x = search(&mylist, ele);
            if (x == -1)
                printf("Element %d not found\n", ele);
            else
                printf("Element %d found\n", ele);
            break;
        case 6:
            x = nodeCount(&mylist);
            printf("Number of Nodes present in link is %d\n", x);
            break;
        case 7:
            printf("Enter the element: \n");
            scanf("%d", &ele);
            printf("Enter the position: \n");
            scanf("%d", &pos);
            insertPos(&mylist, ele, pos);
            break;
        case 8:
            printf("Enter the position: \n");
            scanf("%d", &pos);
            x = deletePos(&mylist, pos);
            if (x == -1)
                printf("Invalid position\n");
            else
                printf("The deleted element is %d\n", x);
            break;
        case 9:
            printf("Enter the element: \n");
            scanf("%d", &ele);
            sortAssending(&mylist, ele);
            break;
        case 10:
            printf("The sum of the elements in list is %d\n", sum(&mylist));
            break;
        case 11:
            display(&mylist);
            break;
        default:
            break;
        }
    } while (choice <= 11);
}