#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct node
{
    int data;
    struct node *next;
}Node;

int hash(int key)
{
    return key%max;
}

Node *insert (int key, Node *root)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = key;
    temp->next = NULL;
    Node *cur = root;
    if(root == NULL)
        return temp;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    return root;
}

void display(Node *a[])
{
    Node *cur;
    for(int i = 0; i <max; i++)
    {
        cur = a[i];
        printf("%d -> ",i);
        while(cur != NULL)
        {
            printf("%d -> ",cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}

void search(int key, Node* a[])
{
    int index = hash (key);
    Node *cur = a[index];
    while(cur != NULL)
    {
        if(cur->data == key)
        {
            printf("Element found\n");
            return;
        }
        cur = cur->next;
    }
    printf("Element not found\n");
}

void delete(int key, Node* a[])
{
    int index = hash(key);
    Node* cur = a[index];
    Node* prev = NULL;
    while(cur!=NULL)
    {
        if (cur->data == key)
        {
            if(prev == NULL)
            {
                a[index] = cur->next;
                free(cur);
                printf("Element deleted\n");
                return;
            }
            prev->next = cur->next;
            free(cur);
            printf("Element deleted\n");
            return;
        }
        prev = cur;
        cur = cur->next;;
    }
}

int main()
{
    Node *a[max]; // array of pointers'
    for(int i=0;i<max;i++)
        a[i]=NULL; // initializing all the pointers to NULL
    int ch,ele,key,index;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the key\n");
                    scanf("%d",&key);
                    index = hash(key);
                    a[index] = insert(key,a[index]);
                    break;
            case 2: printf("Enter the key\n");
                    scanf("%d",&key);
                    delete(key,a);
                    break;
            case 3: printf("Enter the key\n");
                    scanf("%d",&key);
                    search(key,a);
                    break;
                    
            case 4: display(a);
                    break;
            case 5: exit(0);
        }
    }
}                    