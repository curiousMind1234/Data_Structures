//Naive Approach
class Solution {
    private:
    int height(TreeNode* root){
        if(root == NULL) 
        {
            return 0;   
        }
        int ans = max(height(root->left), height(root->right))+1 ;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = abs(height(root->left)-height(root->right))<=1;
        
       if(left && right && diff)
       {
          return true;
       }
       else {
           return false;
       }
    }
};

//Optimise Approach

class Solution {
public:
     pair<int,int> balanced(TreeNode* root){
        if(root == NULL) {
            pair<bool,int>p = make_pair(true,0);
            return p;
        }

        pair<bool,int> left = balanced(root->left);
        pair<bool,int> right = balanced(root->right);

        bool op1 = left.first;
        bool op2 = right.first;
        bool diff = abs(left.second - right.second)<=1;

        pair<bool,int> ans;
        ans.second = max(left.second,right.second) +1;

        if(op1 && op2 && diff){
           ans.first = true;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return balanced(root).first;
    }
};
