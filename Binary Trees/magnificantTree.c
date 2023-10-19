/* Once upon a time in a lush and vibrant forest, there stood a magnificent tree. This tree was not like any ordinary tree;
it was a binary tree, known for its intricate structure and beauty.
Each node of the tree was a living entity, holding a unique value greater than zero, symbolizing its own distinct character.

The tree's level order traversal was like a map of the forest, but it was presented in a rather unusual way.
Instead of telling you which nodes connected to which, it provided a list of values, where -1 indicated the absence of a node,
and the positive values were the essence of each node's existence.

The forest inhabitants were curious about the tree and wondered about its secrets. One day, they set themselves a challenge:
to find the length of the tree's width .The width of this binary tree was no ordinary measure. It was defined as the length of the longest
path between any two nodes in the tree, measured not in units of distance but in the number of nodes traversed.

To solve this intriguing problem, the forest dwellers needed to traverse the tree, carefully crossing the edges between nodes and
seeking the longest possible path( in the number of nodes traversed). They realized that this path might or might not pass through the root
of the tree, adding an extra layer of complexity to their quest.

As they embarked on their journey through the tree's level order traversal, they felt like explorers on a grand adventure.
Each -1 they encountered marked a momentary pause, where they had to acknowledge the absence of a node. But the positive values guided them
further, hinting at the existence of vibrant nodes waiting to be discovered.

Their goal was clear: find the length of the tree's width, the longest path between any two nodes, whether it involved the root or not.
With determination and a touch of wonder, they ventured deep into the heart of the binary tree, seeking to unlock the secrets of its width
and gain a deeper understanding of the intricate web of life it represented.

Input Format

First line contains ‘n’ number of nodes in the tree,
Second line has level order traversal of the tree, with -1 as null nodes

Constraints

NA

Output Format

Single integer

Sample Input 0

9
1 2 3 4 5 -1 6 -1 -1
Sample Output 0

5 */

// Solution

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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *buildTree(int *arr, int n, int index)
{
    struct TreeNode *root = NULL;
    if (index < n && arr[index] != -1)
    {
        root = createNode(arr[index]);
        root->left = buildTree(arr, n, 2 * index + 1);
        root->right = buildTree(arr, n, 2 * index + 2);
    }
    return root;
}

int depth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lDep = depth(root->left);
        int rDep = depth(root->right);

        if (lDep > rDep)
            return (lDep + 1);
        else
            return (rDep + 1);
    }
}

int Solution(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lDep = depth(root->left);
    int rDep = depth(root->right);

    int lDia = Solution(root->left);
    int rDia = Solution(root->right);

    int max = lDep + rDep + 1;
    if (lDia > rDia)
        return (lDia > max) ? lDia : max;
    else
        return (rDia > max) ? rDia : max;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct TreeNode *root = buildTree(arr, n, 0);

    int treeDiameter = Solution(root);
    printf("%d", treeDiameter);

    return 0;
}
