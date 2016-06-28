#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;

typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;

List *List_create();
void List_destroy(List *list);
void List_clear(List *list);
void List_clear_destroy(List *list);

#define List_count(A) ((A)->count) //returns number of elements in list
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL) //returns first element of list
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL) //returns last element of list

void List_push(List *list, void *value);
void *List_pop(List *list);

void List_unshift(List *list, void *value);
void *List_shift(List *list);

void *List_remove(List *list, ListNode *node);

//iterate over element in the list
#define LIST_FOREACH(L, S, N, C) ListNode *_node = NULL;\
    ListNode *C = NULL;\
    for(C = _node = L->S; _node != NULL; V = _node = _node->N)

#endif
