bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //if target is > than current element then increment the row count as it is sorted array and 
    //if target < current element then decrement the column count and so on.
    int left = 0, right = matrix[0].size()-1;
    while(left < matrix.size() && right >= 0){
        if(matrix[left][right] == target){
            return true;
        } else if(matrix[left][right] < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return false;
}
