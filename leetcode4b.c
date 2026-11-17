/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *hd;
    struct ListNode *current;
    struct ListNode *last;
    current=head;
    while(current!=NULL){
        struct ListNode *a;
        a=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(current==head){
            a->val=current->val;
            a->next=NULL; 
            last=a;
            hd=a;
        }
        last->next=a;
        a->val=current->val;
        a->next=NULL;
        current=current->next;
        last=a;
    }
    current=hd;
    struct ListNode *nxt;
    struct ListNode *prev=NULL;
    while(current!=NULL){
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
    }
    hd=prev;
    current=hd;
    last=head;
    int pal=1;
    while(current!=NULL){
        if(current->val!=last->val){
            pal=0;
            printf("Not A Palindrome!");
            return false;
        }
        current=current->next;
        last=last->next;
    }
    return true;

}
