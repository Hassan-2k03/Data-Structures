/* Write a C program that implements a basic dynamic array (a resizable array) using pointers. 
The information related to the dynamic array is maintained using the structure DynamicArray containing the fields: 
int*data: 
    pointer to the dynamic array 
Int size: 
    size of the dynamic array 
Int capacity:  
    capacity of the dynamic array 
Fill the functions (insert, delete) by following the instructions mentioned in the comments under the respective functions.

Note: choice represents the function which will be called. 1->insert 2->delete 3->display 4->exit 
Boiler code 

void insert(DynamicArray *arr, int index, int value) 
{ 
    //Fill the function to insert value into the dynamic array at a specified index 
    // The implementation should also take care of relloacating additional space for dynamic array if 
    //size becomes more than capacity
}

void delete(DynamicArray *arr, int index)
{ 
    // Fill the functino to delete value in the dynamic array at a specified index
}

void display(const DynamicArray *arr)
{

    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main()
{

    // Driver's Code

    DynamicArray myArray;
    int initialSize;

    initialize(&myArray, 1);

    int choice, index, value;

    while (1)
    {

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d %d", &index, &value);
            insert(&myArray, index, value);
            break;
        case 2:
            scanf("%d", &index);
            delete (&myArray, index);
            break;
        case 3:
            display(&myArray);
            break;
        case 4:
            free(myArray.data);
            return 0;
        }
    }

    return 0;
}

Input Format

1 //choice(inserting) 0 1 //index, value 1 1 2 1 2 3 3 //displaying final array 4

Constraints

NA

Output Format

1 2 3

Sample Input 0

1
0 1
1
1 2
1
2 3
3
4
Sample Output 0

1 2 3
Sample Input 1

1
0 1
1
1 2
1
2 3
1
3 4
1
4 5
2
1
3
4
Sample Output 1

1 3 4 5
Sample Input 2

1
0 1
1
1 2
1
2 3
1
3 2
1
4 7
2
1
3
4
Sample Output 2

1 3 2 7
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct DynamicArray
{
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initialize(DynamicArray *arr, int initialSize)
{
    arr->data= malloc(initialSize*sizeof(int));
    arr->size=0;
    arr->capacity=initialSize;
}

void insert(DynamicArray *arr, int index, int value)
{
    if (arr->size == arr->capacity)
    {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
    }
    for (int i = arr->size - 1; i >= index; i--)
    {
        arr->data[i + 1] = arr->data[i];
    }
    arr->data[index] = value;
    arr->size++;
}

void delete(DynamicArray *arr, int index)
{
    for (int i = index; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

void display(DynamicArray *arr)
{

    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main()
{

    // Driver's Code

    DynamicArray myArray;

    initialize(&myArray, 1);

    int choice, index, value;

    while (1)
    {

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d %d", &index, &value);
            insert(&myArray, index, value);
            break;
        case 2:
            scanf("%d", &index);
            delete (&myArray, index);
            break;
        case 3:
            display(&myArray);
            break;
        case 4:
            free(myArray.data);
            return 0;
        }
    }

    return 0;
}