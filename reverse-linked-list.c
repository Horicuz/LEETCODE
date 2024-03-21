struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *nh, *p;
    p = head;

    while (p->next != NULL && (p->next)->next != NULL)
    {
        p = p->next;
    }

    nh = p->next;

    while (p != head)
    {  
        (p->next)->next = p;
        p->next = NULL;
        p = head;
        while (p->next != NULL && (p->next)->next != NULL)
        {
            p = p->next;
        }
    }

    (p->next)->next = p;
    p->next = NULL;

    return nh;
}

gh cop -> 

struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
