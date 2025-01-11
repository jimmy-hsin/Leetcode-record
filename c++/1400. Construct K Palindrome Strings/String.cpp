class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)  return false;
        vector<int> count(26,0);
        for(char c:s){
            count[c-'a']++;
        }
        int odd=0;
        for(int i:count){
            odd+=(i%2);
        }
        return odd<=k;
    }
};
