// TowerOfHanoi using recursion linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void towerofHanoi(int n, char source, char destination, char auxilary)
{
    if (n == 1)
        printf("Move disk 1 from %c to %c\n", source, destination);
    else
    {
        towerofHanoi(n - 1, source, auxilary, destination);
        printf("Move disk %d from %c to %c\n", n, source, destination);
        towerofHanoi(n - 1, auxilary, destination, source);
    }
}

int main()
{
    printf("Enter the number of disks: ");
    int n;
    scanf("%d", &n);
    towerofHanoi(n, 'A', 'C', 'B');
}