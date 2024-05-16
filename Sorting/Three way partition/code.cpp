void threeWayPartition(vector<int>& arr,int a, int b)
{
    int start=0, end = arr.size()-1;
    
    for(int i=0;i<=end;){
        if(arr[i] < a){
            if(i==start){
                i++;
                start++;
            }
            else{
                swap(arr[i++], arr[start++]);
            }
            
        }
        
        else if(arr[i] > b){
            swap(arr[i], arr[end--]);
        }
        else{
            i++;
        }
    }
}

/*
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
