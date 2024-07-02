string encode(string &message)
{
    int count =1;
    string res = "";
    for(int i=1;i<=message.length();i++){
        if(message[i]!=message[i-1]){
            res += message[i-1];
            res += to_string(count);
            count =1;
        }
        else{
            count++;
        }
    }
    return res;
}
TC: O(N)
SC :O(1)
