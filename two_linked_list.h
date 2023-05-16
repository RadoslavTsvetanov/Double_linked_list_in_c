#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode
{
    double value;
    struct ListNode *next;
    struct ListNode *prev;
};

typedef struct
{
    struct ListNode *head;
    struct ListNode *tail;
    int size;
} LinkedList;

LinkedList init();

struct ListNode *get(LinkedList *list, int index);

void push(LinkedList *list, int index, double value);
void pushback(LinkedList *list, double value);
void pushfront(LinkedList *list, double value);

double pop(LinkedList *list, int index);
double popfront(LinkedList *list);
double popback(LinkedList *list);
void set(LinkedList *list, int index, double value);
void freeList(LinkedList *list);
#endif