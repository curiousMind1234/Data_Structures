Node *lca(Node *root, int v1,int v2) {
    if(root == NULL)return NULL;
    
    if(root->data == v1 || root->data == v2){
        return root;
    }
    
    Node* left_node = lca(root->left, v1,v2);
    Node* right_node = lca(root->right, v1,v2);
    
    if(left_node != NULL && right_node != NULL) {
        return root;
    }
    
    // Otherwise, return the non-NULL node from left or right subtree
    return (left_node != NULL) ? left_node : right_node;
}

TC : O(N)
SC : O(height)
