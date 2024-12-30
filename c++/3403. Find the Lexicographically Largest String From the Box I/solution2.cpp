class Solution {
public:
    string answerString(string word, int numF) {
        if(numF==1)
            return word;
        int n=word.length();
        int maxL=n-(numF-1);
        char maxChar='a';
        for(char c:word)
            maxChar=max(maxChar,c);
        if(maxL==1)
            return string(1,maxChar);
        
        string res="";
        for(int i=0;i<n;i++){
            if(word[i]==maxChar){
                string sub=word.substr(i,maxL);
                res=max(res,sub);
            }
        }
        return res;
    }
};
