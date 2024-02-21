int caluclateCapacity(vector<int>& weights, int cap){
    int capacity = 1;
    int totalCap = 0;
    for(int i=0;i<weights.size();i++){
        if(totalCap + weights[i] <= cap){
            totalCap+= weights[i];
        }
        else{
           capacity++;
           totalCap= weights[i];

        }
    }
    return capacity;
}
int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(),weights.end());
    int high =  accumulate(weights.begin(),weights.end(),0);

    while(low <= high){
        int mid = (low+high)/2;

        int calDays = caluclateCapacity(weights, mid);
        if(calDays <= days){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

/*
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countStudents() function for the value of ‘mid’. Now, inside the countStudents() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/
