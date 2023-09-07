 vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,multiset<int> > > nodes;
    vector<vector<int>> result;
    queue<pair<TreeNode*, pair<int,int> > > q;
    if(root == NULL){
        return result;
    }
    q.push(make_pair(root, make_pair(0,0)));
    
    while(!q.empty()){
        pair<TreeNode*, pair<int,int> > temp = q.front();
        q.pop();
            
        TreeNode* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].insert(frontNode->val);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd-1,lvl+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1,lvl+1)));
        }
    } 
    for(auto i : nodes){
        vector<int>ans;
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }                   
        }  
        result.push_back(ans); 
    }         
    return result;
}
