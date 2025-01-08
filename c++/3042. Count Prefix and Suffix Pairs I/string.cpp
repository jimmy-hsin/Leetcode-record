class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                count+=isValid(words[i],words[j]);
            }
        }
        return count;
    }
    bool isValid(string str1, string str2){
        int len1=str1.size(), len2=str2.size();
        if(len1 > len2) return false;
        if(str2.substr(0, len1) != str1)
            return false;
        if(str2.substr(len2-len1, len1) != str1)
            return false;
        return true;
    }
};
