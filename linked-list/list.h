#ifndef _INCLUDED_LIST
#define _INCLUDED_LIST

#include <stdint.h>

typedef struct _node_ Node;
typedef struct _list_ List;

struct _node_
{
    int32_t data;
    Node *next;
};

struct _list_
{
    Node *head;
    Node *tail;
    uint32_t length;
};


List *slist_new(void);
List *slist_free(List *list);


List *slist_add_at_head(List *list, int32_t data);
List *slist_add_at_tail(List *list, int32_t data);
List *slist_add_in_data(List *list, int32_t key, int32_t data);


List *slist_delete_at_head(List *list);
List *slist_delete_at_tail(List *list);


void slist_min_max(List *list);
List *slist_rev(List *list);

#endif