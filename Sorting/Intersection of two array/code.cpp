vector<int> printIntersection(int arr1[], int arr2[], int N, int M) 
{ 
    vector<int> res;
    int i=0,j=0;
    while(i<N && j<M){
        if (i > 0 && arr1[i] == arr1[i - 1]) {        //For Handling duplicates
            i++;
            continue;
        }
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr2[j] < arr1[i]){
            j++;
        }
        else{
            res.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    if(res.empty()){
         res.push_back(-1);
    }
    return res;
}

Time Complexity : O(m + n)
Auxiliary Space: O(1)
