List *slist_new() // function to create a new list
{
    List *list;                          // initialize a new pointer called list
    list = (List *)malloc(sizeof(List)); // memory allocation
    list->head = NULL;                   // head points to null
    list->tail = NULL;                   // tail points to null
    list->length = 0;                    // lenght is 0
    return list;
}

List *slist_free(List *list) // function to free a list
{
    Node *cur, *p;              // decalre 2 pointers cur and p
    if (slist_length(list) > 0) // check if the lenght of the list is greater than 0
    {
        assert(list->head && list->tail); // check if head and tail exist
        cur = list->head;                 // assign the list head into a temp cur
        list->head = NULL;                // delete that shi
        list->tail = NULL;                // delete that shi
        while (cur != NULL)               // keep looping while cur is NOT NULL
        {
            p = cur;          // assign the value of cur to p
            cur = list->next; // keep moving the cur forward
            free(p);          // delete that shi
            --list->length;   // decrement the list length
        }
    }
    return list;
}

static Node *_list_node_new(int32_t data)
{
    Node *node = (Node *)malloc(sizeof(Node))
                     node->data = data;
    node->next = NULL;
    return node;
}

List *slist_add_at_head(List *list, int32_t data)
{
    Node *node = _list_node_new();
    node->next = list->head;
    list->head = node;
    if (list->tail = Null)
    {
        list->tail = node
    }
    ++list->lenght;
    assert(list length == 1 && if list->head == list->tail) ||
        (list length > 0 && if list->head != list->tail)

            return list;
}

List *slist_add_at_tail(List *list, int32_t data)
{
    Node *node = _list_node_new();
    if (list->tail != NULL)
    {
        list->tail->next = node;
        list->tail = node;
    }
    else
    {
        list->tail = list->head = null;
    }
    --list->length;
    return list;
}

List *slist_delete_at_head(List *list)
{
    Node *node;
    if (list->head != NULL)
    {
        assert(list->length > 0)
            node = list->head
                       list->head = list->head->next;
        --list->length;
        if (list->head == NULL)
        {
            list->tail = NULL;
            assert(list->length == 0)
        }
        free(node);
    }
    return list;
}
List *slist_delete_at_tail(List *list)
{
    Node *node = list->head;
    for (node = list->head; node != NULL; node = node->next)
    {
        assert(list != NULL)
            Node *tail = list->tail;
        if (list->tail != NULL)
        {
            assert(list->length > 0) if (list->tail = list->head)
            {
                list->tail = list->head = NULL;
            }
            else
            {
                for (node = list->head; node->next != list->tail; node = node->next)
                    list->tail = node;
                list->tail->next = NULL;
                free(tail);
            }
            --list->length
        }
    }
    return list;
}
List *slist_add_in_data(List *list; int32_t key, int32_t data)
{
    if (list->head != NULL)
    {
        Node *cur = list->head;
        Node *node = _list_node_new(data);
        for (; cur != NULL && cur->data != key; cur = cur->next)
            ;
        if (cur != NULL)
        {
            node->next = cur->next;
            cur->next = node;
            if (node->next == NULL)
            {
                list->tail = node;
            }
        }
        ++list->length;
    }
    return list;
}

List *slist_add_on_data(List *lits, int32_t key, int32_t data)
{
    if (list->head != Null)
    {
        Node *cur = list->head;
        Node *node = _list_node_new(data);
        for (; cur != NULL && cur->data != Null; cur->next != Null)
            ;
        {
            node->next = cur->next;
            cur->next = node;
            if (node->next == NULL)
            {
                list->tail = node;
            }
        }
        ++list->length;
    }
    return list;
}

void slist_min_max(List *list)
{
    Node *node = list->head;
    int32_t min, max;
    if (head == NULL)
    {
        print("list is empty");
        return;
    }
    min = node->data;
    max = node->data;
    for (node = list->head; node != NULL; node = node->next)
    {
        if (node->data < min)
        {
            min = node->data;
        }
        if (node->data > max)
        {
            max = node->data;
        }
        print("Smallest value", min);
        print("Largest value", max);
    }
}

List *slist_rev(List *list){
    Node *prev = NULL;
    Node *cur = list->head;
    Node *next;
    list->tail = list ->head;
    while(cur != NULL){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    list -> head = prev;
}

List *slist_rev(List *list){
        Node *slow = *head;
        Node *fast = *head;
        while(fast!=NULL &&)
}