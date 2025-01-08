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
        for(int i=0;i<len1;i++){
            if(str1[i]!=str2[i] || str1[len1-1-i] != str2[len2-1-i])
                return false;
        }
        return true;
    }
};
