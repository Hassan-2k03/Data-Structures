/* You are tasked with implementing a coffee ordering system in C using two stacks to manage customer orders.
The system should support the following operations:

placeOrder: Add a customer's coffee order to the system.
serveOrder: Serve and deliver the next coffee order to a customer.
isEmpty: Check if there are any pending orders in the system.

The coffee orders should be managed efficiently using two stacks. Each order represents a customer's coffee preference.

Your task is to complete the implementation of the coffee ordering system functions ( push,pop,placeOrder, serveOrder, isEmpty)
using the provided template and efficiently manage coffee orders using two stacks. The system should serve orders in a first-in,
first-out manner. Make sure the coffee ordering operations work correctly.

Input Format

n- no of test inputs
n lines of inputs each input can be in the form of:

placeOrder item
serveOrder
isEmpty

For Example:
6
placeOrder Cappuccino
placeOrder Espresso 
placeOrder Latte
serveOrder
serveOrder
isEmpty

Constraints

1<=n<=100

Output Format

Each output line can be in the form of one of the following:

Added order: item
Served order: item
There are pending orders.
The system is empty.
For Example:
Added order: Cappuccino 
Added order: Espresso
Added order: Latte
Served order: Cappuccino
Served order: Espresso
There are pending orders.

Sample Input 0

6
placeOrder Cappuccino
placeOrder Espresso
placeOrder Latte
serveOrder
serveOrder
isEmpty
Sample Output 0

Added order: Cappuccino
Added order: Espresso
Added order: Latte
Served order: Cappuccino
Served order: Espresso
There are pending orders. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the structure for a stack node to store coffee orders
struct StackNode
{
    char *coffee;
    struct StackNode *next;
};

// Define the structure for a stack to manage coffee orders
struct Stack
{
    struct StackNode *top;
};

// Function to create a new stack for coffee orders
struct Stack *createStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if a stack is empty
bool isStackEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

// Function to push a coffee order onto the stack
void push(struct Stack *stack, const char *coffee)
{
    struct StackNode *temp = (struct StackNode *)malloc(sizeof(struct StackNode));
    temp->coffee = (char *)malloc(strlen(coffee) + 1);
    strcpy(temp->coffee, coffee);
    temp->next = stack->top;
    stack->top = temp;
}

// Function to pop an element from a stack
char *pop(struct Stack *stack)
{
    if (isStackEmpty(stack))
    {
        return NULL;
    }
    struct StackNode *temp = stack->top;
    stack->top = stack->top->next;
    char *cof = temp->coffee;
    free(temp);
    return cof;
}

// Function to implement the coffee ordering system using two stacks
struct CoffeeOrderingSystem
{
    struct Stack *orderStack; // For placing orders
    struct Stack *serveStack; // For serving orders
};

// Function to create a new coffee ordering system
struct CoffeeOrderingSystem *createCoffeeOrderingSystem()
{
    struct CoffeeOrderingSystem *system = (struct CoffeeOrderingSystem *)malloc(sizeof(struct CoffeeOrderingSystem));
    system->orderStack = createStack();
    system->serveStack = createStack();
    return system;
}
// Function to place a coffee order
void placeOrder(struct CoffeeOrderingSystem *system, const char *coffee)
{
    push(system->orderStack, coffee);
}
// Function to serve a coffee order
char *serveOrder(struct CoffeeOrderingSystem *system)
{
    if (isStackEmpty(system->serveStack))
    {
        while (!isStackEmpty(system->orderStack))
        {   
            char *coffee = pop(system->orderStack);
            push(system->serveStack, coffee);
        }
    }
    return pop(system->serveStack);
}
// Function to check if there are any pending coffee orders
bool isEmpty(struct CoffeeOrderingSystem *system)
{
    return isStackEmpty(system->orderStack) && isStackEmpty(system->serveStack);
}

// Coffee ordering system
int main()
{
    struct CoffeeOrderingSystem *coffeeSystem = createCoffeeOrderingSystem();

    int numTestCases;
    scanf("%d", &numTestCases);

    while (numTestCases--)
    {
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "placeOrder") == 0)
        {
            char coffee[20];
            scanf("%s", coffee);
            placeOrder(coffeeSystem, coffee);
            printf("Added order: %s\n", coffee);
        }
        else if (strcmp(command, "serveOrder") == 0)
        {
            char *servedCoffee = serveOrder(coffeeSystem);
            if (servedCoffee)
            {
                printf("Served order: %s\n", servedCoffee);
            }
            else
            {
                printf("No more orders to serve.\n");
            }
        }
        else if (strcmp(command, "isEmpty") == 0)
        {
            if (isEmpty(coffeeSystem))
            {
                printf("The system is empty.\n");
            }
            else
            {
                printf("There are pending orders.\n");
            }
        }
    }

    return 0;
}
