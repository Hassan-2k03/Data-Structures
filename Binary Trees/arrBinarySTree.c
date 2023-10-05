#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void insert(int *a, int ele)
{
    int i = 0;
    while (i<MAX && a[i] != -1)
    {
        if (ele < a[i])
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    }
    a[i] = ele;
}

void inorder(int *a, int i)
{
    if (a[i] == -1)
        return;
    inorder(a, 2 * i + 1);
    printf("%d\t", a[i]);
    inorder(a, 2 * i + 2);
}

void postorder(int *a, int i)
{
    if (a[i] == -1)
        return;
    postorder(a, 2 * i + 1);
    postorder(a, 2 * i + 2);
    printf("%d\t", a[i]);
}

void preorder(int *a, int i)
{
    if (a[i] == -1)
        return;
    printf("%d\t", a[i]);
    preorder(a, 2 * i + 1);
    preorder(a, 2 * i + 2);
}

int main()
{
    int a[MAX];
    for (int i = 0; i < MAX; i++)
    {
        a[i] = -1;
    }
    int ch, ele;
    scanf("%d", &ch);
    while (1)
    {
        printf("\n1. Insert\n2. Inorder\n3. Postorder\n4. Preorder\n5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element:\n");
            scanf("%d", &ele);
            insert(a, ele);
            break;
        case 2:
            inorder(a,0);
            break;
        case 3:
            postorder(a, 0);
            break;
        case 4:
            preorder(a, 0);
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
}