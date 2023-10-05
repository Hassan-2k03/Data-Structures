/* Operations on Binary Search Tree - BST

Implement the following functions for BST:
1. Insert(struct TreeNode* root, int value): Insert a new node with a given integer value.
2. deleteNode(struct TreeNode* root, int value): Deletion of a node with a given integer value. if value is not given then do nothing.
3. countNodesInRange(struct TreeNode* root, int L, int R): Create a function that counts the number of nodes in the BST with values falling
    within a given range [L, R].
4.getHeight(struct TreeNode* node): Write a function to find the height of a bst.

Input Format

first line: n- no. of operation to be performed followed by n operations
For operation 1:
1
e - element to be inserted
For operation 2:
2
e - element to be deleted
For operation 3:
3
L R- lower limit (space) upper limit
For operation 4:
4
For example:
7
1
2
1
1
1
3
1
4
2
1
3
2 4 4

Constraints

1<=n<=8

Output Format

n outputs for n operations: For operation 1:
space separated elements of bst after insertion For operation 2:
space separated elements of bst after deletion
For operation 3:
a number which is the number of nodes in range [L,R]
For operation 4:
Height of the Tree : h- height of the tree
2
1 2
1 2 3
1 2 3 4
2 3 4
3
Height of tree 3

Sample Input 0

7
1
2
1
1
1
3
1
4
2
1
3
2 4
4
Sample Output 0

2
1 2
1 2 3
1 2 3 4
2 3 4
3
Height of tree 3  */

// Code:

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct TreeNode *insert(struct TreeNode *root, int value)
{
    struct TreeNode *temp = createNode(value);
    
    temp->data = value;
    temp->left = temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    struct TreeNode *cur = root;
    struct TreeNode *prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        if (value < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (value < prev->data)
        prev->left = temp;
    else
        prev->right = temp;
    return root;
}

struct TreeNode *deleteNode(struct TreeNode *root, int value)
{
    // Function to delete a new node into the BST
    if (root == NULL) 
        return NULL;
    if (value < root->data)
        root->left = deleteNode (root->left, value);
    else if (value > root->data)
        root->right = deleteNode (root->right, value);
    else
    {
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode (root->right, temp->data);
    }
    return root;
}

// Function to count nodes within a given range [L, R]
int countNodesInRange(struct TreeNode *root, int L, int R)
{
    if (root == NULL)
        return 0;
    if (root->data >= L && root->data <= R)
        return countNodesInRange(root->left, L, R) + countNodesInRange(root->right, L, R) + 1;
    else if (root->data > L)
        return countNodesInRange(root->left, L, R);
    else
        return countNodesInRange(root->right, L, R);
}

// Function to calculate the height of a tree
int getHeight(struct TreeNode *node)
{
    if (node == NULL)
        return 0;
    int ldepth = getHeight(node->left);
    int rdepth = getHeight(node->right);
    if (ldepth > rdepth)
        return ldepth + 1;
    else
        return rdepth + 1;
}
void displayNodesInOrder(struct TreeNode *root)
{
    if (root != NULL)
    {
        // Display left subtree
        displayNodesInOrder(root->left);

        // Display current node's data
        printf("%d ", root->data);

        // Display right subtree
        displayNodesInOrder(root->right);
    }
}

void display(struct TreeNode *root)
{
    displayNodesInOrder(root);
    printf("\n");
}

int main()
{
    struct TreeNode *root = NULL;
    int choice, value, h;
    int n;
    int L, R;
    scanf("%d", &n);
    while (n)
    {

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            scanf("%d", &value);
            root = insert(root, value);
            display(root);
            break;

        case 2:

            scanf("%d", &value);
            root = deleteNode(root, value);
            display(root);
            break;
        case 3:

            scanf("%d %d", &L, &R);
            int count = countNodesInRange(root, L, R);
            printf("%d\n", count);
            break;
        case 4:
            h = getHeight(root);
            printf("Height of tree %d ", h);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
        n--;
    }

    return 0;
}