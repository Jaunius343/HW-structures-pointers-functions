#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    float x, y;
} Point;

typedef struct Stack{
    int capacity;
    Point *array;
}Stack;

void init_stack(Stack *stack);
void print_stack(Stack *stack);
int get_stack_size(Stack *stack);
void push(Stack *stack, Point p);
Point top(Stack *stack);
Point pop(Stack *stack);
void destroy_stack(Stack *stack);
void print_point (Point p);
Point create_point(double x, double y);

int main()
{
    Stack stack;

    init_stack(&stack);

    push(&stack, create_point(3, 2));
    push(&stack, create_point(1, 2));
    push(&stack, create_point(1, 1));
    push(&stack, create_point(0, 0));
    push(&stack, create_point(5, 2));
    print_stack(&stack);
    destroy_stack(&stack);

    return 0;
}

double get_distance(Point a, Point b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

Point create_point(double x, double y)
{
    Point p;

    p.x = x;
    p.y = y;

    return p;
}

void print_point (Point p)
{
    printf("(%0.1f, %0.1f)\n", p.x, p.y);
}

void destroy_stack(Stack *stack)
{
    free(stack->array);
    stack->capacity = 0;
}

Point pop(Stack *stack)
{
    Point last_element = top(stack);
    stack->capacity -= 1;
    stack->array = (int *)realloc(stack->array, sizeof(int) * stack->capacity);
    return last_element;
}

Point top(Stack *stack)
{
    if(stack->capacity > 0){
        Point last;
        last.x = stack->array[stack->capacity - 1].x;
        last.y = stack->array[stack->capacity - 1].y;
        return last;
    } else {
        Point last;
        last.x = 0;
        last.y = 0;
        return last;
    }
}

void push(Stack *stack, Point p)
{
    stack->capacity += 1;
    stack->array = (double *)realloc(stack->array, sizeof(double) * stack->capacity);
//    stack->array = (int *)malloc(sizeof(int) * stack->capacity);
//   printf("\n%d\n", sizeof(stack->array));
    stack->array[stack->capacity - 1].x = p.x;
    stack->array[stack->capacity - 1].y = p.y;
}



int get_stack_size(Stack *stack)
{
    return stack->capacity;
}

void print_stack(Stack *stack)
{
    if (stack->capacity >= 1){
        Point start;
        start.x = 0;
        start.y = 0;
        for(int i = 0; i < stack->capacity; ++i){
            printf("(%0.1f, %0.1f) ", stack->array[i].x, stack->array[i].y);
            printf("length: %0.1f\n", get_distance(stack->array[i], start));
        }
    } else {
        printf("%d ", 0);
    }
}

void init_stack(Stack *stack)
{
    stack->array = NULL;
    stack->capacity = 0;
}
