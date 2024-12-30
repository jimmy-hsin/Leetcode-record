class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.length();
        int j=0, m=spaces.size();
        string res="";
        for(int i=0;i<n;i++){
            if(j<m && i==spaces[j]){
                res+=' ';
                j++;
            }
            res+=s[i];
        }
        return res;
    }
};
