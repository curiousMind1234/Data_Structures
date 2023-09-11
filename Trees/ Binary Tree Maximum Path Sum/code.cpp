int solve(TreeNode* root, int &maxSum){
    if(root == NULL){
      return 0;
    }       
    int leftSum = solve(root->left, maxSum);
    int rightSum = solve(root->right, maxSum);

    int neeche_pura_ans = leftSum + rightSum + root->val ;
    int koi_ek_acha = max(leftSum, rightSum) + root->val;
    int root_acha = root->val;

    maxSum = max({maxSum, neeche_pura_ans, koi_ek_acha, root_acha} );
    return max(koi_ek_acha, root_acha );
}
int maxPathSum(TreeNode* root) {
    int sum = 0, len = 0, maxLen = 0;
    int maxSum = INT_MIN;
    solve(root,maxSum);
    return maxSum;        
}
