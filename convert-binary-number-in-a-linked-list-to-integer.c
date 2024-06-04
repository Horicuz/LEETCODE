/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode *head)
{
    while (head->next != NULL)
    {
        head->next->val = head->val * 2 + head->next->val;
        head = head->next;
    }
    return head->val;
}