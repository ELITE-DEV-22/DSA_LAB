#ifndef _INCLUDED_STACK
#define _INCLUDED_STACK

#include <stdint.h>

#define MAX_DEPTH 32

typedef struct _stack_ Stack;

struct _stack_
{
    uint32_t size;
    int32_t top;
    float data[MAX_DEPTH];
};

struct _stack_result_
{
    float data;
    uint32_t status;
};

typedef struct _stack_result_ StackResult;

#define STACK_OK    1
#define STACK_FULL  2
#define STACK_EMPTY 4

Stack stack_new(uint32_t size);
Stack *stack_push(Stack *stk, float data, StackResult *result);
Stack *stack_pop(Stack *stk, StackResult *result);
Stack *stack_peek(Stack *stk, StackResult *result);
uint32_t stack_full(const Stack *stk);
uint32_t stack_empty(const Stack *stk);

#endif