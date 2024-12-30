class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1)
            return word;
        int n=word.length();
        int maxL=n-numFriends+1;
        char maxChar='a';
        for(char c:word){
            maxChar=max(maxChar,c);
        }
        if(n==numFriends){
            string s;
            s+=maxChar;
            return s;
        }
        string res="";   
        vector<string> temp;
        for(int i=0;i<n;i++){
            if(word[i]==maxChar){
                string sub= word.substr(i, maxL);
                if(customCompare(sub,res))
                    res=sub;
            }
        }
        
        return res; 
    }
    bool customCompare(const string& a, const string& b) {
        int lenA = a.length();
        int lenB = b.length();
        int minLen = min(lenA, lenB);
    
        // 按字典序逐字符比較
        for (int i = 0; i < minLen; ++i) {
            if (a[i] != b[i]) {
                return a[i] > b[i]; // 字母較大的勝出
            }
        }
    
        // 如果所有字符都相同，則比較長度
        return lenA > lenB; // 較長的勝出
    }
};
