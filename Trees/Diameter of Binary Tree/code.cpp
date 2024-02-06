The diameter of a binary tree is the length of the longest path between any two nodes in a tree.

Naive Approach:

class Solution {
    private:
    int height(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int depth = max(height(root->left), height(root->right));
        return depth + 1 ;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->left) + height(root->right) ;

        int ans= max(op1, max(op2,op3));
        return ans;
    }
};

// but it takes extra O(N) time complexcity to calculate height so to optimise it use pair of diameter and height
// pair<int,int> p;
// p.first = stores Diameter
// p.second  = stores height

//Optimise Approach
class Solution {
public:

    pair<int,int> diameterFast(TreeNode* root){
        if(root == NULL) {
            pair<int,int>p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        pair<int,int> ans;
        ans.first = max(op1, max(op2,op3));
        ans.second = max(left.second , right.second) + 1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;
    }
};

/***********************************Another Approach which also taked O(N) TC and O(H) SC *******************************/
int height(TreeNode* root, int& diameter){
     if(root == NULL) return 0;

     int lh = height(root->left, diameter);
     int rh = height(root->right, diameter);
    
     diameter = max(diameter, lh+rh);

     return max(lh,rh)+1;
}
int diameterOfBinaryTree(TreeNode* root) {
   int diameter = 0;
   height(root, diameter);
   return diameter;
}
