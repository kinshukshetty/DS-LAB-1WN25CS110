/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
       
        if (curr->next != NULL && curr->val == curr->next->val) {
            int dupVal = curr->val;
           
            while (curr != NULL && curr->val == dupVal) {
                struct ListNode* temp = curr;
                curr = curr->next;
                free(temp);
            }
            
            prev->next = curr;
        } else {
            
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}
