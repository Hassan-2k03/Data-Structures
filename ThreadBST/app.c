/*  Write a C program that constructs a threaded binary search tree (TBST) from a sequence of N integers. The program should allow the user to input the number of elements (N) and the N integers to build the TBST. After constructing the TBST, implement a function pathExists that determines if a given path (a sequence of nodes) exists in the TBST, utilizing threaded links to optimize the search.

Input Format

5 //Number of elements in the TBST 5 //Elements of TBST 4 3 2 1 3 //Length of path 1 //Elements of the path 2 3

Constraints

0<=Number of elements<=1000

Output Format

Path does not exist.

Sample Input 0

5
5
4
3
2
1
3
1
2
3
Sample Output 0

Path does not exist. */

// solution

#include <stdio.h>
#include <stdlib.h>

// Structure for threaded binary tree node
struct TBSTNode
{
    int data;
    struct TBSTNode *left;
    struct TBSTNode *right;
    int lthread; // 1 if left is a thread, 0 if a left child
    int rthread; // 1 if right is a thread, 0 if a right child
};

// Create a new TBST node
struct TBSTNode *createNode(int data)
{
    struct TBSTNode *newNode = (struct TBSTNode *)malloc(sizeof(struct TBSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthread = 1; // Initialize as threads
    newNode->rthread = 1;
    return newNode;
}

// Insert a node into the threaded BST
struct TBSTNode *insert(struct TBSTNode *root, int data)
{
    struct TBSTNode *newNode = createNode(data);
    if (root == NULL)
    {
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->lthread = 1;
        newNode->rthread = 1;
        root = newNode;
    }
    else
    {
        struct TBSTNode *current = root;
        struct TBSTNode *parent = NULL;
        while (1)
        {
            parent = current;
            if (data < current->data)
            {
                if (current->lthread == 0)
                {
                    current = current->left;
                }
                else
                {
                    newNode->left = current->left;
                    newNode->right = current;
                    current->left = newNode;
                    current->lthread = 0;
                    break;
                }
            }
            else
            {
                if (current->rthread == 0)
                {
                    current = current->right;
                }
                else
                {
                    newNode->left = current;
                    newNode->right = current->right;
                    current->right = newNode;
                    current->rthread = 0;
                    break;
                }
            }
        }
    }
    return root;
}

// Function to check if a path exists in the TBST
int pathExists(struct TBSTNode *root, int path[], int pathLength)
{
    // Write your solution here
}

// Main function for constructing the TBST and checking the path
int main()
{

    // Driver's Code
    int N, i;
    scanf("%d", &N);

    struct TBSTNode *root = NULL;

    for (i = 0; i < N; i++)
    {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }

    int pathLength;
    scanf("%d", &pathLength);

    int path[pathLength];
    for (i = 0; i < pathLength; i++)
    {
        scanf("%d", &path[i]);
    }

    if (pathExists(root, path, pathLength))
    {
        printf("Path exists.\n");
    }
    else
    {
        printf("Path does not exist.\n");
    }

    return 0;
}