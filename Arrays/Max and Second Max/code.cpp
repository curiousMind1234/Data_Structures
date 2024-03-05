vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){  
    int first = 0, second = -1, n = 0;
    for(int i=1; i<sizeOfArray;i++){
        if(arr[i] > arr[first]){
            second = first;
            first = i;
        }
        else if(arr[i] < arr[first]){
            if(second == -1 || arr[second] < arr[i]){
                second = i;
            }
        }
    }
    if(second == -1){
        return {arr[first], second};
    }
    return {arr[first], arr[second]};
}

/*
Time Complexity: O(N).
Auxiliary Space: O(1).

*/
