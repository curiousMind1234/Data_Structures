ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
  //Brute Force Approach
    while(head2 != NULL) {
        ListNode* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;

    //**********************************************//
    //Using Hashing
    unordered_set<ListNode*> st;
    while(head1 != NULL) {
    st.insert(head1);
    head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
  //**************************************************//
  //Using length approach
  ListNode* d1 = head1;
  ListNode* d2 = head2;

  while(d1 != d2) {
      d1 = d1 == NULL? head2:d1->next;
      d2 = d2 == NULL? head1:d2->next;
  }
  
  return d1;
    
}
