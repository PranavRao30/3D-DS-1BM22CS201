/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
     if(head == NULL || head->next == NULL){
            return head;
        }
        int n = 0;
        struct ListNode* len = head;
        while(len->next != NULL){
            n++;
            len = len->next;
        }
        n++;
        k = k % n;
        while(k--){
            struct ListNode* prevTail = head;
            while(prevTail->next->next != NULL){
                prevTail = prevTail->next;
            }
            struct ListNode* tail = prevTail->next;
            tail->next = head;
            prevTail->next = NULL;
            head = tail;
        }
        return head;
}
