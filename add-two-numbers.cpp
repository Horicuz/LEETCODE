#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1->val == 0 && l1->next == nullptr)
    {
        return l2;
    }
    if (l2->val == 0 && l2->next == nullptr)
    {
        return l1;
    }
    ListNode *res = new ListNode();
    ListNode *head = res;
    int add = 0;
    while (l1 != nullptr && l2 != nullptr)
    {
        ListNode *temp = new ListNode((l1->val + l2->val + add) % 10);
        add = (l1->val + l2->val + add) / 10;
        res->next = temp;
        res = res->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    if (l1 == nullptr)
    {
        while (l2 != nullptr)
        {
            ListNode *temp = new ListNode((l2->val + add) % 10);
            add = (l2->val + add) / 10;
            res->next = temp;
            res = res->next;
            l2 = l2->next;
        }
    }
    else if (l2 == nullptr)
    {
        while (l1 != nullptr)
        {
            ListNode *temp = new ListNode((l1->val + add) % 10);
            add = (l1->val + add) / 10;
            res->next = temp;
            res = res->next;
            l1 = l1->next;
        }
    }

    if (add != 0)
    {
        ListNode *temp = new ListNode(add);
        res->next = temp;
    }

    return head->next;
}

int main()
{
    // l1 = [2,4,3], l2 = [5,6,4]

    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *res = addTwoNumbers(l1, l2);

    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}