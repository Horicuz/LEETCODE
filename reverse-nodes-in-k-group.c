struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *aux1, *aux2, *aux3, *aux4, *aux5;
    struct ListNode* newHead = head;
    int changed = 0;
    aux1 = head;
    aux2 = aux1;
    while (aux2 != NULL) {
        int isConnected = 0;
        int i;
        aux3 = aux1;
        for (i = 0; i < k && aux2 != NULL; i++) {
            aux2 = aux2->next;
        }
        if (i != k && aux2 == NULL) // if we have less than k elements left we dont want to reverse them
            return newHead;
        while (aux1->next != aux2) {
            aux4 = aux1;
            while (aux4->next->next != aux2) {
                aux4 = aux4->next;
            }
            aux4->next->next = aux1;
            if (isConnected == 0) {
                isConnected = 1;
                aux3 = aux4->next;
                if (changed == 1)
                    aux5->next = aux3;
                if (changed == 0) {
                    newHead = aux3;
                    changed = 1;
                }

            } else {
                aux3->next = aux4->next;
                aux3 = aux3->next;
            }
            aux4->next = aux2;
        }

        aux5 = aux1;
        aux1 = aux2;
    }

    return newHead;
}
