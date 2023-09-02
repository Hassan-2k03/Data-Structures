/* Given a string ‘str’ implement a program to check whether it's possible to rearrange the characters of the string to
form a palindrome or not.

A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward.
Your task is to complete the function:
int canFormPalindrome(char str[])
    This function should return 1 if it's possible to rearrange the characters of the given string ‘str’ to form a palindrome,
    and 0 otherwise.

● Boilerplate:

int canFormPalindrome(char str[])
{ // Write your code here }

    // Driver code
    int main()
    {
        char str[1001];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
        int result = canFormPalindrome(str);
        if (result)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        return 0;
    }

    Input Format

    Each input consists of one line that will contain a string ‘str’ (1 <= len <= 1000), containing lowercase letters only.

    Constraints

    NA

    Output Format

    For each test case, the program will output: "YES" if it's possible to rearrange the characters of the string to form a palindrome. "NO" if it's not possible to rearrange the characters to form a palindrome.

    Sample Input 0

    racecar
    Sample Output 0

    YES */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int canFormPalindrome(char str[])
{
    int count[26] = {0};
    for (int i = 0; str[i]; i++)
    {
        count[str[i] - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] & 1)
        {
            odd++;
        }
        if (odd > 1)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int result = canFormPalindrome(str);
    if (result)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}