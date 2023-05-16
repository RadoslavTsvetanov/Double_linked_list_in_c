#include <stdio.h>
#include "two_linked_list.h"

void printList(LinkedList *list)
{
    struct ListNode *current = list->head;
    while (current != NULL)
    {
        printf("%lf ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    LinkedList list1 = init();
    LinkedList list2 = init();

    // Push values to the first list
    pushback(&list1, 1.1);
    pushback(&list1, 2.2);
    pushback(&list1, 3.3);

    // Push values to the second list
    pushback(&list2, 4.4);
    pushback(&list2, 5.5);
    pushback(&list2, 6.6);

    printf("List 1:");
    printList(&list1);
    printf("List 2:");
    printList(&list2);
    double poppedValue = popfront(&list1);
    printf("%lf\n", poppedValue);
    push(&list2, 1, 7.7);
    printList(&list2);
    set(&list1, 2, 9.9);
    printList(&list1);

    return 0;
}
