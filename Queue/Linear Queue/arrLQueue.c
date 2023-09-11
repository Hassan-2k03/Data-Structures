#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void enqueue(int *arr , int *rear , int ele)
{
    if(*rear==MAX-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(*rear==-1)
        {
            *rear = 0;
        }
        else
        {
            *rear = *rear + 1;
        }
        arr[*rear] = ele;
    }
}

int dequeue(int *arr , int *front , int *rear)
{
    if(*front==-1)
    {
        printf("Queue is empty\n");
        return -9999;
    }
    int x = arr[*front];
    if(*front==*rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        *front = *front + 1;
    }
    return x;
}

void display(int *arr , int front , int rear)
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[MAX];
    int front = -1;
    int rear = -1;
    int ch;
    int ele;
    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                if(rear==MAX-1)
                {
                    printf("Queue is full\n");
                }
                else
                {
                    if(front==-1)
                    {
                        front = 0;
                    }
                    rear++;
                    arr[rear] = ele;
                }
                break;
            case 2:
                if(front==-1)
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    ele = arr[front];
                    printf("Deleted element is %d\n",ele);
                    if(front==rear)
                    {
                        front = -1;
                        rear = -1;
                    }
                    else
                    {
                        front++;
                    }
                }
                break;
            case 3:
                if(front==-1)
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    for(int i=front;i<=rear;i++)
                    {
                        printf("%d ",arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}