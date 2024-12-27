class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, vector<int>> hash;
        int n=s.length();
        int i=0;
        while(i<n){
            int temp=1;
            char c=s[i];
            while(i<n-1 && s[i]==s[i+1]){
                temp++;
                i++;
            }
            hash[c].push_back(temp);
            i++;
        }
        int res=-1;
        for(auto& i:hash){
            vector<int>& list=i.second;
            sort(list.rbegin(), list.rend());
            if(list[0]>=3)
                res=max(res,list[0]-2);
            
            if(list.size()>=2){
                if(list[0]>=2)
                    res=max(res,min(list[0]-1, list[1]));
                if(list.size()>=3)
                    res = max(res, min({list[0], list[1], list[2]}));
            }
        }
        return res;
    }
};
