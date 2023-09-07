// convert infix to postfix
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void push(char *s, int *top, char x)
{
    s[++(*top)] = x;
}

char pop(char *s, int *top)
{
    return s[(*top)--];
}

int input_precedence(char x)
{
    switch (x)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '$':
    case '^':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}

int stack_precedence(char x)
{
    switch (x)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '$':
    case '^':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}

void convert_infix_postfix(char *infix, char *postfix)
{
    char s[100],ch;
    int top = -1, i = 0, j = 0;
    push(s, &top, '#');
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        while (stack_precedence(s[top]) > input_precedence(ch))
            postfix[j++] = pop(s, &top);
        if (stack_precedence(s[top]) != input_precedence(ch))
            push(s, &top, ch);
        else
            pop(s, &top);        
    }
    while(s[top]!='#')
        postfix[j++]=pop(s,&top);
    postfix[j]='\0';
    
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter a valid Infix Expression\n");
    fgets(infix, 100, stdin);
    convert_infix_postfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
