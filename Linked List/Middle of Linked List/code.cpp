ListNode* middleNode(ListNode* head) {
    //First Approach using counter
    int count = 0;
    ListNode* temp = head;
    while(temp){
        count++;
        temp = temp->next;
            
    }
    temp = head;
    for(int i=0;i<count/2;i++){
        temp = temp->next;
    }
    return temp;  
  
  //Second Approach using two pointers

    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    return slow;
}
