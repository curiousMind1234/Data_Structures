string kthChildNthGeneration(int n, long long int k)
{
	if(n==1 || k==1){
		return "Male";
	}

	string parent = kthChildNthGeneration(n-1,(k+1)/2);

	if (parent == "Male") {
        return (k % 2 != 0) ? "Male" : "Female";
    } else {
        return (k % 2 != 0) ? "Female" : "Male";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
