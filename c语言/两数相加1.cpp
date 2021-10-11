struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
	if(!l2) return l1;
    struct ListNode*Newlist=(struct ListNode*)malloc(sizeof(struct ListNode)),*p=Newlist;
    int sum=0;
    while(l1||l2||sum){
        if(l1){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->val;
            l2=l2->next;
        }
	    p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	    p=p->next;
	    p->val=sum%10;
	    sum/=10;
    }
    p->next=NULL;
    return Newlist->next;
}
