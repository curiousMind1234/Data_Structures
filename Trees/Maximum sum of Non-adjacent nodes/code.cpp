pair<int,int> solve(Node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> leftSum = solve(root->left);
    pair<int,int> rightSum = solve(root->right);
    
    pair<int,int>res;
    res.first = root->data + leftSum.second + rightSum.second;
    res.second = max(leftSum.first,leftSum.second) + 
                       max(rightSum.first, rightSum.second);
                       
    return res;
    
}
int getMaxSum(Node *root) 
{
    pair<int,int>ans = solve(root);
    return max(ans.first,ans.second);
}
