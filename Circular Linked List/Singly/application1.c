/* You are required to implement various operations on a circular singly linked list in C. The list nodes represent
integers. Implement the following functions:

1) removeDuplicates : removes the duplicate elements in the CSLL and returns a pointer to the head of the list.
    Takes a pointer to the head of the list as an argument.

    For Example:  1->3->3->2->1->7 will become 1->3->2->7
2) concatenateLists : given head pointer to 2 CSLL’s joins the second csll to the end of the first csll.
    Takes the 2 head pointers as input and returns the pointer to the concatenated list as output.

    For Example: 1->2->3 and 7->8 becomes 1->2->3->7->8
3) findNthFromEnd : returns the N’th element from the end of the csll. Takes N and the head pointer as input and
    returns the data in the Nth node from the end.( indexed from 1). If N greater than the number of elements in the
    list then return -1.

    For Example: 1->2->3->4->5->6->7 , n=3  returns  5

Input Format

For function1:
first line is 1 second line: n - no of elements of the list n lines of elements

For function 2: first line is 2 second line: n - no of elements of the list n lines of elements n2- no of elements of second list
n2 lines of elements

For function3:
first line is 3 second line: n - no of elements of the list n lines of elements n3 - Nth end element

Constraints

n3>0

Output Format

For function 1 and 2:
elements of the list separated by spaces
For function 3: the Nth element from the end

Sample Input 0

1
5
1
1
2
3
2
Sample Output 0

1 2 3
Sample Input 1

2
6
1
2
3
4
5
6
4
7
8
9
0
Sample Output 1

1 2 3 4 5 6 7 8 9 0
Sample Input 2

3
4
7
9
8
3
4
Sample Output 2

7 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node
{
    int data;
    struct Node *next;
} NODE;

// Function to display the elements of the circular singly linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
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

// Function to insert a node at the end of the circular singly linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL)
    {
        newNode->next = newNode; // Circular link to itself for the first node
        return newNode;
    }

    struct Node *current = head;

    // Traverse the list to find the last node
    while (current->next != head)
    {
        current = current->next;
    }

    // Insert the new node at the end
    current->next = newNode;
    newNode->next = head; // Make it circular

    return head;
}
// Function to remove duplicates from the circular singly linked list

struct Node *removeDuplicates(struct Node *head)
{
    struct Node *h1 = head;
    
    while (h1->next != head)
    {
        struct Node *cur = h1;
        int x = cur->data;
        while(cur->next!=head)
        {
            if (cur->next->data==x)
            {
                struct Node* temp=cur->next;
                cur->next=cur->next->next;
                free(temp);
                continue;
            }
            else
            {
                cur=cur->next;
            }
        }
        h1=h1->next;
    }
    return(head);
}

// Function to concatenate two circular singly linked lists
struct Node *concatenateLists(struct Node *list1, struct Node *list2)
{
    struct Node *h1 = list1, *h2 = list2, *cur1 = h1, *cur2 = h2;
    while (cur1->next != h1)
        cur1 = cur1->next;
    while (cur2->next != h2)
        cur2 = cur2->next;
    cur1->next = h2;
    cur2->next = h1;
    return h1;
}

// Function to find the Nth node from the end of the circular singly linked list
int findNthFromEnd(struct Node *head, int n)
{
    int count = 0;
    struct Node *cur = head, *cur2 = head;
    while (cur->next != head)
    {
        count++;
        cur = cur->next;
    }
    count++;
    int x = count - n;
    while (x != 0)
    {
        cur2 = cur2->next;
        x--;
    }
    return (cur2->data);
}

int main()
{
    int n, x, n2, n3;
    int ch;
    struct Node *head = NULL;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &x);
            head = insertAtEnd(head, x);
        }
        head = removeDuplicates(head);
        display(head);
        break;

    case 2:
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &x);
            head = insertAtEnd(head, x);
        }

        struct Node *h2 = NULL;
        scanf("%d", &n2);
        while (n2--)
        {
            scanf("%d", &x);
            h2 = insertAtEnd(h2, x);
        }
        struct Node *head3 = concatenateLists(head, h2);
        display(head3);
        break;

    case 3:
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &x);
            head = insertAtEnd(head, x);
        }
        scanf("%d", &n3);
        int d = findNthFromEnd(head, n3);
        printf("%d\n", d);
        break;
    }
    return 0;
}