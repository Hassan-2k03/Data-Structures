#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} Node;

void insert(Node **root, int ele)
{
    Node *temp = malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("insufficeient Memory\n");
        return;
    }
    temp->data = ele;
    temp->right = temp->left = NULL;
    if (*root == NULL)
    {
        *root = temp;
        return;
    }
    Node *cur = *root;
    Node *prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        if (ele < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (ele < prev->data)
        prev->left = temp;
    else
        prev->right = temp;
}

int main()
{
    Node *root = NULL;
    int ele, ch;
    while (1)
    {
        printf("Insert\n");
        printf("Enter your Choice\n");
        scanf("%d", &ele);
        switch (ch)
        {
        case 1:
            printf("Enter element:\n");
            break;

        default:
            break;
        }
    }
}
