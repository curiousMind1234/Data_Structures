vector<vector<int>> levelOrder(TreeNode* root) {
   vector<vector<int>>result;
    queue<TreeNode*> q;
    if(root==NULL)
        return {};
    
    q.push(root);
    while(!q.empty())
    {
        int count= q.size();
        vector<int>level;
        for(int i=0;i<count;i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if(node->left)
               q.push(node->left);
            if(node->right)
               q.push(node->right);

            level.push_back(node->val);
        }
        result.push_back(level);
    } 
    return result;
}

/*
Time Complexcity : O(N)
Space Complexcity : O(1)
*/
