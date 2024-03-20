DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
       
    DoublyLinkedListNode* new_node = new DoublyLinkedListNode(data);  
    DoublyLinkedListNode* temp;
    
    // if list is empty  
    if(llist ==NULL){
        return new_node;
    }
     // if the node is to be inserted at the beginning 
    // of the doubly linked list 
    else if(llist->data >= data){
        new_node->next = llist;
        llist->next->prev = new_node;
        llist = new_node;
    }
    else{
        temp = llist;
         // locate the node after which the new node 
        // is to be inserted 
        while(temp->next!= NULL && temp->next->data < data){
            temp = temp->next;
        }
        
        new_node->next = temp->next;
        // if the new node is not inserted 
        // at the end of the list 
        if(temp->next!=NULL){
            new_node->next->prev = temp->next;
        }
        
        temp->next =  new_node;
        new_node->prev = temp;
     
    }
    return llist;
}


TC : O(N)
SC : O(N)
