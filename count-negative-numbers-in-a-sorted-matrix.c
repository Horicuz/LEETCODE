#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *aux = headA;
    struct ListNode *aux2 = NULL;
    while (aux != NULL)
    {
        aux->val = aux->val + 100000;
        aux = aux->next;
    }
    aux = headB;
    while (aux != NULL)
    {
        if (aux->val > 100000)
        {
            if (aux2 == NULL)
            {
                aux2 = aux;
                aux2->val = aux2->val - 100000;
            }
            else
                aux->val = aux->val - 100000;
        }
        aux = aux->next;
    }
    aux = headA;
    while (aux != aux2)
    {
        aux->val = aux->val - 100000;
        aux = aux->next;
    }
    return aux2;
}