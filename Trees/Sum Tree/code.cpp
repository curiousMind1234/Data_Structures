pair<bool,int> isSumFast(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }
    
    pair<bool,int> leftSum = isSumFast(root->left);
    pair<bool,int> rightSum = isSumFast(root->right);
    
    bool val = root->data == leftSum.second + rightSum.second;
    
    pair<bool,int> ans;
    if(leftSum.first && rightSum.first && val){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
    }
    return ans;
}
bool isSumTree(Node* root)
{
     return isSumFast(root).first;
}
