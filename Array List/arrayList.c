#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct array
{
    int *a;
    int size;
    int used_size;
} ALIST;

void init(ALIST *ptr)
{
    ptr->size = 0;
    ptr->used_size = -1;
}

void alloc(ALIST *ptr)
{
    if (ptr->size == 0)
    {
        ptr->a = (int *)malloc(MAX * sizeof(int));
        ptr->size = MAX;
    }
    else if (ptr->used_size == ptr->size - 1)
    {
        ptr->a = (int *)realloc(ptr->a, 2 * ptr->size * sizeof(int));
        ptr->size = 2 * ptr->size;
    }
}

void insert(ALIST *ptr, int ele)
{
    alloc(ptr);
    ptr->used_size++;
    ptr->a[ptr->used_size] = ele;
}

int delete(ALIST *ptr)
{
    if (ptr->used_size == -1)
        return (9999);
    int x = ptr->a[ptr->used_size];
    ptr->used_size--;
    return (x);
}

void display(ALIST *ptr)
{
    if (ptr->used_size == -1)
        printf("list is empty\n");
    for (int i = 0; i <= ptr->used_size; i++)
        printf("%d ", ptr->a[i]);
    printf("\n");
}

int main()
{
    ALIST list;
    init(&list);
    int choice, ele, x;
    do
    {
        printf("1.insert\n2.Delete\n3.Display\n0.Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 0:
                exit(0);
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d", &ele);
            insert(&list, ele);
            break;
        case 2:
            x = delete (&list);
            if (x == 9999)
                printf("List is empty\n");
            else
                printf("Deleted element is %d\n", x);
            break;
        case 3:
            display(&list);
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 0);
    return (0);
}