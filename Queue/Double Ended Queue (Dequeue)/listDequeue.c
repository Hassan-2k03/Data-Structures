/* Operations on Doubly Ended Queue - DEQUE

You are required implement the following functions for a deque in c: Deque* deque,

push_front( Deque* deque, int element) : Insert an element at the front of the deque.
push_back(Deque* deque, int element): Insert an element at the rear of the deque.
move_to_front(Deque* deque, int element): Find the first occurrence of the given element in the deque (from the front) and move it to
the front of the deque. If the element is not found in the deque, do nothing.
get_max_min_difference(Deque* deque): Return an integer which is the absolute difference between the maximum and minimum elements in the
deque. If the deque is empty, return -1.

Input Format

first line: n- number of operations followed by n operations
for operation 1:
1
e- element to be inserted at front
for operation 2:
2
e- element to be inserted at back
for operation 3:
3
e- element to be at end for operation 4:
4

For example:
5
1
1
1
2
2
4
2
5
4

Constraints

1<=n<=6

Output Format

n output’s for n operations:
For operation 1, 2 and 3:
Elements of deque separated by spaces.
For operation 4:
Max-Min Difference: difference between Max and min element in the queue.
Elements of deque separated by spaces.

For example:
1
2 1
2 1 4
2 1 4 5
Max-Min Difference: 4
2 1 4 5

Sample Input 0

3
1
2
1
3
1
4
Sample Output 0

2
3 2
4 3 2
Sample Input 1

5
1
4
2
5
1
7
3
7
4
Sample Output 1

4
4 5
7 4 5
7 4 5
Max-Min Difference: 3
7 4 5  */

// Solution:

#include <stdio.h>
#include <stdlib.h>

// Node structure for the elements in the deque
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Structure for the double-ended queue
typedef struct Deque
{
    Node *front;
    Node *rear;
} Deque;

// Function to create a new node with a given data value
Node *create_node(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new deque
Deque *create_deque()
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Function to insert an element at the front of the deque
void push_front(Deque *deque, int element)
{
    Node *newNode = create_node(element);
    if (deque->front == NULL)
    {
        deque->front = newNode;
        deque->rear = newNode;
    }
    else
    {
        newNode->next = deque->front;
        deque->front = newNode;
    }
}

// Function to insert an element at the rear of the deque
void push_back(Deque *deque, int element)
{
    Node *newNode = create_node(element);
    if (deque->front == NULL)
    {
        deque->front = newNode;
        deque->rear = newNode;
    }
    else
    {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to return the absolute difference between the maximum and minimum elements in the deque
int get_max_min_difference(Deque *deque)
{
    int max = deque->front->data;
    int min = deque->front->data;
    Node *cur = deque->front;
    while (cur != NULL)
    {
        if (cur->data > max)
            max = cur->data;
        if (cur->data < min)
            min = cur->data;
        cur = cur->next;
    }
    return max - min;
}

void move_to_front(Deque *deque, int element)
{
    Node *cur = deque->front;
    Node *prev = NULL;
    while (cur != NULL)
    {
        if (cur->data == element)
        {
            if (prev == NULL)
            {
                return;
            }
            else if (cur->next == NULL)
            {
                deque->rear = prev;
                prev->next = NULL;
                cur->next = deque->front;
                deque->front = cur;
            }
            else
            {
                prev->next = cur->next;
                cur->next = deque->front;
                deque->front = cur;
            }
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

// Function to display the nodes of the deque from front to rear
void display(Deque *deque)
{
    if (deque->front == NULL)
    {
        printf("Deque is empty.\n");
        return;
    }

    Node *current = deque->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by the deque
void free_deque(Deque *deque)
{
    Node *current = deque->front;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(deque);
}

int main()
{
    Deque *myDeque = create_deque();
    char operation[20];
    int element, min_max;
    int n;

    scanf("%d", &n);
    while (n)
    {

        scanf("%s", operation);

        switch (operation[0])
        {
        case '1':

            scanf("%d", &element);
            push_front(myDeque, element);

            break;
        case '2':

            scanf("%d", &element);
            push_back(myDeque, element);

            break;
        case '3':

            scanf("%d", &element);
            move_to_front(myDeque, element);

            break;
        case '4':
            min_max = get_max_min_difference(myDeque);
            printf("Max-Min Difference: %d\n", min_max);
            break;
        default:
            printf("Invalid operation.\n");
        }
        display(myDeque);
        n--;
    }

    free_deque(myDeque);
    return 0;
}