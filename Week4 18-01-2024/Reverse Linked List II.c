/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(head==NULL) return head;
        if(head->next==NULL) return head;
        struct ListNode* start = head;
        int r1 = right;
        int l1 = left;
        struct ListNode* prevStart = NULL;
        while(--l1){
            prevStart = start;
            start = start->next;
        }
        struct ListNode* temp1 = NULL;
        struct ListNode* temp2 = NULL;
        struct ListNode* temp3 = start;
        r1 = right;
        while(r1-- > left - 1){
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3->next;
            temp2->next = temp1;
        }
        if(left > 1){
            prevStart->next = temp2;
        } else {
            head = temp2;
        }
        start->next = temp3;
        return head;
}
