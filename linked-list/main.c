#include <stdio.h>
#include <assert.h>
#include "list.h"

int main()
{
    List *list;

    /* Create */
    list = slist_new();

    assert(list != NULL);
    assert(list->head == NULL);
    assert(list->tail == NULL);
    assert(list->length == 0);

    /* Add at head */
    slist_add_at_head(list, 10);

    assert(list->length == 1);
    assert(list->head->data == 10);
    assert(list->tail->data == 10);

    /* Add at tail */
    slist_add_at_tail(list, 20);

    assert(list->length == 2);
    assert(list->head->data == 10);
    assert(list->tail->data == 20);

    /* Add another at head */
    slist_add_at_head(list, 5);

    assert(list->length == 3);
    assert(list->head->data == 5);

    /* Peek */
    assert(list->head->data == 5);
    assert(list->tail->data == 20);

    /* Delete head */
    slist_delete_at_head(list);

    assert(list->length == 2);
    assert(list->head->data == 10);
    assert(list->tail->data == 20);

    /* Delete tail */
    slist_delete_at_tail(list);

    assert(list->length == 1);
    assert(list->head->data == 10);
    assert(list->tail->data == 10);

    /* Delete last node */
    slist_delete_at_head(list);

    assert(list->length == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);

    printf("All linked list tests passed!\n");

    return 0;
}