#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie_node
{
    int eow;
    struct trie_node *child[255];
} trie;

trie *create_trie_node()
{
    trie *node = (trie *)malloc(sizeof(trie));
    node->eow = 0;
    for (int i = 0; i < 255; i++)
    {
        node->child[i] = NULL;
    }
    return node;
}

/* void insert(trie *root, char *str) {
    trie *temp = root;
    while(*str) {
        if(temp->child[*str] == NULL) {
            temp->child[*str] = create_trie_node();
        }
        temp = temp->child[*str];
        str++;
    }
    temp->eow = 1;
} */

// use for loop insert
void insert(trie *root, char *str)
{
    trie *temp = root;
    for (int i = 0; str[i]; i++)
    {
        if (temp->child[str[i]] == NULL)
            temp->child[str[i]] = create_trie_node();
        temp = temp->child[str[i]];
    }
    temp->eow = 1;
}

char str[100];
int lenngth = 0;

void search(trie *root, char *str)
{
    trie *temp = root;
    while (*str)
    {
        if (temp->child[*str] == NULL)
        {
            printf("String not found\n");
            return;
        }
        temp = temp->child[*str];
        str++;
    }
    if (temp->eow == 1)
        printf("String found\n");
    else
        printf("String not found\n");
}

void display(trie *root)
{
    if (root->eow == 1)
    {
        str[lenngth] = '\0';
        printf("%s\n", str);
    }
    for (int i = 0; i < 255; i++)
    {
        if (root->child[i] != NULL)
        {
            str[lenngth++] = i;
            display(root->child[i]);
            lenngth--;
        }
    }
}

void displayPrefix(trie *root, char *prefix, int index)
{
    if (root->eow == 1)
    {
        prefix[index] = '\0';
        printf("%s\n", prefix);
    }
    for (int i = 0; i < 255; i++)
    {
        if (root->child[i] != NULL)
        {
            prefix[index++] = i;
            displayPrefix(root->child[i], prefix, index);
            index--;
        }
    }
}

int isEmpty(trie *root)
{
    for (int i = 0; i < 255; i++)
    {
        if (root->child[i] != NULL)
            return 0;
    }
    return 1;
}

trie *delete(trie *root, char *key, int depth)
{
    if (root==NULL)
        return NULL;
    if (depth == strlen(key))
    {
        if (root->eow)
            root->eow = 0;
        if (isEmpty(root))
        {
            free(root);
            root = NULL;
        }
        return root;
    }
    int index = key[depth];
    root->child[index] = delete(root->child[index], key, depth + 1);
    if (isEmpty(root) && root->eow == 0)
    {
        free(root);
        root = NULL;
    }
    return root;
}

int main()
{
    trie *root = create_trie_node();
    int ch, n;
    char str[100];
    do
    {
        printf("1. Insert\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the string: ");
            scanf("%s", str);
            insert(root, str);
            break;
        case 2: 
            display(root);
            break;
        case 3:
            printf("Enter the prfix\n");
            scanf("%s", str);
            displayPrefix(root, str, 0);
            break;
        case 4:
            printf("Enter the string to be searched\n");
            scanf("%s", str);
            search(root, str);
            break;
        case 5: 
            printf("Enter the string to be deleted\n");
            trie *temp = delete(root, str, 0);
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 3);
    return 0;
}
