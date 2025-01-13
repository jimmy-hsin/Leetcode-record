class Solution {
public:
    int minimumLength(string s) {
        vector<int> count(26,0);
        for(char& c:s)
            count[c-'a']++;
        int sum=0;
        for(int& i:count){
            if(i>0)   
                sum+=(2-i%2);
        } 
        return sum;
    }
};
