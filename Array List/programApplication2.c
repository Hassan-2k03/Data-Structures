/* Your friend wants to test your coding skills on Array’s and so he gives you an array ‘arr’ of integers of length ‘n’.
He asks you to implement a function to transform the array according to a set of rules. This function should transform the
given array arr in-place using the following rules:

Replace each even element with the sum of the previous and next elements.
Replace each odd element with the difference between the previous and next elements.
If the element does not have a previous element then the new element is obtained by adding it with the next element.
If the element does not have a next element then the new element is obtained by subtracting the previous element from it

For example: The array [1 2 3 4 5] becomes [3 4 -2 8 1]. that is [(1+2) (1+3) (2 - 4) (3 + 5) (5 - 4)]
Implement the function ‘transformArray’ to perform the array transformation as described above.

include void transformArray(int arr[], int n)
{ // Write your code here }

    // Driver Code int main() { int n; scanf("%d", &n); int arr[100]; // Assuming maximum array size of 100

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    transformArray(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

Input Format

The first line will contain an integer ‘n’ (1 <= n <= 100), the number of elements in the array. The second line will contain ‘n’ space-separated integers, the elements of the array.

Constraints

NA

Output Format

The transformed array of size n .

Sample Input 0

5
1 2 3 4 5
Sample Output 0

3 4 -2 8 1 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void transformArray(int arr[], int n)
{
    int arrTemp[100];
    for (int i = 0; i < n; i++)
        arrTemp[i] = arr[i];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            arr[0] = arrTemp[0] + arrTemp[1];
        else if (i == (n - 1))
            arr[n - 1] = arrTemp[i] - arrTemp[i - 1];
        else if ((i + 1) % 2 == 0)
            arr[i] = arrTemp[i - 1] + arrTemp[i + 1];
        else if ((i + 1) % 2 != 0)
            arr[i] = arrTemp[i - 1] - arrTemp[i + 1];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    transformArray(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    // printf(" ");
    printf("\n");
    return 0;
}