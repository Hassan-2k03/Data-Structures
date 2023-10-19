/* In a world shrouded in secrecy and intrigue, I found myself playing the role of a seasoned CIA agent. My mission was unlike any other, for it
 required me to unravel a web of connections and motives that had remained hidden for far too long.

Two notorious thieves were at the heart of this enigma, and my task was to find their lowest common ancestor, a shadowy figure who held the 
key to understanding their dark and clandestine alliance.

To crack this puzzle, I was presented with a peculiar map – a binary tree, a symbol of the complex network that underpinned the thieves' 
collaboration. However, this wasn't your typical tree; it was a tree of secrets, with each node representing a key player in the criminal 
underworld. The tree's layout was given to me in an unconventional format, a level order traversal, where -1 marked the absence of a node,
and every other number revealed a piece of the puzzle.

As I delved into the depths of this tree, I felt like an investigator on a mission to uncover the truth. Each number I encountered was a 
potential lead, an individual with their own role in this intricate drama. But my ultimate goal was to find the elusive lowest common ancestor
– the one node that had a direct connection to both thieves, the linchpin in their dark alliance.

This lowest common ancestor wasn't just any node; it was the pivotal character in this narrative, the one who could shed light on the motives 
behind their criminal activities. To identify this figure, I had to navigate the tree with precision, tracing the paths that led to each thief 
and meticulously searching for the point where their journeys converged.

The binary tree was a labyrinth of secrets, but I was determined to uncover the truth. With every step, I inched closer to the answer, 
analyzing the connections between nodes, following the paths that linked them, and finally, I found it – the lowest common ancestor, the key 
to understanding the thieves' connection and motive.

As I stood there, staring at the node that held the secrets of this dark alliance, I knew that I had unraveled a crucial piece of the puzzle. 
The lowest common ancestor was the link that connected the two thieves, and it was up to me to decipher the information hidden within 
this shadowy figure, revealing the truth behind their criminal endeavors and bringing them to justice.

Input Format

First line contains ‘n’ number of nodes in the tree,
Second line has level order traversal of the tree, with -1 as null nodes
The third line has 2 numbers, who are the thieves

Constraints

NA

Output Format

Single number that is the solution

Sample Input 0

11
1 2 3 -1 -1 4 -1 -1 5 -1 -1
3 5
Sample Output 0

3
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode *buildTree(int *levelOrder, int n)
{
    if (n <= 0)
        return NULL;

    struct TreeNode **queue = (struct TreeNode *)malloc(n * sizeof(struct TreeNode));
    struct TreeNode *root = createNode(levelOrder[0]);
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n)
    {
        struct TreeNode *currentNode = queue[front++];
        int leftVal = levelOrder[i++];
        if (leftVal != -1)
        {
            currentNode->left = createNode(leftVal);
            queue[rear++] = currentNode->left;
        }

        if (i < n)
        {
            int rightVal = levelOrder[i++];
            if (rightVal != -1)
            {
                currentNode->right = createNode(rightVal);
                queue[rear++] = currentNode->right;
            }
        }
    }

    free(queue);
    return root;
}

struct TreeNode *findLCA(struct TreeNode *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    struct TreeNode *leftLCA = findLCA(root->left, a, b);
    struct TreeNode *rightLCA = findLCA(root->right, a, b);

    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *levelOrder = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &levelOrder[i]);
    }

    int thief1, thief2;
    scanf("%d %d", &thief1, &thief2);

    struct TreeNode *root = buildTree(levelOrder, n);
    struct TreeNode *lca = findLCA(root, thief1, thief2);

    printf("%d\n", lca->data);

    // Free allocated memory
    free(levelOrder);

    return 0;
}