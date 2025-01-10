class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26,-1);
        vector<int> last(26,-1);
        for(int i=0;i<s.size();i++){
            int c=s[i]-'a';
            if(first[c]==-1)
                first[c]=i;
            last[c]=i;
        }
      
        int count=0;
        for(int i=0;i<26;i++){
            unordered_set<char> hash;
            if(first[i]!=-1){
                for(int j=first[i]+1;j<last[i];j++){
                    hash.insert(s[j]);
                }
            }
            count+=hash.size();
        }
        return count;
    }
};
