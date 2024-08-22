/*You are a coach of a group consisting of 'N' students. The ith student has a strength Arr[i]. For a Tug of War game, you want to divide students into two teams of equal size (If N is odd, then size of one team should be (N-1)/2 and size of other team should be (N+1)/2). You want a game that is fun, for this the absolute difference between the team’s strength should be as minimum as possible. A team's strength is the sum of the strengths of the students in the team.*/


//1st Approach
#include <bits/stdc++.h> 
int partition(vector<int>& arr, int selectedStundent, int idx,
   int currSum, int& total_sum, int n){
 
    if(selectedStundent >= (n+1)/2){
        return abs(total_sum - 2*currSum);
    }  

    int res = INT_MAX -1;
    for (int i=idx;i<n;i++){
        int mx = partition(arr, selectedStundent+1, i+1, 
        currSum+arr[i],total_sum,n);

        res = min(res, mx);
    }
    return res;
}
int tugOfWar(vector<int> &arr, int n)
{
    int total_sum = 0;
    for(int i=0;i<n;i++){
        total_sum += arr[i];
    }

    return partition(arr, 0, 0,0, total_sum, n);
    //return minDiff;
}

//2nd Approach
#include <bits/stdc++.h> 
void partition(vector<int>& arr, int selectedStudent, int idx,
   int currSum, int& minDiff, int& total_sum, int n){

    if(selectedStudent == n/2 || (n % 2 != 0 && selectedStudent == (n + 1) / 2)){
        minDiff = min(minDiff, abs(total_sum - 2*currSum));
        return;
    }  

    if(idx == n) return;     

    //include student
    partition(arr, selectedStudent+1, idx+1, currSum+arr[idx], 
    minDiff, total_sum, n);

    //exclude student
    partition(arr, selectedStudent, idx+1, currSum, 
    minDiff, total_sum, n);

}
int tugOfWar(vector<int> &arr, int n)
{
    int total_sum = 0;
    for(int i=0;i<n;i++){
        total_sum += arr[i];
    }

    int minDiff = INT_MAX;
    partition(arr, 0, 0,0, minDiff, total_sum, n);
    return minDiff;
}


Time Complexity: O(2n)
Auxiliary Space Complexity: O(1)
