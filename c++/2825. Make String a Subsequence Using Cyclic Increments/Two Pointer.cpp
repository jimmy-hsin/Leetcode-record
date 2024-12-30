class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(), m=str2.size();
        int i=0,j=0;
        while(i<n && j<m){
            int c1=str1[i]-'a', c2=str2[j]-'a';
            if(c1==c2 || (c1+1)%26==c2)
                i++, j++;
            else
                i++;
        }
        return j==m;
    }
};
