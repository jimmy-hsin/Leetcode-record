class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
      //按字串長度由小排到大
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size()<b.size();
        });
      
        int n=words.size();
        vector<string> res;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if (words[j].find(words[i]) != string::npos){  //npos是一個find找不到目標時回傳的常數
                    res.push_back(words[i]);
                    break;
                }
            }
        }
      
        return res;
    }
};
