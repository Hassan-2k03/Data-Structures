#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insert(Node *a[], int i, int j)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = j;
    temp->next = NULL;
    Node *cur = a[i];
    if (cur == NULL)
        a[i] = temp;
    else
    {
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = temp;
    }
}

void createGraph(Node *a[], int n)
{
    int i, j;
    for (int i = 0; i < n; i++)
        a[i] = NULL;
    while (1)
    {
        printf("Enter source and destination \n");
        scanf("%d %d", &i, &j);
        if (i < 0 || j < 0 || i >= n || j >= n)
            break;
        insert(a, i, j);
    }
}

void display(Node *a[], int n)
{
    int i;
    Node *cur;
    for (i = 0; i < n; i++)
    {
        cur = a[i];
        printf("%d -> ", i);
        while (cur != NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}

int main()
{
    Node *a[10];
    int n;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    createGraph(a, n);
    display(a, n);
    return 0;
}