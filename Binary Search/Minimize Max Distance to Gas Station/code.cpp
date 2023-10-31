int numberOfGasRequired(vector<int> &arr, long double diff){
	int cnt = 0;
	for(int i=1; i<arr.size();i++){
		int numsBetween = ((arr[i]-arr[i-1])/diff);
		// if((arr[i]-arr[i-1])/diff == numsBetween * diff ){
		// 	numsBetween--;
		// }
		cnt += numsBetween;
	}
	return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	long double low = 0, high=0;
	for(int i=0;i<n-1;i++){
		high = max(high, ((long double)(arr[i+1]-arr[i])));
	}
    long double diff = 1e-6;
	while(high-low > diff){
		long double mid = (low+high)/(2.0);

		int cnt = numberOfGasRequired(arr, mid);

		if(cnt > k){
			low = mid;
		}
		else{
			high = mid;
		}
	}
	return high;
	
}
