#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct item
{
    int key, marks;
} item;

typedef struct hashtable
{
    int flag;
    item *data;
} hashtable;
hashtable *array;

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

int hash_function(int key)
{
    return (key % MAX);
}

void insert(int key, int value)
{
    item *ele = (item *)malloc(sizeof(item));
    ele->key = key;
    ele->marks = value;
    int i, index;
    i = hash_function(key);
    index = i;
    while (array[i].flag == 1)
    {
        if (array[i].data->key == key)
        {
            printf("Duplicate, !! update marks\n");
            array[i].data->marks = value;
            return;
        }
        i = (i + 1) % MAX;
        if (i == index)
        {
            printf("Hash table is full\n");
            return;
        }
    }
    array[i].flag = 1;
    array[i].data = ele;
}

void delete(int key)
{
    int index, i;
    i = hash_function(key);
    index = i;
    while (array[i].flag == 1)
    {
        if (array[i].data->key == key)
        {
            array[i].flag = 0;
            array[i].data = NULL;
            printf("Key deleted\n");
            return;
        }
        i = (i + 1) % MAX;
        if (i == index)
            break;
    }
    printf("Key not found\n");
}

void search(int key)
{
    int index, i;
    i = hash_function(key);
    index = i;
    while (array[i].flag == 1)
    {
        if (array[i].data->key == key)
        {
            printf("Key found at index %d\n", i);
            return;
        }
        i = (i + 1) % MAX;
        if (i == index)
            break;
    }
    printf("Key not found\n");
}

void display()
{
    for (int i = 0; i < MAX; i++)
    {
        if (array[i].flag == 0)
            printf("array[%d] has no elements\n", i);
        else 
            printf("array[%d] has elements -:\nKey: %d\tMarks: %d\n", i, array[i].data->key, array[i].data->marks);
    }
}

int main()
{
    int key, value, ch;
    array = (hashtable *)malloc(MAX * sizeof(hashtable));
    init();
    while (1)
    {
        printf("1. Insertion\t2. Deletion\t3. Display\t4. Search\t5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the key value: ");
            scanf("%d", &key);
            printf("Enter the marks: ");
            scanf("%d", &value);
            insert(key, value);
            break;
        case 2:
            printf("Enter the key value to be deleted: ");
            scanf("%d", &key);
            delete (key);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Enter the key value to be searched: ");
            scanf("%d", &key);
            search(key);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}