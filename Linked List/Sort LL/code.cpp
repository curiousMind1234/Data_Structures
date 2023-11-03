Node* merge(Node* left, Node* right){
    if(!left) return right;
    if(!right) return left;
    
    Node* res = NULL;
    if(left->data < right->data){
         res = left;
         res->next = merge(left->next, right);
    }
    else{
        res = right;
        res->next = merge(left, right->next);
    }
    return res;
}
Node* sortList(Node* head){
    if(head==NULL || head->next==NULL) return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }    
    Node* left = head;
    Node* right = slow->next;
    slow->next = NULL;

    left = sortList(left);
    right = sortList(right);
    return merge(left,right);
}
