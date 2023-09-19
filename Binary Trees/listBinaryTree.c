#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

void insert(NODE **root, int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = ele;
    temp->left = temp->right = NULL;
    if (*root == NULL)
    {
        *root = temp;
        return;
    }
    NODE *cur = *root;
    NODE *prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        if (ele < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (ele < prev->data)
        prev->left = temp;
    else
        prev->right = temp;
}

void inorder(NODE *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void preorder(NODE *root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}
int max(NODE *root)
{
    NODE *cur = root;
    if (cur == NULL)
        return -1;
    while (cur->right != NULL)
        cur = cur->right;
    return cur->data;
}

// iterative method for search
/* void search(NODE *root, int ele)
{
    if (root == NULL)
        printf("Tree is empty\n");
    else
    {
        NODE *cur = root;
        while (cur != NULL)
        {
            if (ele == cur->data)
            {
                printf("Element found\n");
                return;
            }
            else if (ele < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        printf("Element not found\n");
    }
}
 */

// recursive method for search
NODE *search(NODE *root, int ele)
{
    if (root == NULL)
        printf("Tree is empty\n");
    else
    {
        if (root == NULL || root->data == ele)
            return root;
        else if (ele < root->data)
            return search(root->left, ele);
        else
            return search(root->right, ele);
    }
}

// count leaves iterative method
/* int countLeaves(NODE *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    NODE *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL && cur->right == NULL)
            count++;
        if (cur->left != NULL)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return count;
} */

int countLeaves(NODE *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// iterative method for max depth
/* int maxDepth(NODE *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    NODE *cur = root;
    while (cur != NULL)
    {
        if (cur->left != NULL)
            cur = cur->left;
        else
            cur = cur->right;
        count++;
    }
    return count;
} */

// recursive method for max depth
int maxDepth(NODE *root)
{
    if (root == NULL)
        return 0;
    int ldepth = maxDepth(root->left);
    int rdepth = maxDepth(root->right);
    if (ldepth > rdepth)
        return ldepth + 1;
    else
        return rdepth + 1;
}

int countNodes(NODE *root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// iterative method for delete
/* NODE *delete (NODE *root, int ele)
{
    if (root == NULL)
        return NULL;
    NODE *cur = root;
    NODE *prev = NULL;
    while (cur != NULL)
    {
        if (ele == cur->data)
            break;
        prev = cur;
        if (ele < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (cur == NULL)
        return NULL;
    if (cur->left == NULL && cur->right == NULL)
    {
        if (prev == NULL)
            root = NULL;
        else if (prev->left == cur)
            prev->left = NULL;
        else
            prev->right = NULL;
        free(cur);
    }
    else if (cur->left == NULL)
    {
        if (prev == NULL)
            root = cur->right;
        else if (prev->left == cur)
            prev->left = cur->right;
        else
            prev->right = cur->right;
        free(cur);
    }
    else if (cur->right == NULL)
    {
        if (prev == NULL)
            root = cur->left;
        else if (prev->left == cur)
            prev->left = cur->left;
        else
            prev->right = cur->left;
        free(cur);
    }
    else
    {
        NODE *temp = cur->right;
        while (temp->left != NULL)
            temp = temp->left;
        cur->data = temp->data;
        cur->right = delete (cur->right, temp->data);
    }
    return root;
} */

// recursive method for delete
NODE *delete(NODE *root, int ele)
{
    if (root == NULL) 
        return NULL;
    if (ele < root->data)
        root->left = delete (root->left, ele);
    else if (ele > root->data)
        root->right = delete (root->right, ele);
    else
    {
        if (root->left == NULL)
        {
            NODE *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            NODE *temp = root->left;
            free(root);
            return temp;
        }
        NODE *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

int main()
{
    NODE *root = NULL, *res = NULL;
    int ele, ch;
    while (1)
    {
        printf("1. Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Max\n");
        printf("6.Search\n7.Count Leaf Nodes\n8.Max Depth|Height of Tree\n9.Total Nodes\n10.Total Non Leaf Nodes\n");
        printf("11.Delete Element\nEnter your choice:\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element:\n");
            scanf("%d", &ele);
            insert(&root, ele);
            break;
        case 2:
            printf("Inorder traversal\n");
            inorder(root);
            break;

        case 3:
            printf("Preorder traversal\n");
            preorder(root);
            break;

        case 4:
            printf("Postorder traversal\n");
            postorder(root);
            break;
        case 5:
            printf("Maximum element is %d\n", max(root));
            break;
        case 6:
            printf("Enter the element to be searched\n");
            scanf("%d", &ele);
            // search(root, ele);
            res = search(root, ele);
            if (res == NULL)
                printf("Element not found\n");
            else
                printf("Element found\n");
        case 7:
            printf("Number of leaves are %d\n", countLeaves(root));
            break;
        case 8:
            printf("Maximum depth is %d\n", maxDepth(root));
            break;
        case 9:
            printf("total number of nodes are %d\n", countNodes(root));
            break;
        case 10:
            printf("total number of non leaf nodes are %d\n", countNodes(root) - countLeaves(root));
            break;
        case 11:
            printf("Enter the element to be deleted\n");
            scanf("%d", &ele);
            NODE *x = delete (root, ele);
            if (x == NULL)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element deleted\n");
                root = x;
            }
            break;
        default:
            exit(0);
        }
    }
}