DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* curr = llist;
    DoublyLinkedListNode* temp_p = NULL;
    DoublyLinkedListNode* temp_n = NULL;
    
    while(curr !=NULL){
        temp_n = curr->next;
        curr->next = temp_p;
        curr->prev = temp_n;
        temp_p = curr;
        curr = temp_n;
           
    }
    
    return temp_p;  
}

TC : O(N)
SC : O(N)
