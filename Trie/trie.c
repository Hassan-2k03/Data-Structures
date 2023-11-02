#include <stdio.h>
#include <stdlib.h>

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
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 3);
    return 0;
}
