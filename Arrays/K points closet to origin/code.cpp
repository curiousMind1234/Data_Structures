Approach: The idea is to calculate the Euclidean distance from the origin for every given point and sort the array according to the Euclidean distance found. Print the first k closest points from the list.

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>>res;
    // In multimap values gets 
    // automatically sorted based on 
    // their keys which is distance here
    multimap<int, int>mp;
    
    for(int i=0;i<points.size();i++){
        int x = points[i][0], y = points[i][1];
        mp.insert({(x * x)+(y*y), i});
    }

    for(auto it = mp.begin(); it != mp.end() && k > 0; it++, k--) {
        res.push_back({points[it->second][0], points[it->second][1]});
    }
    return res;
}

Time Complexity: O(n log n). 
Time complexity to find the distance from the origin for every point is O(n) and to sort the array is O(n log n)
Space Complexity: O(n). 
As we are making an array to store distance from the origin for each point.
