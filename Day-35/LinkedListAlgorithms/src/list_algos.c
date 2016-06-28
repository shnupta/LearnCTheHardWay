#include "list_algos.h"

List List_bubble_sort(List *list)
{
    int length = list->count;
    int swapped = 0;
    while(swapped != 1) {
        FOREACH(list, start, next, cur) {
            if(cur > next) {
                ListNode newNext = cur;
                ListNode newCur = next;
                cur = newCur;
                next = newNext;
                swapped = 1;
            }
        }
    }

    return list;
}
