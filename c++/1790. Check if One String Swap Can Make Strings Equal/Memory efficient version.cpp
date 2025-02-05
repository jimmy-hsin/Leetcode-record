class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int idx[2], fault=0;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(fault==2)    return false;
                idx[fault++]=i;
            }
        }
        if(fault==0)
            return true;
        if(fault==1)
            return false;
        return (s1[idx[0]]==s2[idx[1]] && s1[idx[1]]==s2[idx[0]]);
    }
};
