/* You are required to implement various operations on a circular doubly linked list in C. The list nodes represent
integers. Implement the following functions:

1) insertAfterNode: Function to insert a new node with the value ‘data’ after the first occurrence of a node with the
value ‘afterData’. It takes head pointer to the cdll the, ‘data’ which is the value to be inserted,
(and ‘afterdata’ i.e. the key value after which a new node should be created.
 If afterdata is not present in the list then do nothing. Note: Use createNode function to create the new node.

For example: 10->20->30->50->40->20, data: 25, afterData: 20
          result: 10->20->25->30->50->40->20

2) moveLargestToFront: A function to move the node with the largest value to the front of the cdll.
Takes pointer to head pointer as input

For example: 23->45->72->56->31 becomes 72->23->45->56->31
3) deleteNode: Function to delete the first occurrence of a node with the given key value from the cdll.
If the element is not present then don’t make any changes.
Takes pointer to head pointer and data i.e. key value to delete as input

For example: 20->45->11->54->44, data: 45 becomes 20->11->54->44
Input Format

For Function1:
first line is 1 second line: n - no of elements of the list n lines of elements afterData
data

For Function2:
first line is 2 second line: n - no of elements of the list n lines of elements

For Function3:
first line is 1 second line: n - no of elements of the list n lines of elements key

Constraints

n>0

Output Format

For function 1,2 and 3: elements of the list separated by spaces

Sample Input 0

1
5
2
5
7
8
9
2
3
Sample Output 0

2 3 5 7 8 9
Sample Input 1

2
6
5
2
6
5
4
7
Sample Output 1

7 5 2 6 5 4
Sample Input 2

3
5
22
53
34
7
64
53
Sample Output 2

22 34 7 64  */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular doubly linked list.
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node.
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        (*head)->prev = newNode;
        last->next = newNode;
    }
}

// Function to display the elements of the circular doubly linked list.
void display(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }
    struct Node *current = head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to insert a new node with data after the first occurrence of a node with afterData.
void insertAfterNode(struct Node *head, int afterData, int data)
{
    // Function to insert a new node with data after the first occurrence of a node with afterData.
    struct Node *nnode = createNode(data);
    if (head == NULL)
        return;
    struct Node *cur = head;
    do
    {
        if (cur->data == afterData)
        {
            nnode->next = cur->next;
            nnode->prev = cur;
            cur->next->prev = nnode;
            cur->next = nnode;
            return;
        }
        cur = cur->next;
    } while (cur != head);
}

// Function to move the node with the largest value to the front of the list.
void moveLargestToFront(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    struct Node *cur = *head;
    struct Node *m = *head;
    do
    {
        if (cur->data > m->data)
            m = cur;
        cur = cur->next;
    } while (cur != *head);
    if (m == *head)
        return;
    m->prev->next = m->next;
    m->next->prev = m->prev;
    m->next = *head;
    m->prev = (*head)->prev;
    (*head)->prev->next = m;
    (*head)->prev = m;
    *head = m;
}

// Function to delete the first occurrence of a node with the given data from the circular doubly linked list.
void deleteNode(struct Node **head, int data)
{
    if (head == NULL)
    {
        return;
    }
    struct Node *cur = *head;
    do
    {
        if (cur->data == data)
        {
            struct Node *t = cur;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free(t);
            return;
        }
        cur = cur->next;
    } while (cur != *head);
}

int main()
{
    struct Node *head = NULL;
    int ch;
    int n;
    scanf("%d", &ch);
    scanf("%d", &n);
    int x;
    while (n--)
    {
        scanf("%d", &x);
        insertAtEnd(&head, x);
    }

    int data, afterData, key;
    switch (ch)
    {
    case 1:
        scanf("%d", &afterData);
        scanf("%d", &data);
        insertAfterNode(head, afterData, data);
        // printf("After inserting %d after %d: ",data, afterData);
        break;

    case 2:
        moveLargestToFront(&head);
        // printf("After moving the largest element to the front: ");
        break;
    case 3:
        scanf("%d", &key);
        deleteNode(&head, key);
        // printf("After deleting %d: ",key);
        break;
    }
    display(head);

    return 0;
}