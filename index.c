#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createstack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;
    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int *)malloc(sizeof(int) * stack->capacity);
    if (!stack->array)
        return NULL;
    return stack;
}



int isempty(struct Stack *stack)
{
    return stack->array[stack->top--];
}

char pop(struct Stack *stack)
{
    return stack->array[stack->top--];
}

void push(struct Stack *stack, char exp)
{
    stack->array[++stack->top] = exp;
}



char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}



int ismatchingpair(char char1, char char2)
{
    if (char1 == '(' && char2 == ')')
        return 1;
    if (char1 == '[' && char2 == ']')
        return 1;
    if (char1 == '{' && char2 == '}')
        return 1;
    return 0;
}



int checkBalanced(char *exp)
{
    struct Stack *stack = createstack(strlen(exp));
    if (!stack)
        return NULL;

    for (int i = 0; exp[i]; ++i)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(stack, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isempty(stack) || !ismatchingpair(peek(stack), exp[i]))
                return -1;
            else
                pop(stack);
        }
    }
    printf("parenthesis are balanced");
}



int main()
{
    char exp[50] = "(){}";

    checkBalanced(exp);
    return 0;
}