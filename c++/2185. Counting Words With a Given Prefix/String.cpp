class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int lenP=pref.size();
        for(string& i:words){
            if(i.size()<lenP)   continue;
            if(i.substr(0,lenP)==pref)
                count++;
        }
        return count;
    }
};
