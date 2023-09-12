#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void insertfront(int *q, int *f, int *r, int ele)
{
    if (*f == 0 && *r == MAX - 1 || *f == *r + 1)
        printf("Queue is full\n");
    else
    {
        if (*f == -1 && *r == -1)
        {
            *f = *r = 0;
            q[*f] = ele;
        }
        else if (*f == 0)
        {
            *f = MAX - 1;
            q[*f] = ele;
        }
        else
        {
            *f = *f - 1;
            q[*f] = ele;
        }
    }
}

void insertrear(int *q, int *f, int *r, int ele)
{
    if (*f == 0 && *r == MAX - 1 || *f == *r + 1)
        printf("Queue is full\n");
    else
    {
        if (*f == -1 && *r == -1)
        {
            *f = *r = 0;
            q[*r] = ele;
        }
        else if (*r == MAX - 1)
        {
            *r = 0;
            q[*r] = ele;
        }
        else
        {
            *r = *r + 1;
            q[*r] = ele;
        }
    }
}

int deletefront(int *q, int *f, int *r)
{
    if (*f == -1)
        return -9999;
    else
    {
        int x = 0;
        if (*f = *r)
        {
            x = q[*f];
            *f = *r = -1;
        }
        else if (*f == MAX - 1)
        {
            x = q[*f];
            *f = 0;
        }
        else
        {
            x = q[*f];
            *f = *f + 1;
        }
        return x;
    }
}

int deleterear(int *q, int *f, int *r)
{
    if (*f == -1)
        return -9999;
    else
    {
        int x = 0;
        if (*f = *r)
        {
            x = q[*f];
            *f = *r = -1;
        }
        else if (*r == 0)
        {
            x = q[*r];
            *r = MAX - 1;
        }
        else
        {
            x = q[*r];
            *r = *r - 1;
        }
        return x;
    }
}

void display(int *q, int f, int r)
{
    int i;
    if (f == -1 && r == -1)
        printf("Queue is empty\n");
    else
    {
        int i = f;
        while (i != r)
        {
            printf("%d ", q[i]);
            i = (i + 1) % MAX;
        }
        printf("%d ", q[i]);
    }
}

int main()
{
    int q[MAX], f = -1, r = -1, ch, ele, x;
    while (1)
    {
        printf("\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            insertfront(q, &f, &r, ele);
            break;
        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            insertrear(q, &f, &r, ele);
            break;
        case 3:
            if (-9999)
            {
                printf("Queue is empty\n");
            }
            else
            {
                x = deletefront(q, &f, &r);
                printf("Deleted element is %d\n", x);
            }
            break;
        case 4:
            if (-9999)
            {
                printf("Queue is empty\n");
            }
            else
            {
                x = deleterear(q, &f, &r);
                printf("Deleted element is %d\n", x);
            }
            break;
        case 5:
            display(q, f, r);
            break;
        }
    }
}