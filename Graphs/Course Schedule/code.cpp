bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];

    for(auto it : prerequisites){
        adj[it[1]].push_back(it[0]);
    }

    vector<int>inorder(numCourses,0);
    for(int i =0;i<numCourses;i++){
        for(auto j : adj[i]){
            inorder[j]++;
        }
    }

    queue<int>q;
    for(int i =0;i<numCourses;i++){
        if(inorder[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto j : adj[node]){
            inorder[j]--;
            if(inorder[j]==0){
                q.push(j);
               
            }
        }
    }

    if(topo.size()==numCourses) return true;

    return false;
}

/*
Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes). Extra O(N) for storing the topological sorting. Total ~ O(3N).

*/
