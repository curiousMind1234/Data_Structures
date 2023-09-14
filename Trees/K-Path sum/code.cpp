 void solve(TreeNode* root, int &count, vector<int> path, int targetSum){
    if(root == NULL) return;

    path.push_back(root->val);

    solve(root->left, count, path, targetSum);
    solve(root->right, count, path, targetSum);

    int size = path.size();
    long int sum = 0;
    for(int i=size-1;i>=0;i--){
        sum += path[i];
        if(sum == targetSum)
           count++;
    }
    path.pop_back();
}

int pathSum(TreeNode* root, int targetSum) {
    vector<int>path;
    int count = 0;
    solve(root, count, path,targetSum);
    return count;
}
