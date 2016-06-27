#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *List_create() //creates a main list struct
{
    return calloc(1, sizeof(List));
}

void List_destroy(List *list) //destroys a list and any elements it has
{
    LIST_FOREACH(list, first, next, cur) {
        if(cur->prev) {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}

void List_clear(List *list) { //clears the values of the nodes in the list NOT the actual nodes
    LIST_FOREACH(list, first, next, cur) {
        free(cur->value);
    }
}

void List_clear_destroy(List *list) //clears and destroys a list
{
    List_clear(list);
    List_destroy(list);
}

void List_push(List *list, void *value) //adds a new element to the end of the list
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(list->last == NULL) { //if empty its the only element so is both first and last
        list->first = node;
        list->last = node;
    } else { //if list isnt empty, set the new value to the next of the current last, then set the new nodes previous to the current last and then make the new node the last
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->count++;

error:
    return;
}

void *List_pop(List *list) //takes the last element and removes it.
{
    ListNode *node = list->last;
    return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List *list, void *value) //add element to the front of a list
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }

    list->count++;

error:
    return;
}

void *List_shift(List *list) //removes the first element
{
    ListNode *node = list->first;
    return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(List *list, ListNode *node) {
    void *result = NULL;

    check(list->first && list->last, "List is empty.");
    check(node, "Node can't be null.");

    if(node == list->first && node == list->last) { //if only element in list
        list->first = NULL;
        list->last = NULL;
    } else if(node == list->first) { //if its at the front
        list->first = node->next;
        check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
        list->first->prev = NULL;
    } else if (node == list->last) { //if its the last
        list->last = node->prev;
        check(list->last != NULL, "Invalid list, somehow got a next that is NULL.");
        list->last->next = NULL;
    } else { //if its in the middle somewhere
        ListNode *after = node->next;
        ListNode *before = node->prev;
        after->prev = before;
        before->next = after;
    }

    list->count--;
    result = node->value;
    free(node);

error:
    return result;
}
