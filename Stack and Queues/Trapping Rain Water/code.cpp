int trap(vector<int>& height) {
  /*First Approach */
    int n = height.size();
    int res = 0;
    // for(int i=0;i<n;i++){
    //    int j = i;
    //    int leftMax = 0, rightMax = 0;
    //    while(j>=0){
    //        leftMax = max(leftMax, height[j]);
    //        j--;
    //    }
    //    j=i;
    //    while(j<n){
    //        rightMax = max(rightMax, height[j]);
    //        j++;
    //    }
    //    res += min(leftMax, rightMax) - height[i];
    // }
    // return res;


  /*Second Approach */
    int left = 0, right = n-1;
    int leftMax=0 , rightMax = 0;

    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= leftMax){
                 leftMax = height[left];
            }
            else{
                res += leftMax - height[left];
            }
            left++;
        }
        else{
            if(height[right] >= rightMax){
                 rightMax = height[right];
            }
            else{
                res += rightMax - height[right];
            }
            right--;
        }
    }
    return res;
}
