vector<int> postOrder(Node* node) {
    vector<int> postOrder;
    Node* curr = node;
    
    while(curr!=NULL){
        
        if(curr->right == NULL){
            postOrder.push_back(curr->data);
            curr = curr->left;
        }
        else{
            Node* prev = curr->right;
            
            while(prev->left && prev->left!=curr){
                prev = prev->left;
            }
            if(prev->left == NULL){
                postOrder.push_back(curr->data);
                prev->left = curr;
                curr = curr->right;
            }
            else{
                prev->left = NULL;
                curr = curr->left;
            }
            
        }
    }
    reverse(postOrder.begin(), postOrder.end());
    return postOrder;
}
