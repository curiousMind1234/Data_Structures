vector<int> topView(Node *root) {
    vector<int>ans;
    
    if(root == NULL){
        return ans;
    }
    map<int,int> topNode;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        
        Node* firstNode = temp.first;
        int hd = temp.second;
        
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = firstNode->data;
        }
        if(firstNode->left){
            q.push(make_pair(firstNode->left, hd-1));
        }
        if(firstNode->right){
            q.push(make_pair(firstNode->right, hd+1));
        }
    }
    for(auto i : topNode){
        ans.push_back(i.second);
    }
    return ans;
}
