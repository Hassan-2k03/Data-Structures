#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50

typedef struct node
{
    char info;
    struct node *left, *right;
} NODE;

typedef struct tree
{
    NODE *root;
} TREE;

typedef struct stack
{
    NODE *s[50];
    int top;
} STACK;

void init_trr(TREE *pt)
{
    pt->root = NULL;
}

void init_stack(STACK *ps)
{
    ps->top = -1;
}

int push(STACK *ps, NODE *e)
{
    if (ps->top == MAX - 1)
        return 0;
    ps->top++;
    ps->s[ps->top] = e;
    return 1;
}

NODE *pop(STACK *ps)
{
    // Assumption: empty condition checked before entering the pop
    NODE *t = ps->s[ps->top];
    ps->top--;
    return t;
}

// Expression Tree Evaluation
float eval(NODE *r)
{
    float res;
    switch (r->info)
    {
    case '+':
        return (eval(r->left) + eval(r->right));
        break;
    case '-':
        return (eval(r->left) - eval(r->right));
        break;
    case '*':
        return (eval(r->left) * eval(r->right));
        break;
    case '/':
        return (eval(r->left) / eval(r->right));
        break;
    default:
        return r->info - '0';
    }
    return res;
}

float eval_tree(TREE *pt)
{
    return eval(pt->root);
}

int main()
{
    char postfix[MAX];
    STACK sobj;
    TREE tobj;
    NODE *temp;
    init_stack(&sobj);
    printf("Enter a valid postfix expression\n");
    scanf("%s", postfix);
    int i = 0;
    while (postfix[i] != '\0')
    {
        temp = (NODE *)malloc(sizeof(NODE));
        temp->info = postfix[i];
        temp->left = NULL;
        temp->right = NULL;
        if (isdigit(postfix[i]))
            push(&sobj, temp);
        else
        {
            temp->right = pop(&sobj);
            temp->left = pop(&sobj);
            push(&sobj, temp);
        }
        i++;
    }
    tobj.root = pop(&sobj);
    printf("%f", eval_tree(&tobj));
    return 0;
}