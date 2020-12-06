#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int capacity;
    int *array;
}Stack;

void init_stack(Stack *stack);
void print_stack(Stack *stack);
int get_stack_size(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroy_stack(Stack *stack);

int main()
{
    Stack stack;

    init_stack(&stack);

    push(&stack, 3);
    push(&stack, 1);
    push(&stack, 1);
    push(&stack, 0);
    print_stack(&stack);
    printf("\n%d\n", get_stack_size(&stack));

    pop(&stack);
    pop(&stack);
    printf("\n");
    print_stack(&stack);
    printf("\n%d\n", top(&stack));
    printf("%d\n", get_stack_size(&stack));
    destroy_stack(&stack);
    printf("%d\n", get_stack_size(&stack));

    return 0;
}

void destroy_stack(Stack *stack)
{
    free(stack->array);
    stack->capacity = 0;
}

int pop(Stack *stack)
{
    int last_element = top(stack);
    stack->capacity -= 1;
    stack->array = (int *)realloc(stack->array, sizeof(int) * stack->capacity);
    return last_element;
}

int top(Stack *stack)
{
    if(stack->capacity > 0){
        return stack->array[stack->capacity - 1];
    } else {
        return 0;
    }
}

void push(Stack *stack, int value)
{
    stack->capacity += 1;
    stack->array = (int *)realloc(stack->array, sizeof(int) * stack->capacity);
//    stack->array = (int *)malloc(sizeof(int) * stack->capacity);
//   printf("\n%d\n", sizeof(stack->array));
    stack->array[stack->capacity - 1] = value;
}



int get_stack_size(Stack *stack)
{
    return stack->capacity;
}

void print_stack(Stack *stack)
{
    if (stack->capacity >= 1){
        for(int i = 0; i < stack->capacity; ++i)
            printf("%d ", stack->array[i]);
    } else {
        printf("%d ", 0);
    }
}

void init_stack(Stack *stack)
{
    stack->array = NULL;
    stack->capacity = 0;
}
