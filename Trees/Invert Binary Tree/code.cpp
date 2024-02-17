/**********************************1st Approach*****************************************/
TreeNode* invertTree(TreeNode* root) {
    vector<int> data;
    TreeNode* node = root;
    helper(root, data);
    return node;
}
void helper(TreeNode* root, vector<int>& data) {
    if(!root)return ;    
    data.push_back(root->val);
    
    helper(root->right,data);
    helper(root->left,data);   
}

/**********************************2nd Approach*****************************************/

TreeNode* invertTree(TreeNode* root) {
   if(root==NULL)return root;
    if(root->left==NULL && root->right==NULL)return root;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    
    return root;    
}
