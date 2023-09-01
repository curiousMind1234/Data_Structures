int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int depth = max(maxDepth(root->left), maxDepth(root->right));

    return depth + 1;
}
