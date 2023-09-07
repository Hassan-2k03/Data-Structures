#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int compute(int op1, int op2, char symb)
{
    switch (symb)
    {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '*':
        return (op1 * op2);
    case '/':
        return (op1 / op2);
    case '$':
    case '^':
        return pow(op1, op2);
    }
}
int main()
{
    int s[100], top = -1, op1, op2, res;
    char symb, postfix[100];
    printf("Enter a valid Postfix Expression\n");
    fgets(postfix, 100, stdin);
    for (int i = 0; i < strlen(postfix); i++)
    {
        symb = postfix[i];
        if (isdigit(symb))
            s[++top] = symb - '0';
        else
        {
            op2 = s[top--];
            op1 = s[top--];
            res = compute(op1, op2, symb);
            s[++top] = res;
        }
    }
    res = s[top];
    printf("Result %d", res);
    return 0;
}