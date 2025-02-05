class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> fault;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i])
                fault.push_back(i);
            if(fault.size()>2)
                return false;
        }
        if(fault.size()==1)
            return false;
        if(fault.empty())
            return true;
        return (s1[fault[0]]==s2[fault[1]] && s1[fault[1]]==s2[fault[0]]);
    }
};
