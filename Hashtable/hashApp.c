/* Complete the function to find the most common element in the list of strings (list) using a hash table with separate
chaining. Implement a function find_most_common_key that takes the size of the list and the list of strings as input
and returns the most common string as output.

Note: Assume there will always be a majority element with highest number of frequency.

Input Format

3//Number of elements in the list apple //Elements in the list orange apple

Constraints

1<=Number of elements in the list<=1000

Output Format

apple

Sample Input 0

3
apple
orange
apple
Sample Output 0

apple
Explanation 0

The most common element in the list of strings is apple */

// solution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

int hashFunction(char *str)
{
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++)
        hash += str[i];
    return hash % TABLE_SIZE;
}

void insert(char *str, char *hashTable[TABLE_SIZE])
{
    int hash = hashFunction(str);
    while (hashTable[hash] != NULL)
        hash = (hash + 1) % TABLE_SIZE;
    hashTable[hash] = str;
}

char *findMostCommonKey(int n, char list[n][100])
{
    char *hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;
    for (int i = 0; i < n; i++)
        insert(list[i], hashTable);
    int max = 0, count = 0;
    char *mostCommon = (char *)malloc(100 * sizeof(char));
    for (int i = 0; i < TABLE_SIZE; i++)
        if (hashTable[i] != NULL)
        {
            count = 0;
            for (int j = 0; j < TABLE_SIZE; j++)
                if (hashTable[j] != NULL && strcmp(hashTable[i], hashTable[j]) == 0)
                    count++;
            if (count > max)
            {
                max = count;
                strcpy(mostCommon, hashTable[i]);
            }
        }
    return mostCommon;
}

int main()
{

    // Driver's Code
    int n;
    scanf("%d", &n);

    char list[n][100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", list[i]);
    }

    char *mostCommon = findMostCommonKey(n, list);

    if (mostCommon != NULL)
        printf("%s\n", mostCommon);

    return 0;
}
