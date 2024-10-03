#include<bits/stdc++.h>
// long closestPair(pair<int, int>* coordinates, int n)
// {
//    long int miniDist = LONG_MAX;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            if(i==j) continue;
//            long int x = coordinates[i].first - coordinates[j].first;
//            long int y = coordinates[i].second - coordinates[j].second;

//            long int dist = x * x + y *y;

//            if(dist<miniDist){
//                miniDist = dist;
//            }
//        }
//    }
//    return miniDist;
// }

bool compare(pair<int, int>&a, pair<int, int>& b){
    return a.second < b.second;
}
long closestPair(pair<int, int>* coordinates, int n){
    sort(coordinates, coordinates+n);

    long long ans = INT_MAX;
    long long ans2 = INT_MAX;
    long long val, val2;

    for(int i=0;i<n-1;i++){
        long long x1 = coordinates[i].first - coordinates[i+1].first;
        long long y1 = coordinates[i].second - coordinates[i+1].second;

         val = x1 * x1 + y1 * y1;
         ans = min(val, ans);
    }

    sort(coordinates, coordinates+n, compare);

    for(int i=0;i<n-1;i++){
        long long x2 = coordinates[i].first - coordinates[i+1].first;
        long long y2 = coordinates[i].second - coordinates[i+1].second;

        val2 = x2*x2 + y2*y2;
        ans = min(val2, ans);
    }

    return ans;
}

//TC : O(nlogn)
