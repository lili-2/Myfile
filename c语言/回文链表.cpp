bool isPalindrome(struct ListNode* head) {
    if(head==NULL) return true;
    struct ListNode *fast,*slow,*p,*q=NULL;
    fast=slow=head;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    slow=slow->next;
    while(slow!=NULL){
        p=slow;
        slow=slow->next;
        p->next=q;
        q=p;
    }
    while(q!=NULL){
        if(q->val!=head->val){
            return false;
        }
        q=q->next;
        head=head->next;
    }
    return true;
}
