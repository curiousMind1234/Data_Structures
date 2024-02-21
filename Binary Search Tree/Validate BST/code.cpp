std:: vector<int>vec;
public:
    For BST inorder traversal must give sorted order
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        vec.clear();
        inorder(root);
        int size = vec.size()-1;
        // check if not sorted or duplicates exists
        for(int i =0 ;i <size; i++)
        {
            if(vec[i] >= vec[i+1])
                return false;
        }
        return true;
    }

/*
TC : O(n)
SC : O(n)
*/
