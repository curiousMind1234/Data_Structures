int makeBeautiful(string str) {
	int n = str.size();
    int count1 = 0;
    int count2 = 0;
	
    for (int i = 0; i<n; i++){
        if (i%2==0){
            if (str[i] == '1'){
                count1++;
            }
            if (str[i] == '0'){
                count2++;
            }
        }
        if (i%2 == 1){
            if (str[i] == '1'){
                count2++;
            }
            if (str[i] == '0'){
                count1++;
            }

        }

    }

    return min(count1,count2);  
}

/*
TC: O(N)
SC:O(1)
*/
