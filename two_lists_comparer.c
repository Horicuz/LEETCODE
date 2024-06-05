#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

typedef struct Node NODE;

int compare_two_lists(NODE *head1, NODE *head2)
{
    // O(n) time complexity
    // hashing
    int hash[1000000];
    NODE *temp = head1;
    NODE *temp2 = head2;
    int matches = 0, numbers = 0;
    while (temp != NULL && temp2 != NULL)
    {
        if (hash[temp->val] == 1)
        {
            matches++;
            hash[temp->val]++;
        }
        else
        {
            hash[temp->val]++;
        }

        if (hash[temp2->val] == 1)
        {
            matches++;
            hash[temp2->val]++;
        }
        else
        {
            hash[temp2->val]++;
        }
        temp = temp->next;
        temp2 = temp2->next;
        numbers++;
    }
    if (temp != temp2)
    {
        printf("Not equal lengths\n");
        return 0;
    }
    else
    {
        if (matches == numbers)
        {
            printf("The two lists are equal\n");
            return 1;
        }
        else
        {
            printf("The two lists are not equal\n");
            return 0;
        }
    }
}

int main()
{
    NODE *head1, *head2;
    head1 = (NODE *)malloc(sizeof(NODE *));
    head2 = (NODE *)malloc(sizeof(NODE *));
    int v1[10] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int v2[10] = {10, 9, 8, 7, 6, 5};
    // read the lists
    NODE *temp = head1;
    for (int i = 0; i < 10; i++)
    {
        temp->val = v1[i];
        temp->next = (NODE *)malloc(sizeof(NODE *));
        temp = temp->next;
    }
    temp->next = NULL;

    temp = head2;
    for (int i = 0; i < 10; i++)
    {
        temp->val = v2[i];
        temp->next = (NODE *)malloc(sizeof(NODE *));
        temp = temp->next;
    }
    temp->next = NULL;

    printf("The two lists are %s\n", compare_two_lists(head1, head2) ? "equal" : "not equal");

    return 0;
}