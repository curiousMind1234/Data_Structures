ListNode* removeNthFromEnd(ListNode* head, int n) {
  //Brute force Approch
    ListNode* prev = NULL;
    ListNode* temp = head;
    if(temp->next == NULL) return NULL;

    int cnt = 0;       
    while(temp!=NULL){
        temp =  temp->next;
        cnt++;
    }
    temp = head;
    
    int count = cnt - n + 1;
    for(int i=1;i<count;i++){
        prev = temp;
        temp = temp->next;
    }
    //incase when prev is not updated
    if (prev == NULL) {
        head = head->next;
        return head;
    }
    else {
        prev->next = prev->next->next;
        return head;
    }
    return head;

   /*******************************************************/
  //Two Pointer Approach
  
    ListNode* start = new ListNode();
    start->next = head;
    ListNode* fast = start;
    ListNode* slow = start;

    for(int i = 1; i <=n;++i){
        fast = fast->next;
    }

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;

    return start->next;
}
