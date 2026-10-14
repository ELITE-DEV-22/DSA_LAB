#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static Node *_list_node_new(int32_t data)
{
    Node *node = (Node *)malloc(sizeof(Node));

    assert(node != NULL);

    node->data = data;
    node->next = NULL;

    return node;
}

List *slist_new(void)
{
    List *list = (List *)malloc(sizeof(List));

    assert(list != NULL);

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

List *slist_free(List *list)
{
    Node *cur;
    Node *p;

    assert(list != NULL);

    cur = list->head;

    while (cur != NULL)
    {
        p = cur;
        cur = cur->next;
        free(p);
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

List *slist_add_at_head(List *list, int32_t data)
{
    Node *node = _list_node_new(data);

    assert(list != NULL);

    node->next = list->head;
    list->head = node;

    if (list->tail == NULL)
    {
        list->tail = node;
    }

    ++list->length;

    return list;
}

List *slist_add_at_tail(List *list, int32_t data)
{
    Node *node = _list_node_new(data);

    assert(list != NULL);

    if (list->tail != NULL)
    {
        list->tail->next = node;
        list->tail = node;
    }
    else
    {
        list->head = node;
        list->tail = node;
    }

    ++list->length;

    return list;
}

List *slist_delete_at_head(List *list)
{
    Node *node;

    assert(list != NULL);

    if (list->head != NULL)
    {
        node = list->head;
        list->head = list->head->next;

        --list->length;

        if (list->head == NULL)
        {
            list->tail = NULL;
        }

        free(node);
    }

    return list;
}

List *slist_delete_at_tail(List *list)
{
    Node *node;
    Node *tail;

    assert(list != NULL);

    if (list->tail != NULL)
    {
        tail = list->tail;

        if (list->head == list->tail)
        {
            list->head = NULL;
            list->tail = NULL;
        }
        else
        {
            node = list->head;

            while (node->next != list->tail)
            {
                node = node->next;
            }

            list->tail = node;
            list->tail->next = NULL;
        }

        --list->length;
        free(tail);
    }

    return list;
}

List *slist_add_in_data(List *list, int32_t key, int32_t data)
{
    Node *cur;
    Node *node;

    assert(list != NULL);

    if (list->head != NULL)
    {
        cur = list->head;
        node = _list_node_new(data);

        while (cur != NULL && cur->data != key)
        {
            cur = cur->next;
        }

        if (cur != NULL)
        {
            node->next = cur->next;
            cur->next = node;

            if (node->next == NULL)
            {
                list->tail = node;
            }

            ++list->length;
        }
        else
        {
            free(node);
        }
    }

    return list;
}

void slist_min_max(List *list)
{
    Node *node;
    int32_t min;
    int32_t max;

    assert(list != NULL);

    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node = list->head;
    min = node->data;
    max = node->data;

    while (node != NULL)
    {
        if (node->data < min)
        {
            min = node->data;
        }

        if (node->data > max)
        {
            max = node->data;
        }

        node = node->next;
    }

    printf("Smallest value: %d\n", min);
    printf("Largest value: %d\n", max);
}

List *slist_rev(List *list)
{
    Node *prev = NULL;
    Node *cur;
    Node *next;

    assert(list != NULL);

    cur = list->head;
    list->tail = list->head;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    list->head = prev;

    return list;
}