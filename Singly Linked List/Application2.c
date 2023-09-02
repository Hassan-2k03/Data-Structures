/* You are given a linked list where each node contains a ‘data’ field which stores an integer value and a ‘next’ pointer of type node which points to the next node. You are required to sort the list in a particular way-

If the integer is a multiple of of 2 it should go the front of the list
If it is a multiple of 3 send it to the end.
If it is a multiple of both then delete it.
Else leave it as it is.
For example the list 15 -> 2 -> 6 -> 7 -> 9 -> 4 will become 4 -> 2 -> 7 -> 15 -> 9

You are required to implement the function custom_sort() which takes the head pointer to the list as an argument and returns the head pointer to the rearranged list.

Input Format

Input consists of 2 lines The first line is the number of elements in the list. The second line is the elements of the list.

Constraints

n - number of elements in the list 1<=n<=100

Output Format

Output is the elements of the reordered list

Sample Input 0

6
15 2 6 7 9 4
Sample Output 0

4 2 7 15 9
Sample Input 1

5
2 4 6 8 10
Sample Output 1

10 8 4 2
Sample Input 2

5
3 6 9 18 21
Sample Output 2

3 9 21
Sample Input 3

5
24 5 3 13 30
Sample Output 3

5 13 3 */

// code

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to insert a node at the end of the list
Node *insertAtEnd(Node *head, int value);

// Function to rearrange the linked list based on custom sorting rules
Node *custom_sort(Node *head);

// Function to display the linked list
void displayList(Node *head);

int main()
{
    Node *head = NULL;
    int n, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }
    head = custom_sort(head);
    displayList(head);
    return 0;
}

Node *insertAtEnd(Node *head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;
    Node *current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
    return head;
}

Node *insertAtStart(Node *head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

void displayList(Node *head)
{
    Node *current = head;
    if (current == NULL)
        printf("Empty List\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node *custom_sort(Node *head)
{
    Node *head1 = NULL;
    Node *cur = head, *prev = NULL, *temp = NULL;

    while (cur != NULL)
    {
        temp = cur;
        if (cur->data % 6 == 0)
        {
            if (prev == NULL)
            {
                head = head->next;
                cur = cur->next;
                continue;
            }
            prev->next = cur->next;
            cur = cur->next;
            free(temp);
            continue;
        }
        prev = cur;
        cur = cur->next;
    }
    cur = head;
    while (cur != NULL)
    {
        if (!(cur->data % 2 == 0 || cur->data % 3 == 0))
            head1 = insertAtEnd(head1, cur->data);
        cur = cur->next;
    }
    cur = head;
    while (cur != NULL)
    {
        if (cur->data % 2 == 0)
            head1 = insertAtStart(head1, cur->data);
        else if (cur->data % 3 == 0)
            head1 = insertAtEnd(head1, cur->data);
        cur = cur->next;
    }
    return head1;
}