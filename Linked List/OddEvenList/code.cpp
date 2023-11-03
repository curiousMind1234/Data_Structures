ListNode* oddEvenList(ListNode* head) {
    ListNode* odd_head = new ListNode(0);
    ListNode* odd = odd_head;
    ListNode* even_head = new ListNode(0);
    ListNode* even = even_head;
    ListNode* curr  = head;
    int counter = 1;

    while(curr){
      //odd postioned
        if(counter%2 ==1){
            odd->next = curr;
            odd = odd->next;
        }
        else{
          //even positioned
            even->next = curr;
            even = even->next;
        }
      //increase current
        curr = curr->next;
        counter++;
    }
    //merge odd and even list
    odd->next = even_head->next;
    even->next = NULL;

    return odd_head->next;
}
