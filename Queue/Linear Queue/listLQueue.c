#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}Node;

typedef struct
{
    Node *front;
    Node *rear;
}Queue;

void enqueue(Queue *ptr , int ele)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = ele;
    temp->link = NULL;
    if(ptr->front==NULL)
    {
        ptr->front = temp;
        ptr->rear = temp;
    }
    else
    {
        ptr->rear->link = temp;
        ptr->rear = temp;
    }
}

int dequeue(Queue *ptr)
{
    if(ptr->front==NULL)
    {
        printf("Queue is empty\n");
        return -9999;
    }
    Node *temp = ptr->front;
    int x = temp->data;
    ptr->front = ptr->front->link;
    free(temp);
    return x;
}

void display(Queue *ptr)
{
    Node *cur = ptr->front;
    if(cur==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur = cur->link;
    }
    printf("\n");
}

int main()
{
    Queue *ptr = malloc(sizeof(Queue));
    ptr->front = NULL;
    ptr->rear = NULL;
    int ele,ch,x;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element to be inserted\n");
                    scanf("%d",&ele);
                    enqueue(ptr,ele);
                    break;
            case 2: x = dequeue(ptr);
                    if(x!=-9999)
                        printf("Deleted element is %d\n",x);
                    break;
            case 3: display(ptr);
                    break;
            case 4: exit(0);
        }
    } 
}