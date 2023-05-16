#include "two_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

static struct ListNode *createnode(double value)
{
    struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newnode == NULL)
    {
        printf("Error allocating memory \n");
        exit(1);
    }
    newnode->value = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

LinkedList init()
{
    LinkedList list = {size : 0, head : NULL, tail : NULL};
    return list;
}

struct ListNode *get(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }

    struct ListNode *currentnode;
    if (index < list->size / 2)
    {
        currentnode = list->head;
        for (int i = 0; i < index; i++)
        {
            currentnode = currentnode->next;
        }
    }
    else
    {
        currentnode = list->tail;
        for (int i = list->size - 1; i > index; i--)
        {
            currentnode = currentnode->prev;
        }
    }

    return currentnode;
}

void push(LinkedList *list, int index, double value)
{
    if (index == 0)
    {
        pushfront(list, value);
        return;
    }

    struct ListNode *prev = get(list, index - 1);
    struct ListNode *newnode = createnode(value);
    newnode->next = prev->next;
    if (newnode->next)
    {
        newnode->next->prev = newnode;
    }
    prev->next = newnode;
    newnode->prev = prev;
    if (index == list->size)
    {
        list->tail = newnode;
    }
    list->size++;
}

void pushback(LinkedList *list, double value)
{
    push(list, list->size, value);
}

void pushfront(LinkedList *list, double value)
{
    struct ListNode *newnode = createnode(value);
    newnode->next = list->head;
    if (list->head)
    {
        list->head->prev = newnode;
    }
    list->head = newnode;
    if (list->size == 0)
    {
        list->tail = newnode;
    }
    list->size++;
}

double pop(LinkedList *list, int index)
{
    if (index == 0)
    {
        return popfront(list);
    }

    struct ListNode *prev = get(list, index - 1);
    struct ListNode *nodetodelete = prev->next;
    prev->next = nodetodelete->next;
    if (prev->next)
    {
        prev->next->prev = prev;
    }
    if (index == list->size - 1)
    {
        list->tail = prev;
    }
    list->size--;

    double result = nodetodelete->value;
    free(nodetodelete);
    return result;
}

double popfront(LinkedList *list)
{
    struct ListNode *nodetodelete = list->head;
    list->head = list->head->next;
    if (list->head)
    {
        list->head->prev = NULL;
    }
    else
    {
        list->tail = NULL;
    }
    list->size--;

    double result = nodetodelete->value;
    free(nodetodelete);
    return result;
}

double popback(LinkedList *list)
{
    pop(list, list->size - 1);
}

void set(LinkedList *list, int index, double value)
{
    struct ListNode *node = get(list, index);
    if (node != NULL)
    {
        node->value = value;
    }
}
void freeList(LinkedList *list)
{
    struct ListNode *current = list->head;
    while (current != NULL)
    {
        struct ListNode *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}