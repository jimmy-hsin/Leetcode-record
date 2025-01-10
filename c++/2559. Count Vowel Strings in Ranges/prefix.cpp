class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> prefix(n,0);
      
        prefix[0]=isValid(words[0]);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1];
            prefix[i]+=isValid(words[i]);
        }
      
        vector<int> res;
        for(auto& i:queries){
            int front= (i[0]==0)? 0: prefix[ i[0]-1 ];  //第一個數是不是0，如果不是的話，前面的valid個數為 prefix[i[0]-1](前一個prefix)，若為0，前面的valid個數為0;
            res.push_back(prefix[i[1]]-front);
        }
        return res;
    }

    bool isValid(string& s){
        if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u'){
            if(s.back()=='a' || s.back()=='e' || s.back()=='i' || s.back()=='o' || s.back()=='u')
                return true;
        }
        return false;
    }
};
