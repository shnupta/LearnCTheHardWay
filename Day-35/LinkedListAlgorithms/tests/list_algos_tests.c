#include "minunit.h"
#include <src/list_algos.h>
#include <assert.h>
#include <string.h>


char *test()
{
    List *list = List_create();
    List_push(list, 5);
    List_push(list, 4);
    List_push(list, 3);
    List_push(list, 2);
    List_push(list, 1);

    List_bubble_sort(list);

    return NULL;

}

char *test_all() {
    mu_suite_start();

    mu_run_test(test);

    return NULL;
}

RUN_TESTS(test_all);
