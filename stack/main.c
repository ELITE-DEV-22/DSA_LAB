#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main()
{
    Stack s;
    StackResult result;

    /* Create stack with size 5 */
    s = stack_new(5);

    /* Test initial state */
    assert(s.size == 5);
    assert(s.top == -1);
    assert(stack_empty(&s) == 1);
    assert(stack_full(&s) == 0);

    /* Test push */
    stack_push(&s, 10.5, &result);
    assert(result.data == 10.5);
    assert(result.status == STACK_OK);
    assert(s.top == 0);

    stack_push(&s, 20.5, &result);
    assert(result.data == 20.5);
    assert(result.status == STACK_OK);
    assert(s.top == 1);

    stack_push(&s, 30.5, &result);
    assert(result.data == 30.5);
    assert(result.status == STACK_OK);
    assert(s.top == 2);

    /* Test peek */
    stack_peek(&s, &result);
    assert(result.data == 30.5);
    assert(result.status == STACK_OK);
    assert(s.top == 2);       // top should NOT change

    /* Test pop */
    stack_pop(&s, &result);
    assert(result.data == 30.5);
    assert(result.status == STACK_OK);
    assert(s.top == 1);

    /* Test peek after pop */
    stack_peek(&s, &result);
    assert(result.data == 20.5);
    assert(result.status == STACK_OK);
    assert(s.top == 1);

    /* Test more pop operations */
    stack_pop(&s, &result);
    assert(result.data == 20.5);
    assert(result.status == STACK_OK);
    assert(s.top == 0);

    stack_pop(&s, &result);
    assert(result.data == 10.5);
    assert(result.status == STACK_OK);
    assert(s.top == -1);

    /* Stack should now be empty */
    assert(stack_empty(&s) == 1);
    assert(stack_full(&s) == 0);

    /* Test pop on empty stack */
    stack_pop(&s, &result);
    assert(result.status == STACK_EMPTY);

    /* Test peek on empty stack */
    stack_peek(&s, &result);
    assert(result.status == STACK_EMPTY);

    printf("All stack tests passed!\n");

    return 0;
}