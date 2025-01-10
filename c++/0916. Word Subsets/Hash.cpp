class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int hash[26]={0};    //letter, count
        int temp[26]={0}; 
        for(string& s:words2){   
            memset(temp, 0, sizeof temp);
            for(char& c:s){
                temp[c-'a']++;
            }
            for(int i=0;i<26;i++){
                hash[i]=max(hash[i],temp[i]);
            }
        }

        vector<string> res;
        for(string& s:words1){
            memset(temp, 0, sizeof temp);
            for(char& c:s){
                temp[c-'a']++;
            }
            bool valid=true;
            for(int i=0;i<26;i++){
                if(temp[i]<hash[i]){
                    valid=false;
                    break;
                }
            }
            if(valid)
                res.push_back(s);
        }
        return res;
    }
};
