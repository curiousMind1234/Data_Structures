#include <algorithm>

vector<int> reverseLevelOrder(TreeNode<int> *root){
    queue<TreeNode<int>*> q;

    if(root==NULL)return {};
    q.push(root);

    vector<int>res;
    while(!q.empty()){   
       TreeNode<int> *temp = q.front();
       q.pop();
       res.push_back(temp->val);
       if (temp->left) {
           q.push(temp->left);
       }
       if(temp->right){
           q.push(temp->right);
       }
    }
    reverse(res.begin(), res.end());
    return res;
}
