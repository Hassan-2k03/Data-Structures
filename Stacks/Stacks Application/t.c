#include <stdio.h>
int main()
{
    char exp[100];
    int i = 0;
    char stack[100];
    int top = -1;
    printf("Enter the expression\n");
    scanf("%s", exp);
    for (int i = 0; exp[i] < '/0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            stack[++top] = exp[i];
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
            {
                printf("Unbalanced Expression\n");
                return 0;
            }
            else
            {
                if (exp[i] == ')' && stack[top] == '(')
                    stack--;
                else if (exp[i] == '}' && stack[top] == '{')
                    top--;
                else if (exp[i] == ']' && stack[top] == '[')
                    top--;
                else
                {
                    printf("Unbalanced Expression\n");
                    return 0;
                }
            }
        }
    }
}